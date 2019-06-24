#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;




int main() {

	
	int N = 0;
	scanf("%d", &N);
	vector<long long > solution;

	long long left;
	long long  right;
	long long  mid;
	long long tmp;

	for (int i = 0; i < N; i++) {
		scanf("%lld",&tmp);
		solution.push_back(tmp);
	}
	int k= N - 1;
	
	sort(solution.begin(), solution.end());
	

	int index1=0, index2=0, index3=0;
	long long ans= 9223372036854775807; //�ִ밪



	for (int i = 0; i < N; i++) {
		mid = solution[i];
		k = N - 1;
		for (int j = i+1; j < N; j++) {
			if (j == k ) k++;
			if (k == N) break;
			left = solution[j];
			right = solution[k];
			if (mid + left + right < 0) {
				if (k < N - 1) {

					while (abs(mid + left + solution[k]) >= abs(mid + left + solution[k + 1])) {
						k++;
						if (k >= N - 1) break;

					}

				}
				
				if (ans > abs(mid + left + solution[k])) {
					index1 = i;
					index2 = j;
					index3 = k;
					ans = abs(mid + left + solution[k]);
				}
			}
			else {

				if (k > j + 1) {
					while ((abs(mid + left + solution[k]) >= abs(mid + left + solution[k - 1]))) {
						k--;
						if (k <= j + 1) break;
					}

				}
				

				if (ans > abs(mid + left + solution[k])) {
					index1 = i;
					index2 = j;
					index3 = k;
					ans = abs(mid + left + solution[k]);
				}
			}

		

		}
	}

	printf("%lld %lld %lld", solution[index1], solution[index2], solution[index3]);




	return 0;
}