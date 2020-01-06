#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int start_x, start_y, N;

const int dx[8] = { 1,1,0,-1,-1,-1,0,1 };
const int dy[8] = { 0,-1,-1,-1,0,1,1,1 };

void upperorlower_bound(int upordown,int max_or_min, vector<vector<char>>& mat, vector<vector<int>>& altitude,vector<vector<int>>& is_visit,int i,int j) {
	
	is_visit[i][j] = 1;
	
	for (int k = 0; k < 8; k++) {
		int xx = j + dx[k];
		int yy = i + dy[k];
		if (xx >= 0 && xx < N && yy >= 0 && yy < N && !is_visit[yy][xx] ) {
			if (upordown && altitude[yy][xx] <=max_or_min) {
				upperorlower_bound(upordown, max_or_min, mat, altitude, is_visit, yy, xx,end_y,end_x);
			}
			else if (!upordown && altitude[yy][xx] >= max_or_min) {
				upperorlower_bound(upordown, max_or_min, mat, altitude, is_visit, yy, xx,end_y,end_x);
			}
			
		}
	}
	


}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	
	cin >> N;
	vector<vector<char>> mat(N, vector<char>(N, 0));
	vector<vector<int>> altitude(N, vector<int>(N, 0));
	vector<pair<int, int>> k_list;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			char tmp;
			cin >> tmp;
			if (tmp == 'P') {
				start_y = i;
				start_x = j;
			}
			else if (tmp == 'K') {
				k_list.push_back(make_pair(i, j));
			}
			mat[i][j] = tmp;

		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int tmp;
			cin >> tmp;
			altitude[i][j] = tmp;

		}
	}

	int low = 0;
	int high = 1000000;
	int mid = (low + high) / 2;
	int ans_up = 0;
	int ans_down = 0;
	while (low < high) {

		mid = (low + high) / 2;
		vector<vector<int>> is_visit(N, vector<int>(N, 0));
		upperorlower_bound(1, mid, mat, altitude, is_visit, start_y, start_x);
		int is_up_or_down = 1;
		for (auto& n : k_list) {
			if (!is_visit[n.first][n.second]) {
				is_up_or_down = 0;
				break;

			}
		}
		if (is_up_or_down) {
			high = mid;
		}
		else {
			low = mid;
		}

		
	}
	ans_up = mid;
	low = 0;
	high= 1000000;
	mid = (low + high) / 2;
	while (low < high) {

		mid = (low + high) / 2;
		vector<vector<int>> is_visit(N, vector<int>(N, 0));
		upperorlower_bound(0, mid, mat, altitude, is_visit, start_y, start_x);
		int is_up_or_down = 1;
		for (auto& n : k_list) {
			if (!is_visit[n.first][n.second]) {
				is_up_or_down = 0;
				break;

			}
		}
		if (is_up_or_down) {
			low = mid;
		}
		else {
			high = mid;
		}


	}




	return 0;
}