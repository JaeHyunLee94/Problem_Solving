#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int findt(vector<int>& tree, int a) {
	if (tree[a] == a) return a;
	else {
		int y= findt(tree, tree[a]);
		tree[a] = y;
		return y;
	}
}



void uniont(vector<int>& tree, int a, int b) {
	int aroot = findt(tree,a);
	int broot = findt(tree,b);
	if (aroot == broot) return;
	else tree[aroot] = broot;
	
}



int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	int n, m;
	int a, b, command;
	cin >> n >> m;
	vector<int> tree(n + 1,0);
	for (int i = 1; i <= n; i++) {
		tree[i] = i;
	}

	for (int i = 0; i < m; i++) {
		cin >> command >> a >> b;
		if (!command) uniont(tree, a, b);
		else  cout << (findt(tree, a) == findt(tree, b) ?  "YES" : "NO") << '\n';
	
	}

	



	system("pause");




	return 0;
}