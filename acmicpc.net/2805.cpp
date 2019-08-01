#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;



int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	long long  N, M, tmp;
	long long ans = 0;
	cin >> N >> M;

	vector<long long> arr(N);
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		arr[i] = tmp;
	}

	sort(arr.begin(), arr.end());

	long long low = 0;
	long long high = arr[N - 1];
	

	while (low<=high) {
		long long mid = (low + high) / 2;
		long long sum = 0;
		for (auto& n : arr) {
			if (mid < n) sum += n - mid;
		}

		if (sum < M) {
			high = mid - 1;
		}
		else {
			ans = mid;
			low = mid + 1;
		}
		





	}

	cout << ans;

	system("pause");


	return 0;
}