#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>


using namespace std;



int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	deque <pair<int,int>> qq;

	int N, L, tmp_val;
	cin >> N >> L;
	for (int i = 0; i < N; i++) {
		cin >> tmp_val;
		while (!qq.empty() && qq.back().first > tmp_val) {
			qq.pop_back();
		}
		qq.push_back(make_pair(tmp_val, i));

		if (i - qq.front().second+1 > L) qq.pop_front();


		cout <<  qq.front().first << " ";

	}




	system("pause");
	return 0;
}