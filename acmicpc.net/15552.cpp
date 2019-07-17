#include <iostream>


using namespace std;

int main() {


	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int test_case;
	cin >> test_case;
	int a, b;

	for (int i = 1; i <= test_case; i++) {
		cin >> a >> b;
		cout << a + b << '\n';
	}








	return 0;
}