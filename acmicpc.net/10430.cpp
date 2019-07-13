#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;




int main() {



	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int a, b;
	cin >> a >> b;

	string tmp = to_string(b);
	cout << a * (tmp[2] - '0') << '\n';
	cout << a * (tmp[1] - '0') << '\n';
	cout << a * (tmp[0] - '0') << '\n';
	cout << a * b << '\n';



	return 0;
}