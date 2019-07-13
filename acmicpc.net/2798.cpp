#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {



	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M, tmp;
	cin >> N >> M;

	vector<int> card(N, 0);

	for (int i = 0; i < N; i++) {
		cin >> tmp;
		card[i] = tmp;
	}
	
	sort(card.begin(), card.end());

	int diff = M - (card[0] + card[1] + card[2]);
	int ans = card[0] + card[1] + card[2];

	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			for (int k = j + 1; k < N; k++) {
				int sum = card[i] + card[j] + card[k];
				if (sum <= M && M - sum < diff) {
					diff = M - sum;
					ans = sum;
				}
			}
		}
	}

	cout << ans << '\n';



	return 0;
}