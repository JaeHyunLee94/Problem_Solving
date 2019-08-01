#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <functional>
#include <map>

using namespace std;



int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long K, N, tmp, maxv=0;
	cin >> K >> N;
	vector<long long> ss(K);
	priority_queue<long long, vector<long long>, greater<long long> > pq;
	map<long long,bool> check;
	for (int i = 0; i < K; i++) {
		cin >> tmp;
		ss[i] = tmp;
		pq.push(tmp);
		check[tmp] = 1;
	}

	for (int i = 0; i  < N-1; i++) {
		
		for (int i = 0; i < K; i++) {

			pq.push(pq.top()*ss[i]);

			if (pq.top() % ss[i] == 0) break;
				
				
		}
		pq.pop();

		

	}

	
	cout << pq.top();
	system("pause");
	return 0;
}