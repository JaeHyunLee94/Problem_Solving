#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INf= 1987654321;

struct edge {
	int from;
	int to;
	int w;

};


int main() {


	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	int test_case;
	cin >> test_case;
	for (int t = 1; t <= test_case; t++) {
		int V, E, W;
		cin >> V >> E >> W;
		vector<edge> EE(2*E+W);
		vector<int> dis(V + 1, INf);
	
		
		
		for (int i = 0; i < 2*E; i+=2) {
			int from, to, w;
			cin >> from >> to >> w;
			
			EE[i] = edge{ from,to,w };
			EE[i + 1] = edge{ to,from,w };
		}
		for (int i = 2*E; i <2*E+W; i++) {
			int from, to, t;
			cin >> from >> to >> t;
			
			EE[i] = edge{ from,to,-t };
		}
		int is_neg_cycle = 0;
		dis[1] = 0;

		for (int v = 0; v < V ; v++) {

			for (auto& n : EE) {
				if (dis[n.from] != INf && dis[n.from] + n.w < dis[n.to]) {
					if (v == V - 1) {
						is_neg_cycle = 1;
					}
					dis[n.to] = n.w + dis[n.from];
				}
			}


		}
		
		
	
		cout << (is_neg_cycle ? "YES" : "NO") << '\n';



	}

	return 0;
}