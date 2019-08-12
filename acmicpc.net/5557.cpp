#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>




using namespace std;




int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	long long n;
	cin >> n;
	vector<int> arr(n-1);
	vector<vector<long long>> num(n, vector<long long>(21, 0));



	for (int i = 0; i < n-1; i++) {
		int tmp;
		cin >> tmp;
		arr[i] = tmp;
	}
	int ans;
	cin >> ans;
	num[0][arr[0]] = 1;
	for (int i = 1; i < n-1; i++) {
		for (int j = 0; j < 21;j++) {
			if (num[i-1][j]) {
				if (j + arr[i] <= 20) num[i][j + arr[i]] += num[i - 1][j] ;
				if (j - arr[i] >= 0)  num[i][j - arr[i]]+= num[i - 1][j] ;
			}
		}

	}

	cout << num[n-2][ans];



	return 0;
}