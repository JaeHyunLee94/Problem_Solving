#include <iostream>
#include <vector>
#include <algorithm>



using namespace std;


int main() {


	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	int cnt = -1;
	int num = 1;
	for (int i = 0; i <= 10; i++) {
		if (n < 3 * i) break;

		if ((n - 3 * i) % 5 == 0) {
			cnt = i + (n - 3 * i) / 5;
			break;
		}
	}
	
	cout << cnt;

	return 0;
}