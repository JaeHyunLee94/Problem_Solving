#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>


using namespace std;



int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	vector<int> is_deleted(1000001, 0);

	for (int i = 2; i <= 1000000; i++) {
		if (!is_deleted[i]) {

			int start = 2;
			while (i*start <= 1000000) {
				if (!is_deleted[i*start]) {
					is_deleted[i*start] = 1;
				}
				start++;
			}
		}
		else continue;


	}
	while (N) {
		int first = N - 3;
		int is_found = 0;
		while (first >= N / 2) {
			if (!is_deleted[first] && !is_deleted[N - first]) {
				is_found = 1;
				break;
			}
			else first -= 2;
		}



		if (is_found) cout << N << " = " << N - first << " + " << first << '\n';
		else cout << "Goldbach's conjecture is wrong." << '\n';



		cin >> N;
	}
	
	return 0;
}