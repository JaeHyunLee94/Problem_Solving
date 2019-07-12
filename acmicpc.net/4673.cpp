#include <iostream>
#include <vector>
#include <algorithm>
#include <string>


using namespace std;

int d_n(int a) {

	int sum = a;
	string tmp = to_string(a);

	for (auto& n : tmp) sum += n - '0';

	return sum;
}

void generate(int n, vector<int>& table) {
	int a = d_n(n);
	while (a <= 10000) {
		table[a]++;
		a = d_n(a);
	}


}



int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<int> table(10001, 0);

	for (int i = 1; i <= 10000; i++) {
		if (table[i] == 0) generate(i, table);
	}


	for (int i = 1; i <= 10000; i++) {
		if (table[i] == 0) cout << i << '\n';
	}






	return 0;
}