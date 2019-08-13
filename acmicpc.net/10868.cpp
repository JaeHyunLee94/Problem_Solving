#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

const int INf = 987654321;

int init_tree(int node,int start,int end,vector<int>& arr, vector<int>& tree) {

	if (start == end) return tree[node] = arr[start];

	int mid = (start + end) / 2;

	return tree[node] = min(init_tree(node * 2, start, mid, arr, tree), init_tree(node * 2 + 1, mid + 1, end, arr, tree));

}

int return_min(int node, int start, int end, int left, int right, vector<int>& arr, vector<int>& tree) {

	if (start > right || left > end) return INf;

	if (start >= left && end <= right) return tree[node];
	int mid = (start + end) / 2;

	return min(return_min(node * 2, start, mid, left, right, arr, tree), return_min(node*2+1,mid+1,end,left,right,arr,tree));


}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	int N, M;
	cin >> N >> M;
	vector<int> arr(N, 0);
	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		arr[i] = tmp;
	}

	int max_size =(int)( log2(N + 1) + 1);
	max_size = (1 <<( max_size+1)) + 1;
	vector<int> index_tree(max_size, 0);
	init_tree(1, 0, N - 1, arr, index_tree);


	for (int i = 0; i < M; i++) {
		int left, right;
		cin >> left >> right;
		cout << return_min(1, 0, N - 1, left-1, right-1, arr, index_tree) << '\n';
	}




	return 0;
}