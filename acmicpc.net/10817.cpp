#include <iostream>
#include <vector>
#include <algorithm>



using namespace std;



int main() {


	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int a, b, c;
	cin >> a >> b >> c;

	vector<int> tmp(3);
	tmp[0] = a;
	tmp[1] = b;
	tmp[2] = c;
	sort(tmp.begin(), tmp.end());
	cout << tmp[1];



	return 0;
}