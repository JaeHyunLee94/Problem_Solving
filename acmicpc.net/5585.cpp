#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>



using namespace std;



int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int money;
	cin >> money;
	money = 1000 - money;

	vector<int> rest_list(6, 0);
	rest_list[0] = 500;
	rest_list[1] = 100;
	rest_list[2] = 50;
	rest_list[3] =10;
	rest_list[4] = 5;
	rest_list[5] = 1;
	int ans = 0;

	for (int i = 0; i < 6; i++) {
		while (money >= 0) {
			money -= rest_list[i];
			ans++;
		}
		money += rest_list[i];
		ans--;
	}
	cout << ans;







	return 0;
}