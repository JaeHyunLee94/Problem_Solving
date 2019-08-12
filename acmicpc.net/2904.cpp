#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>

using namespace std;

void update(map<int, int>& a, int tmp, map<int, int>& gcd) {

	int start = 2;
	while (tmp != 1) {
		if (tmp%start == 0) {
			a[start]++;
			gcd[start]++;
			tmp /= start;
		}
		else start++;
	}

	return;


}


int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, tmp;
	int cnt = 0;
	cin >> N;
	map<int, int> gcd;
	int gcdd = 1;
	vector<map<int, int>> arr(N);
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		update(arr[i], tmp, gcd);

	}
	for (auto& n : gcd) {
		n.second /= N;
	}
	for (auto& n : gcd) {
		gcdd *= pow(n.first, n.second);
	}

	for (auto& n : arr) {
		for (auto& m : gcd) {
			if (n[m.first] < m.second) {
				cnt += m.second - n[m.first];
			}
		}
	}
	cout << gcdd << " " << cnt<<'\n';

	return 0;
}