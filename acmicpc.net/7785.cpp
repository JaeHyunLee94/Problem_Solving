#include <iostream>
#include <vector>
#include <algorithm>




using namespace std;


int main() {



	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	
	int n, tmp;
	cin >> n;
	vector<int> stair(n);
	vector<int> max_score(n);
	
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		stair[i] = tmp;
	}

	max_score[0] = stair[0];
	max_score[1] = stair[0]+stair[1];
	max_score[2] = max(stair[0] + stair[2], stair[1] + stair[2]);


	for (int i = 3; i < n; i++) {
		max_score[i] = max(stair[i - 1]+max_score[i-3]+stair[i], max_score[i - 2]+stair[i]);
	}
	
	cout << max_score.back();


	return 0;
}