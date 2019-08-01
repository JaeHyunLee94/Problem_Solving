#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);



	long long N = 0, ans = 0;
	cin >> N;

	vector<long long> A(N);
	vector<long long> B(N);
	vector<long long> C(N);
	vector<long long> D(N);
	for (long long i = 0; i < N; i++) {
		long long a, b, c, d;
		cin >> a >> b >> c >> d;
		A[i] = a;
		B[i] = b;
		C[i] = c;
		D[i] = d;
	}

	vector<long long> AB(N*N);
	vector<long long> CD(N*N);
	long long ab_inx = 0, cd_inx = 0;
	for (long long i = 0; i < N; i++) {
		for (long long j = 0; j < N; j++) {
			AB[ab_inx++] = A[i] + B[j];
			CD[cd_inx++] = C[i] + D[j];

		}
	}
	sort(AB.begin(), AB.end());
	sort(CD.begin(), CD.end());

	for (long long i = 0; i < AB.size(); i++) {
		long long sum = -AB[i];
		long long cnt = upper_bound(CD.begin(), CD.end(), sum)- lower_bound(CD.begin(), CD.end(), sum);
		ans += cnt;

	}

	cout << ans;

	system("pause");
	return 0;
}