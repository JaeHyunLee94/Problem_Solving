#include <iostream>
#include <vector>
#include <algorithm>



using namespace std;

struct node {
	int r;
	int g;
	int b;

};

int main() {


	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	vector<node> house(N);

	for (int i = 0; i < N; i++) {
		int rr, gg, bb;
		cin >> rr >> gg >> bb;
		house[i].r = rr;
		house[i].g = gg;
		house[i].b = bb;
	}

	vector<int> min_red(N);
	vector<int> min_blue(N);
	vector<int> min_green(N);
	vector<int> min_cost(N);
	min_red[0] = house[0].r;
	min_green[0] = house[0].g;
	min_blue[0] = house[0].b;

	for (int i = 1; i < N; i++) {
		min_red[i] = min(min_blue[i - 1] + house[i].r, min_green[i - 1] + house[i].r);
		min_blue[i] = min(min_red[i - 1] + house[i].b, min_green[i - 1] + house[i].b);
		min_green[i] = min(min_blue[i - 1] + house[i].g, min_red[i - 1] + house[i].g);
	}

	cout << min(min_red[N - 1], min(min_blue[N - 1], min_green[N - 1]));


	return 0;
}