#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;



struct Node{
	int Node_num;
	vector <Node*> child_node;
	vector <int> distance;
};

Node* search_node( Node* root,int num){
	if(!root) return nullptr;

	if(root->Node_num==num) return root;

	for(auto n: root->child_node){
		Node* tmp=search_node(n,num);
		if(tmp) return tmp;
	}
	return nullptr;
}

Node* insert_node(Node* root, int parent, int child, int dis){
	

	Node* nd = new Node;
	nd->Node_num = child;
	if (!root) {
		Node* par = new Node;
		par->Node_num = parent;
		par->child_node.push_back(nd);
		par->distance.push_back(dis);
		
		return par;
	}
	Node* par=search_node(root,parent);
	par->child_node.push_back(nd);
	par->distance.push_back(dis);

	return root;

}

int tree_height(const Node* root) {
	if (!root) return -1;
	if (root->child_node.empty()) return 0;

	vector<int> candidate;
	for (int i = 0; i < root->child_node.size();i++) {
		candidate.push_back(tree_height(root->child_node[i])+ root->distance[i]);
	}
	sort(candidate.begin(), candidate.end());

	return candidate.back();

}

int leaf_leafdis(const Node* root) {

	if (!root) return -1;
	if (root->child_node.size() <= 1) return -1;

	vector<int> candidate;

	for (int i = 0; i < root->child_node.size();i++) {
		candidate.push_back(tree_height( root->child_node[i])+root->distance[i]);
	}

	sort(candidate.begin(), candidate.end());

	return  candidate[candidate.size()-1] + candidate[candidate.size() - 2];
}

int main() {
	int num_of_node;
	Node* root = nullptr;
	vector<int> longest;
	queue <Node*> bfs;

	cin >> num_of_node;

	for (int i = 0; i < num_of_node-1; i++) {

		int parent, child, dis;

		cin >> parent;
		cin >> child;
		cin >> dis;

		root = insert_node(root, parent, child, dis);



	}
	
	longest.push_back(tree_height(root));

	bfs.push(root);
	while (!bfs.empty()) {
		Node* tmp = bfs.front();
		bfs.pop();
		longest.push_back(leaf_leafdis(tmp));

		for (auto n : tmp->child_node) {

			bfs.push(n);
		}

	}
	
	sort(longest.begin(), longest.end());

	cout << longest.back();

	system("pause");
	

	return 0;
}
