#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int INF = 9999999;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);


	int V, E;

	cin >> V >> E;
	vector<vector<int>> mat(V + 1, vector<int>(V + 1, INF));
	for (int i = 1; i < V + 1; i++) {
		mat[i][i] = 0;
	}

	for (int i = 0; i < E; i++) {
		int from, to;
		cin >> from >> to;
		mat[from][to] = 1;
		mat[to][from] = 1;

	}
	//auto mat2 = mat;

	for (int k = 1; k < V+1; k++) {
		for (int i = 1; i < V + 1; i++) {
			for (int j = 1; j < V + 1; j++) {
				mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
			}
		}
		
	}


	int index = 0;
	int kevin = INF;

	for (int i = 1; i <V+1; i++) {
		int sum = accumulate(mat[i].begin()+1, mat[i].end(), 0);
		if (sum < kevin) {
			index = i;
			kevin = sum;

		}


	}
	cout << index;



	return 0;
}