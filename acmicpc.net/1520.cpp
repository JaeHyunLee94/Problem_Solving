#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;


int end_x, end_y;


int way_down(int x, int y, const vector<vector<int>>& matrix,vector<vector<int>>& DP) {

	

	if (DP[y][x] != -1) return DP[y][x];

	if (y == 0 && x == 0) return DP[y][x] = 1;

	int& ret = DP[y][x];
	ret = 0;
	

	if (x - 1 >= 0 && matrix[y][x - 1] > matrix[y][x]) ret += way_down(x - 1, y, matrix, DP);
	if (y - 1 >= 0 && matrix[y - 1][x] > matrix[y][x]) ret += way_down(x, y-1, matrix, DP);
	if (x + 1 <= end_x && matrix[y][x + 1] > matrix[y][x]) ret += way_down(x +1, y, matrix, DP);
	if (y + 1 <= end_y && matrix[y+1][x] > matrix[y][x]) ret += way_down(x, y+1, matrix, DP);
	
	return ret;



}




int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int M, N;
	cin >> M >> N;
	end_x = N - 1;
	end_y = M- 1;

	vector<vector<int>> matrix(M, vector<int>(N, 0));
	vector<vector<int>> DP(M, vector<int>(N, -1));
	DP[0][0] = 1;
	
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			int tmp;
			cin >> tmp;
			matrix[i][j] = tmp;
		}
	}
	
	cout << way_down(end_x, end_y, matrix,DP);





	return 0;
}