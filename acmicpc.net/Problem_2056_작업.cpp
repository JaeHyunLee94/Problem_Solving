#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;




int main() {
		
	int n;
	int work, num, p_ver;
	cin >> n;

	vector < vector<int>> adj_list(n + 1);
	vector <int> work_time(n + 1, 0);
	vector <int> predecessor(n + 1, 0);
	vector<int> earliset_time(n + 1, 0);

	queue<int> ver;
	
	

	for (int i = 1; i < n + 1; i++) {
		scanf_s("%d %d", &work,&num);
		work_time[i] = work;
		predecessor[i] = num;
		for (int j = 0; j < num; j++) {
			scanf_s("%d", &p_ver);
			adj_list[p_ver].push_back(i);
		}
	
	}
	for (int i = 1; i < n + 1; i++) {
		if (!predecessor[i]) {
			ver.push(i);
			earliset_time[i] = work_time[i];
		}
	}
	int on_process;
	while (!ver.empty()) {

		on_process = ver.front();
		ver.pop();
		for (auto& n : adj_list[on_process]) {
			predecessor[n]--;
			if (!predecessor[n]) {
				ver.push(n);
			}
			if (earliset_time[n] <= earliset_time[on_process] + work_time[n]) {
				earliset_time[n] = earliset_time[on_process] + work_time[n];
			}
		}



	}

	cout<< *max_element(earliset_time.begin(), earliset_time.end());



	system("pause");
	return 0;
}