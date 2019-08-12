#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <functional>
#include <cmath>


using namespace std;




int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	vector<int> a;
	int i = 2;

	while (N != 1) {
		if (N%i == 0) {
			a.push_back(i);
			N = N / i;
		}
		else i++;
	}

	for (auto& n : a) cout << n << '\n';


	return 0;
}