#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>


using namespace std;


bool comp(const char& a,const char& b) {
	return a > b;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int is_ten = 0;
	int is_three = 0;
	int sum = 0;
	string N;
	cin >> N;
	

	for (auto& n : N) {
		if (n == '0') is_ten = 1;
		sum += n - '0';

	}
	if (sum % 3 == 0) is_three=1;

	if (is_three && is_ten) {
		sort(N.begin(), N.end(), comp);
		for (auto& n : N) cout << n;
	}
	else cout << -1;
	

	return 0;
}