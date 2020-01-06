#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int findf(int a,vector<int>& parent) {
	if (parent[a] == a)return a;
	else {
		int f = findf(parent[a], parent);
		parent[a] = f;
		return f;
	}
}
void unionf(int a, int b, vector<int>& parent) {
	int first = findf(a, parent);
	int second = findf(b, parent);
	if (first == second) return;
	else {
		parent[second] = first;
		return;
	}
}



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;
	vector<int> parent(N + 1, 0);
	int ans = N;
	for (int i = 1; i <= N; i++) parent[i] = i;
	for (int i = 0; i < M; i++) {
		int first, second;
		cin >> first >> second;
		if (findf(first, parent) != findf(second, parent)) {
			unionf(first, second,parent);
			ans--;
		}
	}
	cout << ans;

	



	return 0;
}