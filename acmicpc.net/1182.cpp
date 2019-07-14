#include <iostream>
#include <vector>
#include <algorithm>



using namespace std;

int cnt = 0;


void count_way(const vector<int>& seq, int S) {

	if (seq.empty()) return;
	if (seq[0] == S) cnt++;
		



	
	vector<int> next_seq(seq.begin() + 1, seq.end());
	count_way(next_seq, S-seq[0]);
	count_way(next_seq, S);




}

int main() {


	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int N, S, tmp;
	cin >> N >> S;
	vector<int> seq(N);
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		seq[i] = tmp;
	}

	sort(seq.begin(), seq.end());

	count_way(seq, S);

	cout << cnt;


	return 0;
}