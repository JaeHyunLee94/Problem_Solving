#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <functional>


using namespace std;
struct edge {
	pair<int, int> start;
	pair<int, int> end;
	int w;

};
bool check_g(const vector<pair<int, int>>& gg, pair<int, int> v) {

	auto m = find(gg.begin(), gg.end(), v);

	return (m == gg.end());


}
int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int W, H, G, E;

	cin >> W >> H;
	while (!(W == 0 && H == 0)) {

		int is_cycle = 0;
		cin >> G;
		vector<vector<int>> dis(H, vector<int>(W, 987654321));
		vector<edge> edg_list;
		vector<pair<int, int>> gg(G);
		
		dis[0][0] = 0;


		for (int i = 0; i < G; i++) {
			int x, y;
			cin >> x >> y;
			gg[i] = make_pair(x, y);
		}
		cin >> E;
		vector<pair<int, int>> ee(E);
		for (int i = 0; i < E; i++) {
			int x1, y1, x2, y2, w;
			cin >> x1 >> y1 >> x2 >> y2 >> w;
			ee[i] = make_pair(x1, y1);
			edg_list.push_back(edge{ make_pair(x1,y1),make_pair(x2,y2) ,w });
		}

		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				pair<int, int> now(j, i);
				if (!check_g(ee, now)||!check_g(gg, now)||(i==H-1 && j==W-1)) continue;

				if (j + 1 < W && check_g(gg, make_pair(j + 1, i))) edg_list.push_back(edge{ now,make_pair(j + 1, i) ,1 });
				if (j - 1 >= 0 && check_g(gg, make_pair(j - 1, i))) edg_list.push_back(edge{ now,make_pair(j - 1, i) ,1 });
				if (i + 1 < H && check_g(gg, make_pair(j, i + 1))) edg_list.push_back(edge{ now,make_pair(j , i + 1) ,1 });
				if (i - 1 >= 0 && check_g(gg, make_pair(j, i - 1))) edg_list.push_back(edge{ now,make_pair(j, i - 1) ,1 });



			}
		}

		

		for (int i = 1; i < W*H - G; i++) {
			for (auto& n : edg_list) {
				if (dis[n.start.second][n.start.first] != 987654321 && dis[n.start.second][n.start.first] + n.w < dis[n.end.second][n.end.first]) {
					dis[n.end.second][n.end.first] = dis[n.start.second][n.start.first] + n.w;
				}
			}
		}

		vector<vector<int>> check(dis);
		for (auto& n : edg_list) {
			if (check[n.start.second][n.start.first] != 987654321 && check[n.start.second][n.start.first] + n.w < check[n.end.second][n.end.first]) {
				is_cycle = 1;
			}
			if (is_cycle) break;
		}


		if (is_cycle) cout << "Never" << '\n';
		else if (dis[H - 1][W - 1] == 987654321) cout << "Impossible" << '\n';
		else cout << dis[H - 1][W - 1] << '\n';



		cin >> W >> H;


	}





	return 0;
}