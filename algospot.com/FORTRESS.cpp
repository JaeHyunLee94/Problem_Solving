#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int sqr(int a) {
	return a * a;
}
int longest = 0;



struct TreeNode {
	int x, y, r;
	vector<TreeNode*> child_list;
};


int isChild(const TreeNode* a, const TreeNode* b) {
	int x_a = a->x;
	int y_a = a->y;
	int r_a = a->r;
	int x_b = b->x;
	int y_b = b->y;
	int r_b = b->r;

	if (sqr(x_a - x_b) + sqr(y_a - y_b)<sqr(r_a - r_b)) {
		return r_a - r_b;
	}
	else return 0;
}
TreeNode* make_tree(int x, int y, int r) {
	TreeNode* root = new TreeNode;
	root->x = x; root->y = y; root->r = r;
	return root;
}

void insert_node(TreeNode* root, TreeNode* node) {


	int n = root->child_list.size();

	if (n==0) {
		root->child_list.push_back(node);
		return;
	}
	vector<TreeNode*> img;
	vector<TreeNode*> real;

	int flag = 0;
	int index = 0;
	for (int i = 0; i<n; i++) {
		if (isChild(root->child_list[i], node)>0) {
			flag = 1;
			index = i;
			break;
		}
		else if (isChild(root->child_list[i], node)<0) {
			flag = -1;
			img.push_back(root->child_list[i]);
			continue;
		}
		else {
			real.push_back(root->child_list[i]);
			continue;
		}
	}
	if (flag == 0) root->child_list.push_back(node);
		

	else if (flag == -1) {
		root->child_list.clear();
		for (int i = 0; i < img.size(); i++) node->child_list.push_back(img[i]);
		

		for (int i = 0; i < real.size(); i++) root->child_list.push_back(real[i]);

	
		root->child_list.push_back(node);


	}
	else insert_node(root->child_list[index], node);

}

int find_height(TreeNode* root) {
	int n = root->child_list.size();
	if (n== 0) return 0;
	int max = 0;

	for (auto n : root->child_list) {
		int tmp = find_height(n);
		if (tmp >= max) max = tmp;
	}
	return max + 1;

}

int longest_dis(TreeNode* root) {

	int n = root->child_list.size();

	int max1 = 0; int max2 = 0;
	if (n<= 1) return 0;
	else {


		for (auto n : root->child_list) {
			int tmp = find_height(n);
			if (tmp >= max1) {
				max2 = max1;
				max1 = tmp;
			}
			else if (tmp<max1&&tmp >= max2) {
				max2 = tmp;
			}
		}

	}
	return max1 + max2 + 2;
}

void update_longest(TreeNode* root) {
	queue<TreeNode*> bfs_q;

	bfs_q.push(root);
	while (!bfs_q.empty()) {
		TreeNode* tmp = bfs_q.front();
		bfs_q.pop();
		int ismax = longest_dis(tmp);
		if (ismax >= longest) longest = ismax;

		for (auto n : tmp->child_list) bfs_q.push(n);
	}
}



int main() {

	int test_case = 0;
	cin >> test_case;

	for (int i = 0; i<test_case; i++) {
		int num_of_node = 0;
		cin >> num_of_node;
		TreeNode* root = nullptr;

		int tmp_x, tmp_y, tmp_r;
		cin >> tmp_x;
		cin >> tmp_y;
		cin >> tmp_r;
		root = make_tree(tmp_x, tmp_y, tmp_r);

		for (int j = 0; j<num_of_node - 1; j++) {


			cin >> tmp_x;
			cin >> tmp_y;
			cin >> tmp_r;

			TreeNode* tmp = make_tree(tmp_x, tmp_y, tmp_r);
			insert_node(root, tmp);

		}
		longest = find_height(root);
		update_longest(root);

		cout << longest;

		longest = 0;
		free(root);



	}
	//system("pause");

	return 0;
}
