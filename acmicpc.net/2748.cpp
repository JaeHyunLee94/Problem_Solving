#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);



	int N;
	cin >> N;
	vector<long long> fibo(100,0);
	fibo[1] = 0;
	fibo[2] = 1;

	for (int i = 3; i <= N+1; i++) {
		fibo[i] = fibo[i - 1] + fibo[i - 2];
	}
	cout << fibo[N+1];



	system("pause");





	return 0;
}