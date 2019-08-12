#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;


int main() {

	int N, K;
	cin >> N >> K;


	int ans = 1;
	for (int i = 0; i < K; i++) {
		ans *= (N - i);
	}
	for (int i = 0; i < K; i++) {
		ans /= (K - i);
	}

	cout << ans;



	return 0;
}