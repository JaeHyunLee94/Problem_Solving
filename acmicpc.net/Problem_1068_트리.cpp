#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <queue>
using namespace std;

int leaf_num = 0;



void deletenode(vector<list<int>>& tree, const vector<int>& parent,int del_node) {
	queue <int> tm;
	int a;
	if (parent[del_node] == -1) {
		tree.clear();
		return;
	}
	tm.push(del_node);

	while (!tm.empty()) {
		a = tm.front();
		tm.pop();

		int par = parent[a];
		tree[par].remove(a);
		for (auto& n : tree[a]) {
			tm.push(n);
		}

	}

	



}

void find_leaf(const vector<list<int>>& tree,int root) {
	if (tree.empty()) return;
	if (tree[root].empty()) {
		leaf_num++;
		return;
	}

	for (auto& n : tree[root]) {
		find_leaf(tree, n);
	}

}



int main() {

	int root;
	int node_num;
	int delete_node;
	int tmp;
	cin >> node_num;
	vector<list<int>> tree(node_num);
	vector<int> parent(node_num,-1);
	vector<bool> is_alive(node_num, false);
	

	for (int i = 0; i < node_num; i++) {
		scanf("%d", &tmp);
		
		parent[i] = tmp;
		if (tmp != -1) {
			tree[tmp].push_back(i);
			
		}
		else root = i;
		

	}
	cin >> delete_node;
	

	deletenode(tree, parent,delete_node);

	find_leaf(tree,root);

	cout << leaf_num;
	




	system("pause");
	return 0;
}