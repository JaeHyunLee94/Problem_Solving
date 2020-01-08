#include <iostream>
#include <vector>
#include <algorithm>



using namespace std;


int ans = 0;
int N = 0;


int is_possible(vector<vector<int>>& grid, int row, int column) {
	

	for (int i = 0; i < row; i++) {
		if (grid[i][column]) return 0;
	}

	int i = 0, j = 0;

	while (row + i >= 0 && column + j < N) { //©Л╩С
		if (grid[row + i][column + j]) return 0;
		i--;
		j++;

	}
	i = 0; j = 0;
	while (row + i >= 0 && column + j >= 0) { //аб╩С	
		if (grid[row + i][column + j]) return 0;
		i--;
		j--;
	}

	return 1;
}


void find_Nqueen(vector<vector<int>>& grid,int row_now) {

	
	if (row_now == N) {
		ans++;
		return;
	}

	for (int i = 0; i < N; i++) {
		
		if (is_possible(grid, row_now, i)) {
			grid[row_now][i] = 1;
			find_Nqueen(grid, row_now + 1);
			grid[row_now][i] = 0;

		}	
		
	}
	return;


}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	vector<vector<int>> grid(N, vector<int>(N, 0));
	find_Nqueen(grid,0);
	cout << ans;


	return 0;
}