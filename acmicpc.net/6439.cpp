#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>


using namespace std;

struct edge {
	long long x1, y1;
	long long x2, y2;

};



bool is_meet(const edge& a, const edge& b) {


	if (a.x1 == a.x2 && b.x1 == b.x2) {
		if (a.x1 != b.x1) return false;
		else if (max(b.y2, b.y1) < min(a.y2, a.y1) || min(b.y2, b.y1) > max(a.y2, a.y1)) return false;
		else return true;
	}

	pair<long long, long long> v1 = make_pair(a.x2 - a.x1, a.y2 - a.y1);
	pair<long long, long long> v2 = make_pair(b.x1 - a.x1, b.y1 - a.y1);
	pair<long long, long long> v3 = make_pair(b.x2 - a.x1, b.y2 - a.y1);

	long long ccw1 = v1.first*v2.second - v1.second*v2.first;
	long long ccw2 = v1.first*v3.second - v1.second*v3.first;
	if (ccw1 == 0 && ccw2 == 0) {
		return !(max(a.x2, a.x1) < min(b.x1, b.x2) || min(a.x2, a.x1) > max(b.x1, b.x2));
	}

	pair<long long, long long> v4 = make_pair(b.x2 - b.x1, b.y2 - b.y1);
	pair<long long, long long> v5 = make_pair(a.x1 - b.x1, a.y1 - b.y1);
	pair<long long, long long> v6 = make_pair(a.x2 - b.x1, a.y2 - b.y1);

	long long ccw3 = v4.first*v5.second - v4.second*v5.first;
	long long ccw4 = v4.first*v6.second - v4.second*v6.first;


	return ccw1*ccw2 <= 0 && ccw3*ccw4 <= 0;



}


int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int test_case;
	cin >> test_case;

	for (int t = 1; t <= test_case; t++) {
		int x1, y1, x2, y2;
		int v1_x, v1_y, v2_x, v2_y;
		
		cin >> x1 >> y1 >> x2 >> y2;
		edge tmp{ x1,y1,x2,y2 };
		vector<edge> rec(4);
		cin >> v1_x >> v1_y >> v2_x >> v2_y;
		int t_y = max(v1_y, v2_y);
		int b_y = min(v1_y, v2_y);
		int l_x = min(v1_x, v2_x);
		int r_x = max(v1_x, v2_x);

		
		rec[0] = edge{ l_x,b_y,r_x,b_y };
		rec[1] = edge{ l_x,b_y,l_x,t_y };
		rec[2] = edge{ r_x,t_y,r_x,b_y };
		rec[3] = edge{ r_x,t_y,l_x,t_y };
		int is_meetrec = 0;
		for (int i = 0; i < 4; i++) {
			if (is_meet(rec[i], tmp)) {
				is_meetrec = 1;
				break;
			}
		}
		if (tmp.x1 < r_x && tmp.x1>l_x && tmp.x2<r_x && tmp.x2>l_x && tmp.y1 > b_y && tmp.y1<t_y && tmp.y2>b_y && tmp.y2 < t_y) {
			is_meetrec = 1;
		}
		cout << (is_meetrec == 1 ? "T" : "F") <<'\n';
	}

	return 0;
}