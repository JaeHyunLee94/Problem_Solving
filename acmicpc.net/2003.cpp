#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;



int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	int N, M;
	int tmp;
	
	int ans = 0;
	cin >> N >> M;

	vector<int> arr(N);

	for (int i = 0; i < N; i++) {
		cin >> tmp;
		arr[i] = tmp;
	}


	for (int len = 1; len <= N; len++) {
		int sum = 0;
		int start = 0, end = start + len;
		for (int i = 0; i < len; i++) {
			sum += arr[i];
		}

		while(end != N) {
			if (sum == M) ans++;
			sum -= arr[start];
			sum += arr[end];

			start++;
			end++;

		}
		if(sum==M) ans++;
		

	}

	cout << ans;

	system("pause");










	return 0;
}