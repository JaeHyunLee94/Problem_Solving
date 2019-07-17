#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void pretopost(vector<int>& pre) {
	if (pre.size() == 1) {
		cout << pre[0] << '\n';
		return;
	}

	vector<int>::iterator index = pre.end();
	for (vector<int>::iterator iter = pre.begin(); iter != pre.end(); iter++) {
		if (*iter > pre[0]) {
			index = iter;
			break;
		}
	}
	vector<int> left(pre.begin() + 1, index);
	vector<int> right(index, pre.end());
	if (left.size()) {
		pretopost(left);
	}
	if (right.size()) {
		pretopost(right);
	}
	

	cout << pre[0] << '\n';


}

int main() {


	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	

	vector<int> preorder;
	int x;
	while (cin >> x) preorder.push_back(x);

	pretopost(preorder);




	return 0;
}