#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

unsigned long long gcd(unsigned long long a, unsigned long long b) {
	if (a < b) swap(a, b);
	if (a % b == 0) return b;
	while (b != 0) {
		unsigned long long tmp = a;
		a = b;
		b = tmp % b;
	}
	return a;
}

void yakbun(unsigned long long& a, unsigned long long& b) {
	unsigned long long gcdd = gcd(a, b);
	a /= gcdd;
	b /= gcdd;
}

int main() {

	

	vector<vector<unsigned long long>> dp(51, vector<unsigned long long>(51, 0));
	for (unsigned long long i = 0; i <= 50; i++) {
		dp[i][i] = 1;
		dp[i][0] = 1;
	}
	for (unsigned long long i = 2; i <= 50; i++) {
		for (unsigned long long j = 1; j < i; j++) {
			dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
		}
	}
	unsigned long long n, total = 0;
	cin >> n;
	vector<unsigned long long> arr(n);
	for (unsigned long long i = 0; i < n; i++) {
		unsigned long long tmp;
		cin >> tmp;
		total+=(arr[i] = tmp);
		
	}


	unsigned long long k;
	cin >> k;

	unsigned long long numerator = 0;
	for (unsigned long long i = 0; i < n; i++) {
		if (k <= arr[i]) numerator += dp[arr[i]][k];
	}
	if (numerator == 0) {
		cout << 0;
		return 0;
	}
	vector<unsigned long long> denom1(k);
	vector<unsigned long long> denom2(k);
	for (unsigned long long t = 0; t < k; t++) {
		denom1[t] = total - t;
		denom2[t] =t+1;
	}

	for (unsigned long long i = 0; i < k; i++) {
		for (unsigned long long j = 0; j < k; j++) {
			yakbun(denom1[i], denom2[j]);
		}
	}
	for (unsigned long long i = 0; i < k; i++) {
		yakbun(numerator, denom1[i]);
	}
	double ans = (double)numerator;
	for (unsigned long long i = 0; i < k; i++) {
		ans /= denom1[i];
	}

	printf("%.11lf", ans);



	return 0;
}