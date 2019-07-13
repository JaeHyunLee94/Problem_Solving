#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;



void dfs_here(vector<vector<int>>& map,int y, int x, int& cnt) {
	int n = map.size();
	map[y][x] = 2;
	cnt++;
	if (x + 1 < n && map[y][x + 1] == 1) dfs_here(map, y, x + 1, cnt);
	if (x-1 >= 0&& map[y][x - 1] == 1) dfs_here(map, y, x - 1, cnt);
	if (y - 1 >= 0 && map[y-1][x] == 1) dfs_here(map, y-1, x , cnt);
	if (y + 1 < n && map[y+1][x] == 1) dfs_here(map, y+1, x, cnt);
	

}




int main() {



	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;
	char tmp;
	vector<vector<int>> map(N, vector<int>(N, 0));
	vector<int> num;
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> tmp;
			map[i][j] = tmp-'0';
		}
	}



	int cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] == 1) {
				dfs_here(map, i, j, cnt);
				num.push_back(cnt);
				cnt = 0;
			}
		}
	}

	sort(num.begin(), num.end());
	cout << num.size() << '\n';
	for (auto& n : num) cout << n << '\n';






	return 0;
}