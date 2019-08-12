#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <string>
using namespace std;

long long gcd(long long a, long long b) {
	if (a < b) swap(a, b);
	if (a % b == 0) return b;
	while (b != 0) {
		long long tmp = a;
		a = b;
		b = tmp % b;
	}
	return a;
}


int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long n, m, tmp;
	long long ans = 1;
	cin >> n;

	vector<long long> first_num(n);
	
	vector<long long> gcd_num;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		first_num[i] = tmp;
	}
	cin >> m;
	vector<long long> second_num(m);
	for (long long j = 0; j < m; j++) {
		cin >> tmp;
		second_num[j] = tmp;
	}


	for (int i = 0; i < n;i++) {
		for (int j = 0; j < m;j++) {
			long long ggccdd = gcd(first_num[i], second_num[j]);
			if (ggccdd == 1)continue;
			gcd_num.push_back(ggccdd);
			first_num[i] = first_num[i] / ggccdd;
			second_num[j] = second_num[j] / ggccdd;


		}
	}

	for (auto& n : gcd_num) {

		ans *= n;
		if (ans >= 10000000000) ans = ans % 10000000000;


	}
	
	string ans_t = to_string(ans);
	if (ans_t.size() <= 9) cout << ans_t;
	else for (int i = 0; i < 9; i++)  cout << ans_t[ans_t.size() - 9 + i];

	return 0;
}