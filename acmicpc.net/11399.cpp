#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>

using namespace std;


int main() {

	int N = 0, M = 0;

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	vector<int> my(N);
	int tmp = 0;

	for (int i = 0; i < N; i++) {
		
		cin >> tmp;
		my[i] = tmp;
	}

	sort(my.begin(), my.end());
	int sum = 0;

	for (int i = 0; i < N; i++) {
		sum += (N - i) * my[i];
	} 

	cout << sum << "\n";


	





	return 0;




}