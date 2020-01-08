#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

struct node {
	int max_val;
	int min_val;
};


node init(vector<node>& tree, vector<int>& arr, int node_index, int start, int end) {

	if (start == end) return tree[node_index] = node{ arr[start],arr[start] };

	int mid = (start + end) / 2;

	node lft = init(tree, arr, node_index * 2, start, mid);
	node rgt = init(tree, arr, node_index * 2+1, mid+1, end);

	int maxx = max(max(lft.max_val, rgt.max_val),max(lft.min_val,rgt.min_val));
	int minx = min(min(lft.max_val, rgt.max_val), min(lft.min_val, rgt.min_val));

	return tree[node_index]=node{ maxx,minx };

}

node find_max_min(vector<node>& tree, vector<int>& arr, int node_index, int start, int end, int left, int right) {

	if (left > end || right < start) return node{ -1, 1000000001 };

	if (left <= start && end<= right) {
		return tree[node_index];
	}

	int mid = (start + end) / 2;

	node lft = find_max_min(tree, arr, node_index * 2, start, mid,left,right);
	node rgt = find_max_min(tree, arr, node_index * 2 + 1, mid + 1, end,left,right);

	int maxx = max(lft.max_val, rgt.max_val);
	int minx = min(lft.min_val, rgt.min_val);
	
	return node{ maxx,minx };

}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	int N, M;

	cin >> N >> M;
	int h = (int)ceil(log2(N));
	int tree_size = (1 << (h + 1));
	vector<node> tree(tree_size);
	vector<int> arr(N);

	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		arr[i] = tmp;
	}

	init(tree, arr, 1, 0, N-1);


	for (int i = 0; i < M; i++) {
		int from, to;
		cin >> from >> to;
		node ans = find_max_min(tree, arr, 1, 0, N - 1, from-1, to-1);
		cout << ans.min_val << ' ' << ans.max_val << '\n';
	}





	return 0;
}