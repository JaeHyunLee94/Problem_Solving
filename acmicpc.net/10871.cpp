#include <iostream>
#include <algorithm>
#include <vector>







using namespace std;


int main() {

	int N = 0, X = 0;
	int tmp = 0;
	vector<int> arr;
	cin >> N >> X;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		if (tmp < X) arr.push_back(tmp);
	}

	for (auto& n : arr) {
		cout << n << " ";
	}





	return 0;
}