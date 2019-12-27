#include <iostream>
#include <algorithm>
#include <vector>



using namespace std;


int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	vector<int> arr(n, 0);
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		arr[i] = tmp;
	}

	vector<int> ans(n, 0);
	ans[0] = arr[0];
	int max_num = arr[0];

	for (int i = 1; i < n; i++) {
		ans[i] = (ans[i - 1] > 0) ? ans[i - 1] + arr[i] : arr[i];
		if (ans[i] > max_num) max_num = ans[i];
	}

	cout << max_num;














	return 0;
}