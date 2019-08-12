#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

struct vertex {
	long long x, y;

};
struct edge {
	vertex v1, v2;
};

struct rectangle {
	vertex l_b, r_b, r_t, l_t;
	edge l_v, r_v, t_h, b_h;
};


int is_intersect(const edge& a, const edge& b) {


	if (a.v1.x == a.v2.x && b.v1.x == b.v2.x) {
		if (a.v1.x != b.v1.x) return false;
		else if (max(b.v2.y, b.v1.y) < min(a.v2.y, a.v1.y) || min(b.v2.y, b.v1.y) > max(a.v2.y, a.v1.y)) return false;
		else return true;
	}

	pair<long long, long long> v1 = make_pair(a.v2.x - a.v1.x, a.v2.y - a.v1.y);
	pair<long long, long long> v2 = make_pair(b.v1.x - a.v1.x, b.v1.y - a.v1.y);
	pair<long long, long long> v3 = make_pair(b.v2.x - a.v1.x, b.v2.y - a.v1.y);

	long long ccw1 = v1.first*v2.second - v1.second*v2.first;
	long long ccw2 = v1.first*v3.second - v1.second*v3.first;
	if (ccw1 == 0 && ccw2 == 0) {
		return !(max(a.v2.x, a.v1.x) < min(b.v1.x, b.v2.x) || min(a.v2.x, a.v1.x) > max(b.v1.x, b.v2.x));
	}

	pair<long long, long long> v4 = make_pair(b.v2.x - b.v1.x, b.v2.y - b.v1.y);
	pair<long long, long long> v5 = make_pair(a.v1.x - b.v1.x, a.v1.y - b.v1.y);
	pair<long long, long long> v6 = make_pair(a.v2.x - b.v1.x, a.v2.y - b.v1.y);

	long long ccw3 = v4.first*v5.second - v4.second*v5.first;
	long long ccw4 = v4.first*v6.second - v4.second*v6.first;


	return ccw1*ccw2 <= 0 && ccw3*ccw4 <= 0;



}

long long is_online(edge& line, vertex& ver) {
	return (ver.y - line.v1.y) * (line.v2.x - line.v1.x) == (ver.x - line.v1.x) * (line.v2.y - line.v1.y);
}




long long howmany_meet(rectangle& rec, edge& line) {

	long long num_of_intersect = 0;
	num_of_intersect += is_intersect(rec.b_h, line);
	num_of_intersect += is_intersect(rec.t_h, line);
	num_of_intersect += is_intersect(rec.l_v, line);
	num_of_intersect += is_intersect(rec.r_v, line);

	if (num_of_intersect == 0) return 0;
	else if (num_of_intersect == 1) {
		if (line.v1.x == line.v2.x) {
			if (line.v1.x > rec.l_b.x && line.v1.x < rec.r_b.x) return 1;
			else if (rec.l_t.y == min(line.v1.y, line.v2.y) || rec.l_b.y == max(line.v1.y, line.v2.y)) return 1;
			else return 4;
		}
		else if (line.v1.y == line.v2.y) {
			if (line.v1.y > rec.r_b.y && line.v1.y < rec.r_t.y) return 1;
			else if (rec.r_t.x == min(line.v1.x, line.v2.x) || rec.l_t.x == max(line.v1.x, line.v2.x)) return 1;
			else return 4;
		}
		else return 1;
	}
	else if (num_of_intersect == 2) {

		if (line.v1.x == line.v2.x) {
			if (line.v1.x > rec.l_b.x && rec.r_b.x > line.v1.x) return 2;
			else if (rec.l_t.y == min(line.v1.y, line.v2.y) || rec.l_b.y == max(line.v1.y, line.v2.y)) return 1;
			else return 4;
		}
		else if (line.v1.y == line.v2.y) {
			if (line.v1.y > rec.l_b.y && rec.r_t.y > line.v1.y) return 2;
			else if (rec.r_b.x == min(line.v1.x, line.v2.x) || rec.l_b.x == max(line.v1.x, line.v2.x)) return 1;
			else return 4;
		}

		else if (is_online(line, rec.l_t) || is_online(line, rec.r_t) || is_online(line, rec.l_b) || is_online(line, rec.r_b)) return 1;
		else return 2;

	}
	else if (num_of_intersect == 3) {
		if (line.v1.x == line.v2.x || line.v1.y == line.v2.y) return 4;
		else return 2;
	}
	else return 2;

}




int main() {


	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long test_case;
	cin >> test_case;


	for (long long t = 1; t <= test_case; t++) {
		long long line_x1, line_y1, line_x2, line_y2;
		long long left_bottom_x, left_bottom_y, right_top_x, right_top_y;

		cin >> left_bottom_x >> left_bottom_y >> right_top_x >> right_top_y;

		rectangle rec;

		rec.l_b = vertex{ left_bottom_x,left_bottom_y };
		rec.r_b = vertex{ right_top_x,left_bottom_y };
		rec.r_t = vertex{ right_top_x,right_top_y };
		rec.l_t = vertex{ left_bottom_x,right_top_y };

		rec.l_v = edge{ rec.l_b,rec.l_t };
		rec.r_v = edge{ rec.r_b,rec.r_t };
		rec.t_h = edge{ rec.l_t,rec.r_t };
		rec.b_h = edge{ rec.l_b,rec.r_b };

		cin >> line_x1 >> line_y1 >> line_x2 >> line_y2;

		vertex line_coord1{ line_x1,line_y1 };
		vertex line_coord2{ line_x2,line_y2 };

		edge line{ line_coord1,line_coord2 };

		cout << howmany_meet(rec, line) << '\n';


	}

	return 0;
}


