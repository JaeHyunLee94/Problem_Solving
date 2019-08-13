#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;


void update(const vector<long long>& arr, vector<long long>& tree, long long node, long long start, long long end, long long index, long long diff) {
	if (index<start || index>end) return;
	
	tree[node] += diff;
	long long mid = (start + end) / 2;

	if (start != end) {
		update(arr, tree, node * 2, start, mid, index, diff);
		update(arr, tree, node * 2 + 1, mid + 1, end, index, diff);
	}
	


}

long long init(const vector<long long>& arr, vector<long long>& tree, long long node, long long start, long long end) {
	if (start == end) return tree[node] = arr[start];
	long long mid = (start + end) / 2;
	return tree[node] = init(arr, tree,node * 2, start, mid) + init(arr, tree,node * 2+1, mid+1, end);

}

long long ret_sum(const vector<long long>& arr, vector<long long>& tree,long long node, long long start, long long end, long long left, long long right) {

	if (left > end || right < start) return 0;
	if (left <= start && right >= end) return tree[node];
	long long mid = (start + end) / 2;

	return ret_sum(arr, tree, node * 2, start, mid, left, right) + ret_sum(arr, tree, node * 2+1, mid+1, end, left, right);



}

int main() {

	long long N, M, K;
	
	cin >> N >> M >> K;
	long long t = ceil(log2(N));
	long long max_level = pow(2, t+1);
	vector<long long> arr(N);
	vector<long long> tree(max_level+1);
	for (long long i = 0; i < N; i++) {
		long long tmp;
		cin >> tmp;
		arr[i] = tmp;
	}

	init(arr, tree, 1, 0, N - 1);

	for (long long i = 0; i < M + K; i++) {
		long long command;
		cin >> command;
		if (command == 1) {
			long long a, towhat;
			cin >> a >> towhat;
			
			update(arr, tree, 1, 0, N - 1, a-1, towhat - arr[a-1]);
			arr[a - 1] = towhat;
		}
		else {
			long long from, to;
			cin >> from >> to;
			cout << ret_sum(arr, tree, 1, 0, N - 1, from - 1, to - 1) << '\n';

		}
	}


	


	return 0;
}