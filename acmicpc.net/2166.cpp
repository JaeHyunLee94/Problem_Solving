#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>


using namespace std;

struct node {
	long long x;
	long long y;
};

long double area(const node& a, const node& b) {
	return 0.5*(a.y*b.x - a.x*b.y);
}

int main() {
	

	long long N;
	cin >> N;
	long double ans = 0;
	vector<node> recs(N);
	for (long long i = 0; i < N; i++) {
		long long x, y;
		cin >> x >> y;
		recs[i].x = x;
		recs[i].y = y;
	}

	for (long long i = 0; i < N - 1; i++) {
		ans += area(recs[i], recs[i + 1]);
	}
	ans += area(recs[N - 1], recs[0]);

	ans = abs(ans);

	printf("%.1Lf", ans);

	return 0;
}