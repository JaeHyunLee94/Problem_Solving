#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, H;
	cin >> N;
	H = (N % 2 == 1 ? N / 2 : N / 2 - 1);
	vector<vector<int>> DP(N, vector<int>(H + 1, 0));
	vector<int> table(N);

	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		table[i] = tmp;
		if (tmp > H) {
			cout << 0;
			return 0;
		}
		
	}
	if (table[0] > 0 || table[N - 1] > 0) {
		cout << 0;
		return 0;
	}


	table[0] = 0;
	table[N-1] = 0;
	DP[0][0] = 1;
	
	for (int i = 0; i < N - 1; i++) {
		if (table[i] != -1) {
			int now_h = table[i];
			if(now_h+1<=H)	DP[i + 1][now_h + 1] = DP[i][now_h];
			if(now_h-1>=0)	DP[i + 1][now_h - 1] = DP[i][now_h];
		
			DP[i + 1][now_h] = DP[i][now_h];
		}
		else {
			for (int h = 0; h <= H; h++) {
				if (h == 0)	DP[i + 1][h] = (DP[i][h] % 1000000007 + DP[i][h + 1] % 1000000007) % 1000000007;
				else if (h == H)	DP[i + 1][h] = (DP[i][h - 1] % 1000000007 + DP[i][h] % 1000000007) % 1000000007;
				else	DP[i + 1][h] = ((DP[i][h - 1] % 1000000007 + DP[i][h] % 1000000007) % 1000000007 + +DP[i][h + 1] % 1000000007) % 1000000007;

			}


		}


	}

	cout << DP[N - 1][0] % 1000000007;





	return 0;
}