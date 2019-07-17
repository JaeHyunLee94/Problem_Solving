#include <iostream>
#include <vector>

using namespace std;


int main() {
	

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	vector<long long> an(N + 1);
	vector<long long> bn(N + 1);

	an[1] = 0;
	bn[1] = 1;
	for (int i = 2; i <= N; i++) {
		an[i] = an[i - 1] + bn[i - 1];
		bn[i] = an[i - 1];
	}

	cout << an[N] + bn[N];


	return 0;
}