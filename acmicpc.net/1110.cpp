#include <iostream>
#include <vector>
#include <algorithm>
#include <string>


using namespace std;

int do_operate(int a) {
	int tmp = a;
	string first = to_string(tmp);
	if (tmp < 10) tmp *= 10;
	
	string tmp2 = to_string(tmp);
	int sum = 0;
	for (auto& n : tmp2) sum += (n - '0');

	string tmp3 = to_string(sum);

	

	return (first.back() - '0') * 10 + (tmp3.back() - '0');
}


int main() {



	int n;
	cin >> n;

	int next = do_operate(n);
	int cnt = 1;
	while (next != n) {
	
		next = do_operate(next);
		cnt++;
	}
	

	cout << cnt;

	return 0;
}