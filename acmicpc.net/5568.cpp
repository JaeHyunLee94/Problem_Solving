#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>



using namespace std;

void findd(set<string>& my, vector<int>& num,string now,int k) {
	if (k==0) {
		my.insert(now);
		return;
	}

	for (auto& n : num) {
		vector<int> next = num;
		vector<int>::iterator iter = next.begin();
		while (iter != next.end()) {
			if (*iter == n) {
				iter = next.erase(iter);
				break;
			}
			else iter++;
			
		}

		findd(my, next, now+to_string(n), k - 1);

	}

}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);



	int n, k;

	cin >> n >> k;
	string tmp;
	vector<int> num(n);
	for (int i = 0; i < n; i++) {
		int val;
		cin >> val;
		num[i] = val;
	}
	set<string> my;
	findd(my, num, tmp, k);
	cout << my.size();

	return 0;
}