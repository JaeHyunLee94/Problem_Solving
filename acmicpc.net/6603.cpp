#include <iostream>
#include <algorithm>
#include <deque>
#include <vector>

using namespace std;

struct node {
	int num;
	bool is_visited;
};

bool isv(const node& tmp) {
	return tmp.is_visited;
}


void print_all(vector<node>& num, int visited_num, int present_node) {

	if (visited_num == 6) {
		for (auto& n : num) {
			if (n.is_visited) printf("%d ", n.num);
		}
		printf("\n");
		return;

	}
	if (present_node + 6 - visited_num == num.size()) {
		for (int i = 0; i < present_node; i++) {
			if (num[i].is_visited) printf("%d ", num[i].num);
		}
		for (int i = present_node; i < num.size(); i++) printf("%d ", num[i].num);
		printf("\n");
		return;
	}

	num[present_node].is_visited = true;
	print_all(num, visited_num + 1, present_node + 1);
	num[present_node].is_visited = false;
	print_all(num, visited_num, present_node + 1);





}


int main() {

	int tmp = 0, k = 0;
	vector<node> num;



	while (1) {
		cin >> k;
		if (!k) break;
		for (int i = 0; i < k; i++) {
			scanf("%d", &tmp);
			num.push_back(node{ tmp,false });
		}


		print_all(num, 0, 0);
		printf("\n");
		num.clear();


	}








	return 0;
}