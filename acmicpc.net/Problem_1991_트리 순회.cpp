#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int conv(char a) {
	if (a >= 65 && a <= 90) return a - 65;
	else if (a == 46) return 26;
	else return -1;
}
char invert(int a) {
	if (a >= 0 && a <= 25) return a + 65;
	else if (a == 26) return '.';
	else return 0;
}
int find_index(const vector<vector<int>>& tree, int code) {
	int index = 0;
	for (auto& n: tree) {
		
		if (n[0] == code) break;
		index++;
	}
	return index;
}


void inorder(const vector<vector<int>>& tree,int root ){
	if(root==26) return;
	int index = find_index(tree, root);
	

	inorder(tree,tree[index][1]);
	cout << invert(root);
	inorder(tree,tree[index][2]);
}
void poseorder(const vector<vector<int>>& tree,int root ){
	if(root==26) return;
	int index = find_index(tree, root);
	poseorder(tree,tree[index][1]);
	poseorder(tree,tree[index][2]);
	cout << invert(root);
}
void preorder(const vector<vector<int>>& tree,int root ){
	if(root==26) return;
	int index = find_index(tree, root);
	cout << invert(root);

	preorder(tree,tree[index][1]);

	preorder(tree,tree[index][2]);
}



int main() {

	

	int num_of_node;
	cin>> num_of_node;

	vector<vector<int>> adj_list(num_of_node + 5);

	for(int i=0; i<num_of_node;i++){
		for(int j=0;j<3;j++){
			char tmp;
			cin >> tmp;
			int tmp2 = conv(tmp);

			adj_list[i].push_back(tmp2);
		}
	}
	preorder(adj_list,adj_list[0][0]);
	cout<<endl;
	inorder(adj_list,adj_list[0][0]);
	
	cout<<endl;
	poseorder(adj_list,adj_list[0][0]);
	

	system("pause");


	return 0;
}