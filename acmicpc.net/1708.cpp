#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long standx=1, standy=0;

struct point {
	long long x, y;
	long long p; long long q;
	
};

long long ccw(const point& a, const point& b, const point& c) {
	return (a.x*b.y + b.x*c.y + c.x*a.y) - (a.y*b.x + b.y*c.x + c.y*a.x);
}

bool comp(const point& a, const point& b) {
	if (b.p*a.q != a.p*b.q) return b.p*a.q < a.p*b.q;
	if (a.y != b.y) return a.y <b.y;

	return a.x < b.x;
}






int main() {


	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	long long N;
	cin >> N;
	vector<point> arr(N);

	for (long long i = 0; i < N; i++) {
		long long x, y;
		cin >> x >> y;
		arr[i] = point{ x,y,1,0 };
	}
	
	sort(arr.begin(), arr.end(),comp);
	for (long long i = 1; i < N; i++) {
		arr[i].p = arr[i].x - arr[0].x;
		arr[i].q = arr[i].y - arr[0].y;
	}

	sort(arr.begin() + 1, arr.end(), comp);

	vector<long long> stack;

	stack.push_back(0);
	stack.push_back(1);

	long long next = 2;


	while (next<N) {


		while (stack.size() >= 2) {
			int second = stack.back();
			stack.pop_back();
			int first = stack.back();
			if (ccw(arr[first], arr[second], arr[next]) > 0) {
				stack.push_back(second);
				break;
			}
			
			
		
		}
		stack.push_back(next++);
	}

	cout << stack.size();


	return 0;
}


