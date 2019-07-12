#include <iostream>
#include <algorithm>
#include <vector>


using namespace std;


void count_way(const vector<int>& arr, int start_index, int count, int S, int* way) {


	if (arr.size() - start_index > count) return;
	if()



	count_way(arr, start_index + 1, count, S, way);
	count_way(arr, start_index+1, count - 1, S - arr[start_index], way);



}


int main() {


	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	int N, S;
	cin >> N >> S;
	int tmp;

	vector<int> arr(N);
	for (int i = 0; i < N; i++) {
		arr[i] = tmp;
	}
	int way = 0;





	return 0;
}