#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <cmath>


using namespace std;



struct coord {
	int x, y;
};


int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int test_case;
	cin >> test_case;

	for (int t = 1; t <= test_case; t++) {

		int can_make = 1;
		vector<coord> arr(4);
		for (int j = 0; j < 4; j++) {
			int x, y;
			cin >> x >> y;
		
			arr[j] = coord{ x,y };
		}

		for (int i = 0; i < 4; i++) {
			for (int j = i + 1; j < 4; j++) {
				if (arr[i].x == arr[j].x && arr[i].y == arr[j].y) {
					can_make = 0;
					
				}
			}
		}

		if (!can_make) {
			cout << 0 << '\n';

		}
		else {
			vector<int> dis;
		
			for (int i = 1; i < 4; i++) {
				for (int j = 0; j + i < 4; j++) {
					int diss = (arr[j].x - arr[i + j].x)*(arr[j].x - arr[i + j].x) + (arr[j].y - arr[i + j].y)*(arr[j].y - arr[i + j].y);
					dis.push_back(diss);
				}
			}
			sort(dis.begin(), dis.end());

			for (int i = 0; i < dis.size() - 1; i++) {
				if (i == 3) {
					if (dis[i] * 2 != dis[i + 1]) {
						can_make = 0;
						break;
					}
				}
				else {
					if (dis[i] != dis[i + 1]) {
						can_make = 0;
						break;
					}
				}
			}
			cout << can_make << '\n';

		}
		
			
	}



	return 0;
}