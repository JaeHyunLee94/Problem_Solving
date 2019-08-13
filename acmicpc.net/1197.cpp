#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std;


struct edge {
	long long from, to, w;

	
};
bool operator <(const edge& a,const edge& b) {
	return a.w > b.w;
}



long long findf(long long a,vector<long long>& parent) {
	if (parent[a] == a) return a;
	else {
		long long p = findf(parent[a], parent);
		parent[a] = p;
		return p;
	}
}

void unionf(long long a, long long b, vector<long long>& parent) {
	long long first = findf(a, parent);
	long long second= findf(b, parent);
	if (a == b) return;
	else parent[second] = first;
}


int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long V, E;
	cin >> V >> E;
	priority_queue<edge> pq;
	vector<long long> parent(V + 1,0);
	for (long long i = 1; i <= V; i++) parent[i] = i;
	for (long long i = 0; i < E; i++) {
		long long from, to, w;
		cin >> from >> to >> w;
		pq.push(edge{ from,to,w });
	}

	long long n = 0;
	long long ans = 0;
	while (n < V - 1) {
		edge next_edge = pq.top();
		pq.pop();

		if (findf(next_edge.from, parent) != findf(next_edge.to, parent)) {
			ans += next_edge.w;
			unionf(next_edge.from, next_edge.to, parent);
			n++;
		}
	}

	cout << ans;

	



	return 0;
}