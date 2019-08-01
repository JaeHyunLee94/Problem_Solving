#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long T, m, n;
	long long tmp;
	long long ans = 0;
	cin >> T;

	cin >> n;
	vector<long long> A(n);
	vector<long long> AA((n*(n+1))/2);
	for (long long i = 0; i < n; i++) {
		cin >> tmp;
		A[i] = tmp;
	}
	long long a_index = 0;
	for (long long i = 0; i < n; i++) {
		long long sum = A[i];
		AA[a_index++] = sum;
		for (long long j = i+1; j < n; j++) {
			sum += A[j];
			AA[a_index++] = sum;
		}
	}

	cin >> m;
	vector<long long> B(m);
	vector<long long> BB((m*(m+1))/2);
	for (long long i = 0; i < m; i++) {
		cin >> tmp;
		B[i] = tmp;
	}

	long long b_index = 0;
	for (long long i = 0; i < m; i++) {
		long long sum = B[i];
		BB[b_index++] = sum;
		for (long long j = i + 1; j < m; j++) {
			sum += B[j];
			BB[b_index++] = sum;
		}
	}
	sort(AA.begin(), AA.end());
	sort(BB.begin(), BB.end());

	for (auto& n : AA) {
		ans += upper_bound(BB.begin(), BB.end(), T-n) - lower_bound(BB.begin(), BB.end(),T-n);
	}

	cout << ans;





	system("pause");





	return 0;
}