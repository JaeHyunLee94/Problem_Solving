#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {


	long long min;
	long long max;
	cin >> min >> max;
	vector<bool> table(1000001000000,false);

	for (long long  i = 2; i <= sqrt(1000001000000); i++) {
		for (long long j = 1; i * i * j < 1000001000000; j++) {
			table[i * i * j] = true;
		}

	}
	long long cnt = 0;

	for (int i = min; i <= max; i++) {
		if (table[i]) cnt++;
	}
	









	return 0;
}