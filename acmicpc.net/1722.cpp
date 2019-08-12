#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;





int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	long long N, command;
	cin >> N >> command;
	vector<long long> f(21);
	f[0] = 1;
	f[1] = 1;
	for (long long i = 2; i <= 20; i++) {
		f[i] = i * f[i - 1];
	}
	if (command == 1) {
		long long m;
		cin >> m;
		vector<long long>arr(N);
		vector<long long> is_visit(N,0);
		for (long long i = 0; i < N; i++) arr[i] = i;

		for (long long i = 0; i < N; i++) {
			for (long long j = 0; j < N; j++) {

				if (is_visit[j]) continue;
				else if (f[N - i - 1] < m) m-= f[N - i - 1];
				else {
					cout << j + 1 << " ";
					is_visit[j] = 1;
					break;
				}


			}
		}
		
		

	}
	else {
		vector<long long> arr(N);
		vector<long long> is_visit(N, 0);
		for (long long i = 0; i < N; i++) {
			long long tmp;
			cin >> tmp;
			arr[i] = tmp-1;

		}
		long long m = 0;
		for (long long i = 0; i < N; i++) {
			for (long long j = 0; j < N; j++) {
				if (is_visit[j]) continue;
				else if (arr[i] != j) m += f[N - i - 1];
				else {
					is_visit[j] = 1;
					break;
				}
			}
		}
		cout << m+1;



	}





	return 0;
}