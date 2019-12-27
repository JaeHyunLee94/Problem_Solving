#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>



using namespace std;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

struct tomato
{
	int x;
	int y;
	int day;
};

int tomato_day(vector<vector<int>>& mat,vector<pair<int,int>>& source) {

	if (source.size() == 0) return 0;
	int M = mat.size();
	int N = mat[0].size();

	queue<tomato> q;
	for (auto& n : source) q.push(tomato{n.second,n.first,0});
	int day = 0;

	while (!q.empty()) {
		auto next = q.front();
		q.pop();
		if (next.day > day) day = next.day;
		for (int i = 0; i < 4; i++) {
			if (next.x + dx[i] >= 0 && next.x + dx[i] < N && next.y + dy[i]>=0 && next.y + dy[i] < M&&mat[next.y+dy[i]][next.x+dx[i]]==0) {
				mat[next.y + dy[i]][next.x + dx[i]] = 1;
				q.push(tomato{ next.x + dx[i], next.y + dy[i],next.day + 1 });

			}
		}
	}

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (mat[i][j] == 0) return -1;
			
		}
	}

	return day;



}


int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int M, N;

	cin >> N >> M;
	vector<vector<int>> mat(M, vector<int>(N, 0));
	vector<pair<int,int>> source;

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			int tmp;
			cin >> tmp;
			mat[i][j] = tmp;
			if (tmp == 1) source.push_back(pair<int,int>(i,j));
		}
	}


	cout << tomato_day(mat, source);








	return 0;
}