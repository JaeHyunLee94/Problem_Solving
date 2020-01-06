#include <iostream>
#include <vector>

using namespace std;

int ans(int i, vector<int>& DP) {
	if (DP[i] != -1) return DP[i];
	int& ret = DP[i];
	if (i == 1)return ret = 1;
	if (i == 2) return ret = 3;
	return ret = (ans(i - 1, DP) % 10007 + 2*ans(i - 2, DP) % 10007) % 10007;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	vector<int> DP(n + 1, -1);
	cout << ans(n, DP) % 10007;
	


	return 0;
}