#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> slice(const vector<int> &tmp, int a, int b) {
	
	if (a == b) {
		vector <int> s;
		return s;
	}

	else {
		vector <int> s(tmp.begin() + a, tmp.begin() + b);
		return s;
	}
}


void print_post(const vector<int> &pre, const vector<int> &inor) {
	
	
	if (pre.empty()) return;

	const int SIZE = pre.size();
	const int root = pre[0];

	
	const int lft_tree_size = find(inor.begin(), inor.end(), root) - inor.begin();
	const int rgt_tree_size = SIZE - lft_tree_size - 1;
	
	vector <int> p = slice(pre, 1, lft_tree_size + 1);
	vector <int> i = slice(inor, 0, lft_tree_size);
	print_post(slice(pre, 1, lft_tree_size+1), slice(inor, 0, lft_tree_size));
	print_post(slice(pre, lft_tree_size + 1, SIZE), slice(inor, lft_tree_size + 1, SIZE));
	cout << root<<" ";


}

int main() {

	int test_case = 0;
	int num_of_node = 0;

	cin >> test_case;

	for (int i = 0; i < test_case; i++) {

		cin >> num_of_node;
		vector<int> preorder;
		vector<int> inorder;
		int tmp = 0;
		for (int i = 0; i < num_of_node; i++) {
			cin >> tmp;
			preorder.push_back(tmp);
		}
		for (int i = 0; i < num_of_node; i++) {
			cin >> tmp;
			inorder.push_back(tmp);
		}
		print_post(preorder, inorder);
		cout << endl;

	}

	system("pause");


	return 0;
}