#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>


using namespace std;

const int INf = 1000000000;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long N;
	cin >> N;
	long long DP[4][101][10];
	
	memset(DP, 0, sizeof(DP));
	DP[0][10][0] = 1;
	for (int i = 1; i <= 8; i++) DP[3][1][i] = 1;
	for(int i=1;i<=8;i++) DP[3][2][i]= DP[3][1][i - 1] + DP[3][1][i + 1];
	DP[1][2][0] = 1;
	DP[2][2][8]=1;
	DP[2][2][9] = 1;

	for (long long i = 3; i <= 100; i++) {
		for (long long j = 1; j <= 8; j++) {
			
			DP[1][i][j] = (DP[1][i - 1][j - 1] % INf + DP[1][i - 1][j + 1] % INf) % INf;
			DP[2][i][j]= (DP[2][i - 1][j - 1] % INf + DP[2][i - 1][j + 1] % INf) % INf;
			DP[3][i][j] = (DP[3][i - 1][j - 1] % INf + DP[3][i - 1][j + 1] % INf) % INf;

		}
		DP[1][i][9] = 0;
		DP[1][i][0] = (DP[1][i - 1][1] % INf + DP[3][i-1][1] % INf) % INf;
		DP[2][i][0] = 0;
		DP[2][i][9] = (DP[2][i - 1][8] % INf + DP[3][i-1][8] % INf) % INf;

	}
	long long ans = 0;
	for (long long i = 11; i <= 100; i++) {
		for (long long j = 1; j <= 8; j++) {
			DP[0][i][j] = (DP[0][i - 1][j - 1] % INf + DP[0][i - 1][j + 1] % INf);
		}
		DP[0][i][0] = (DP[0][i - 1][1] % INf + DP[2][i - 1][1] % INf) % INf;
		DP[0][i][9] = (DP[0][i - 1][8] % INf + DP[1][i - 1][8] % INf) % INf;
	}

	for (int i = 0; i <= 9; i++) {
		ans += (DP[0][N][i] % INf);
		ans = ans % INf;
	}
	
	cout << ans << '\n';




	return 0;
}