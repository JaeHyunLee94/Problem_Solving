#include <iostream>
#include <algorithm>
#include <vector>



using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);


	int x1, y1, x2, y2, x3, y3;

	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

	pair<int, int> v1 = make_pair(x2 - x1, y2 - y1);
	pair<int, int> v2 = make_pair(x3 - x1, y3 - y1);

	int ccw = v1.first*v2.second - v1.second*v2.first;


	if (ccw > 0) cout << 1;
	else if (ccw < 0) cout << -1;
	else cout << 0;



	return 0;
}