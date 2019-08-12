#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <functional>
#include <cmath>


using namespace std;


int ret_nextmod(int a,int n) {
	return (10 * a) % n + 1;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	while (cin >> N) {
		if (N == 1) cout << 1 << '\n';
		else {
			int init = 2;
			int nxt = 11;
			while (nxt%N != 0) {
				nxt = ret_nextmod(nxt, N);
				init++;
			}


			cout << init << '\n';
		}
		


	}

	return 0;
}