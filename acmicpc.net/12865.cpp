#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;


struct stuff {
	int w;
	int v;
};

int N, K;

int maximum_val(int n, int w, vector<vector<int>>& DP,const vector<stuff>& table) {

	if (DP[n][w] != -1) return DP[n][w];
	
	int& ret = DP[n][w];
	if (table[n].w > w)  return ret = maximum_val(n - 1, w, DP, table);

	return ret = max(maximum_val(n - 1, w - table[n].w, DP, table)+table[n].v, maximum_val(n - 1, w, DP, table));

}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	
	cin >> N >> K;
	vector<stuff> arr_stuff(N, stuff{ 0,0 });
	vector<vector<int>> DP(N, vector<int>(K+1,-1));

	for (int i = 0; i < N; i++) {
		int W, V;
		cin >> W >> V;
		arr_stuff[i] = stuff{ W,V };
	}

	for (int k = 0; k <= K; k++) {
		if (k < arr_stuff[0].w) DP[0][k] = 0;
		else DP[0][k] = arr_stuff[0].v;
	}

	
	
	cout << maximum_val(N - 1, K, DP, arr_stuff);
	



	return 0;
}