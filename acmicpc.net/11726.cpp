#include <iostream>
#include <vector>
#include <algorithm>



using namespace std;


int main() {


	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	vector<int> fibo(1001,0);

	fibo[1] = 1;
	fibo[2] = 2;

	for (int i = 3; i < 1001; i++) fibo[i] = (fibo[i - 1] + fibo[i - 2]) % 10007;

	cout << fibo[n];

	return 0;
}