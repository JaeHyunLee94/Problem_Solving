#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>

using namespace std;

int gcd(int a, int b) {
	if (a < b) swap(a, b);
	if (a%b == 0) return b;
	while (b !=0) {
		int tmp = a;
		a = b;
		b = tmp % b;
	}
	return a;
}



int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int test_case;
	int n;
	cin >> test_case;
	vector<int> ans(1001, -1);
	ans[1] = 1;

	for (int i = 2; i <= 1000; i++) {
		int cnt = 0;
		for (int j = 1; j < i; j++) {
			if (gcd(i, j) == 1) cnt++;
		}
		ans[i] = ans[i - 1] + cnt;
	}

	for (int t = 1; t <= test_case; t++) {
		cin >> n;
		cout << ans[n]*2+1 << '\n';
	

	}
	

	return 0;
}