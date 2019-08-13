#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int findf(int a, vector<int>& parent) {

	if (parent[a] == a) return a;
	else {
		
		int p = findf(parent[a], parent);
		parent[a] = p;
		return p;
	}


}

void unionf(int a, int b, vector<int>& parent) {
	int p1 = findf(a,parent);
	int p2 = findf(b, parent);

	if (p1 == p2) return;
	else parent[p2] = p1;
}



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;
	vector<int> parent(N+1,0);
	for (int i = 1; i <= N; i++)parent[i] = i;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			int tmp;
			cin >> tmp;
			if (tmp) unionf(i, j, parent);
		}
	}
	int to_travle;
	int can_travle = 1;
	if (!M) {
		cout << "YES" << '\n';
		return 0;
	}
	cin >> to_travle;
	int prt = findf(to_travle, parent);
	for (int i = 1; i < M; i++) {
		

		cin >> to_travle;
		if (findf(to_travle, parent) != prt) {
			can_travle = 0;
			break;
		}
		
	}
	cout << (can_travle ? "YES" : "NO") << '\n';

	


	return 0;
}