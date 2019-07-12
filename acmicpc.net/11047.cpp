#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;



int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, K, tmp;
	cin >> N >> K;
	vector<int> table(N, 0);
	
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		table[i] = tmp;
	}
	int index = N - 1;
	int cnt = 0;
	while (K != 0) {
		if (table[index] <= K) {
			K -= table[index];
			cnt++;
		}
		else index--;
	}
	cout << cnt << '\n';

	return 0;
}