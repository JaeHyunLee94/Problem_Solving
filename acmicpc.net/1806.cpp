#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	int N, M;
	int tmp;

	int ans = 2147483647;
	cin >> N >> M;

	vector<int> arr(N+1,0);

	for (int i = 1; i <= N; i++) {
		cin >> tmp;
		arr[i] = tmp;
		
	}

	int tail = 0;
	int sum = 0;
	for (int head = 0; head <= N; head++) {
		sum += arr[head];
		while (sum >= M) {
			ans = min(ans, head - tail+1);
			sum -= arr[tail];
			tail++;
			
		}



	}
	

	if (ans == 2147483647) cout << 0;
	else cout << ans;
	

	

	system("pause");





	return 0;
}