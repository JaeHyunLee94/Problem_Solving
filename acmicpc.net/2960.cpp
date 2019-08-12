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

	int N, K;
	cin >> N >> K;
	vector<int> kth;
	vector<int>is_deleted(N + 1,0);


	for (int i = 2; i <= N; i++) {
		if (!is_deleted[i]) {
			
			int start = 1;
			while (i*start <= N) {
				if (!is_deleted[i*start]) {
					is_deleted[i*start] = 1;
					kth.push_back(i*start);
				}
				start++;
			}
		}
		else continue;
	}
	cout << kth[K - 1];


	return 0;
}