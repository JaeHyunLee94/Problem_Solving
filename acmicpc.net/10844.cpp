#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;


int find_ans(int N, int i,vector<vector<int>>& ans) {
	if (ans[N][i] != -1) return ans[N][i];



	if (i == 0) ans[N][i] = find_ans(N - 1, i + 1, ans) % 1000000000;
	else if (i == 9) ans[N][i] = find_ans(N - 1, i - 1, ans) % 1000000000;
	else ans[N][i] = (find_ans(N - 1, i - 1, ans) % 1000000000 + find_ans(N - 1, i + 1, ans) % 1000000000) % 1000000000;

	return ans[N][i];
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);


	int N;
	cin >> N;
	vector<vector<int>> ans(N + 1, vector<int>(10, -1));
	
	ans[1][0] = 0;
	for (int i = 1; i < 10; i++) {
		ans[1][i] = 1;
	}

	int sum = 0;
	for (int i = 0; i < 10; i++) {
		sum=(sum % 1000000000+find_ans(N,i,ans) % 1000000000) % 1000000000;
	}

	cout << sum;




	return 0;
}