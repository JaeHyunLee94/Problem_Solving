#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	int N;
	cin >> N;
	
	vector<int> dp_now(3);
	vector<int> dp_pre(3);

	vector<int> dpmin_now(3);
	vector<int> dpmin_pre(3);

	int now1, now2, now3;
	cin >> now1 >> now2 >> now3;
	dpmin_now[0]= dp_now[0] = now1;
	dpmin_now[1] =dp_now[1] = now2;
	dpmin_now[2]= dp_now[2] = now3;
	for (int i = 1; i < N; i++) {
		dp_pre[0] = dp_now[0];
		dp_pre[1] = dp_now[1];
		dp_pre[2] = dp_now[2];

		dpmin_pre[0] = dpmin_now[0];
		dpmin_pre[1] = dpmin_now[1];
		dpmin_pre[2] = dpmin_now[2];
		
		cin >> now1 >> now2 >> now3;

		dp_now[0] = now1 + max(dp_pre[0], dp_pre[1]);
		dp_now[1] = now2 + max(dp_pre[0], max(dp_pre[1],dp_pre[2]));
		dp_now[2] = now3 + max(dp_pre[1], dp_pre[2]);

		dpmin_now[0] = now1 + min(dpmin_pre[0], dpmin_pre[1]);
		dpmin_now[1] = now2 + min(dpmin_pre[0], min(dpmin_pre[1], dpmin_pre[2]));
		dpmin_now[2] = now3 + min(dpmin_pre[1], dpmin_pre[2]);
	}

	cout << max(dp_now[0], max(dp_now[1], dp_now[2])) << " " << min(dpmin_now[0], min(dpmin_now[1], dpmin_now[2]));



	system("pause");





	return 0;
}