#include <iostream>
#include <algorithm>
#include <map>


using namespace std;

long long find_n(long long N, long long P, long long Q, map<long long,long long>& DP) {
	if (DP[N]) return DP[N];
	
	long long& ret = DP[N];
	if (N == 0) return ret = 1;
	

	return ret=find_n((long long)(N / P), P, Q, DP) + find_n((long long)(N / Q), P, Q, DP);
	
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long N, P, Q;
	cin >> N >> P >> Q;
	map<long long, long long> DP;



	cout << find_n(N, P, Q, DP);



	return 0;
}