#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;


int main() {
	int in = 0, out = 0;
	int in_train = 0;
	int max = 0;

	for (int i = 0; i < 4; i++) {
		scanf_s("%d %d", &out, &in);
		in_train -= out;
		if (max <= in_train) max = in_train;
		in_train += in;
		if (max <= in_train) max = in_train;

	}

	cout << max;





	return 0;
}