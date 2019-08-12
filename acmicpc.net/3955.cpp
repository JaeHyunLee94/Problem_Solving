#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

long long gcd(long long a, long long b)
{
	if (a < b) swap(a, b);
	if (a % b == 0) return b;
	return b ? gcd(b, a % b) : a;
}

pair<int, int> extended_euclid(long long K, long long C) {

	long long s1, s0;
	long long t1, t0;
	long long q, r0, r1;

	s0 = 1, s1 = 0, t1 = 1, t0 = 0;
	r0 = K, r1 = C;
	q = K / C;
	

	while (r0-r1*q != 0) {
		long long s2 = s0 - s1 * q;
		long long t2 = t0 - t1 * q;
		long long r2 = r0 - r1 * q;
		q = r1 / r2;
		s0 = s1;
		t0 = t1;
		s1 = s2;
		t1 = t2;
		r0 = r1;
		r1 = r2;

	}

	return make_pair(s1, t1);


}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int test_case;
	

	cin >> test_case;

	for (int t = 1; t <= test_case; t++) {

		long long K, C;
		cin >> K >> C;

		long long gcdd = gcd(K, C);
		if (gcdd != 1) cout << "IMPOSSIBLE" << '\n';
		else {
			pair<int, int> ans = extended_euclid(K, C);
			
			if (ans.second <= 0 || ans.first>=0) {
				while (ans.second <= 0 || ans.first >= 0)
				{
					ans.second += K;
					ans.first -= K;
				}

			}
			else if (ans.second > 1000000000) {
				while (ans.second > 1000000000 && ans.first<0) {
					ans.second -= K;
					ans.first += K;
				}
			}
			if (ans.second > 0 && ans.second <= 1000000000 && ans.first<0) cout << ans.second << '\n';
			else cout << "IMPOSSIBLE" << '\n';
		}
		
		

		



	}
	

	return 0;
}
