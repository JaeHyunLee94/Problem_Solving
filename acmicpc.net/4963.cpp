#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

void dfs_island(vector<vector<int>>& island,int here_x,int here_y) {

	island[here_y][here_x] = 2;

	for (int i = here_y - 1; i <= here_y + 1; i++) {
		for (int j = here_x - 1; j <= here_x + 1; j++) {

			if (i == here_y && j == here_x) continue;
			else if (i >= 0 && i < island.size() && j >= 0 && j < island[0].size() && island[i][j] == 1) dfs_island(island, j, i);


		}
	}



}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int w, h;
	cin >> w >> h;

	
	while(!(w==0 && h==0)) {

		
		
		vector<vector<int>> island(h, vector<int>(w, 0));

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				int tmp;
				cin >> tmp;
				island[i][j] = tmp;
			}
		}
		int cnt = 0;

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (island[i][j] == 1) {
					dfs_island(island, j, i);
					cnt++;
				}
			}
		}

		cout << cnt << '\n';


		cin >> w >> h;

	}




	return 0;
}