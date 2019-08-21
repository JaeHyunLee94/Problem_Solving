#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>


using namespace std;

const int dx[4] = { 0,0,-1,1 };
const int dy[4] = { 1,-1,0,0 };


void check_update(vector<vector<char>>& mat) {

	for (int i = 0; i < 6; i++) {
		vector<char> ::iterator iter = mat[i].begin();
		while (iter != mat[i].end()) {
			if (*iter == '.') {
				iter = mat[i].erase(iter);
			}
			else iter++;

		}
		while (mat[i].size() != 12) mat[i].push_back('.');
	}


}

void chain(const vector<vector<char>>& mat, stack<pair<int, int>>& st, int start_y, int start_x,char color,vector<vector<int>>& is_visit) {

	if (mat[start_y][start_x] != color) return;
	is_visit[start_y][start_x] = 1;
	
	st.push(make_pair(start_y, start_x));
	for (int i = 0; i < 4; i++) {
		int xx = start_x + dx[i];
		int yy = start_y + dy[i];

		if (xx >= 0 && xx < 12 && yy >= 0 && yy < 6 &&!is_visit[yy][xx] &&mat[yy][xx] == color ) chain(mat, st, yy, xx, color,is_visit);
	}



}




int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	vector<vector<char>> mat(6, vector<char>(12, '.'));

	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 6; j++) {
			char tmp;
			cin >> tmp;
			mat[j][11-i] = tmp;
		}
	}

	int score = 0;
	int is_change = 1;
	stack<pair<int, int>> to_erase;
	while (is_change){
		is_change = 0;
		
		for (int i = 0; i < 6; i++) {
			for (int j = 0; j < 12; j++) {
				if (mat[i][j] == '.') continue;

				vector<vector<int>> is_visit(6, vector<int>(12, 0));

				chain(mat, to_erase, i, j, mat[i][j],is_visit);

				if (to_erase.size() < 4) {
					while (!to_erase.empty()) to_erase.pop();
					
				}
				else {
					is_change = 1;
					while (!to_erase.empty()) {
						pair<int, int> next = to_erase.top();
						to_erase.pop();
						mat[next.first][next.second] = '.';
					}
				}

			}
		}
		check_update(mat);
		if (is_change) score += 1;


	}



	cout << score;









	return 0;
}