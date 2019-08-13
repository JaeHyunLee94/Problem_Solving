#include <iostream>
#include <vector>
#include <queue>


using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N,tmp;
	cin >> N;
	priority_queue<int> pq;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		if (!tmp) {
			if (pq.empty()) {
				cout << 0 << '\n';
			}
			else {
				cout  << pq.top() << '\n';
				pq.pop();
			}
			
		}
		else pq.push(tmp);
		

	}

	

	return 0;
}