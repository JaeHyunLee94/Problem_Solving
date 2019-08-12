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
	pair<long long, long long> v3= make_pair(b.x2 - a.x1, b.y2 - a.y1);

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


long long findf(vector<long long>& parent,long long i) {
	if (i == parent[i]) return i;

	else {
		
		long long p=findf(parent, parent[i]);
		parent[i] = p;
		return p;
	}

}

void unionf(vector<long long>& parent, long long i, long long j) {
	long long x = findf(parent,i);
	long long y = findf(parent,j);

	if (x != y) {
		parent[y] = x;
	}


}



int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long N;
	cin >> N;
	vector<edge> edge_list(N);
	vector<long long> parent(N);
	vector<long long> group(N,0);

	for (long long i = 0; i < N; i++) {
		long long x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		edge_list[i].x1 = x1;
		edge_list[i].y1 = y1;
		edge_list[i].x2 = x2;
		edge_list[i].y2 = y2;
		parent[i] = i;
	}

	for (long long i = 0; i < N; i++) {
		for (long long j = i+1; j < N; j++) {
			if (is_meet(edge_list[i], edge_list[j])) unionf(parent, i, j);
		}
	}
	long long size = 0;
	long long num = 0;
	for (long long i = 0; i < N; i++) {
		group[findf(parent, i)]++;
	}
	for (long long i = 0; i < N; i++) {
		if (group[i] > 0) {
			num++;
			if (group[i] > size) size = group[i];
		}
	}

	cout << num << '\n' << size;

	return 0;
}