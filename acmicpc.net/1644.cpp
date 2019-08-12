#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>


using namespace std;


bool comp(const char& a, const char& b) {
	return a > b;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	vector<int> sosu;
	vector<int> is_deleted(N + 1);

	for (int i = 2; i <= N; i++) {
		if (!is_deleted[i]) {
			sosu.push_back(i);
			int start = 1;
			while (i*start <= N) {
				is_deleted[i*start] = 1;
				start++;
			}
		}
		else continue;
	}

	int cnt = 0;
	int size = sosu.size();
	int tail = 0;
	int sum = 0;
	for (int head = 0; head < sosu.size(); head++) {
		sum +=sosu[head];
		while (sum >= N) {
			if (sum == N) cnt++;
			sum -=sosu[tail];
			tail++;

		}



	}
	cout << cnt;


	return 0;
}