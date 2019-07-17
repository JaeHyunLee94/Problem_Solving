#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {


	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n=0, cnt=0;
	cin >> n;


	vector<bool> hansu(1001,false);

	for (int i = 1; i < 100; i++) hansu[i] = true;

	for (int i = 10; i < 100; i++) {
		int start = i / 10;
		int d = i % 10 - start;

		if (start + 2 * d < 10 && start + 2 * d >= 0) {
			int next_hansu = start * 100 + (start + d) * 10 + (start + 2 * d);
			hansu[next_hansu] = true;
		}
		
	}

	
	for (int i = 1; i <= n; i++) if (hansu[i]) cnt++;

	cout << cnt;




	return 0;
}