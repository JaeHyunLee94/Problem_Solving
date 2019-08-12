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



	int n, m;
	cin >> n>>m;
	vector<int> num(n);
	vector<int> dum(n);
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		num[i] = tmp;
		if (i>0)dum[i] = dum[i - 1] + num[i];
		else dum[i] = num[0];
	}
	

	for (int k = 0;k < m; k++) {
		int i, j;
		cin >> i >> j;
		if (i == 1) cout << dum[j - 1] << '\n';
		else cout << dum[j - 1] - dum[i - 2] << '\n';
	}


	return 0;
}