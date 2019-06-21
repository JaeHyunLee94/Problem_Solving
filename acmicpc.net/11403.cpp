#include <iostream>
#include <algorithm>
#include <vector>





using namespace std;


int main() {
	
	int ver = 0;
	int tmp = 0;
	cin >> ver;
	vector<vector<int>> adj(ver);
	for (int i = 0; i < ver; i++) {
		for (int j = 0; j < ver; j++) {
			scanf_s("%d", & tmp);
			adj[i].push_back(tmp);
		}
	}

	for (int k = 0; k <ver; k++) {
		for (int i = 0; i < ver; i++) {
			for (int j = 0; j < ver; j++) {
				if ((adj[i][j]||adj[i][k] && adj[k][j])) adj[i][j] = 1;

			}
		}
	}

	for (int i = 0; i < ver; i++) {
		for (int j = 0; j < ver; j++) {
			printf_s("%d ", adj[i][j]);
			
		}
		printf_s("\n");
	}






	return 0;
}