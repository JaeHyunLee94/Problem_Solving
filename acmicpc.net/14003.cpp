#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

long long _lower_bound(const vector<long long>& arr,long long start, long long end, long long target)
{
	long long mid;

	while (start < end)
	{
		mid = (start + end) / 2;

		if (arr[mid] < target)
			start = mid + 1;

		else
			end = mid;
	}

	return end + 1;
}




int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long N;
	long long index = 0;
	long long ans = 0;
	cin >> N;

	vector<long long>arr(N);
	vector<long long>vv;
	vector < pair <long long,long long >> answer(N);
	vector<long long> aa;
	for (long long i = 0; i < N; i++) {
		long long tmp;
		cin >> tmp;
		arr[i] = tmp;
	}
	vv.push_back(arr[0]);
	answer[0].first = 0;
	answer[0].second = arr[0];
	for (long long i = 1; i < N; i++) {
		if (arr[i] > vv.back()) {
			vv.push_back(arr[i]);
			answer[i].first = vv.size()-1;
			answer[i].second = arr[i];
			ans++;
		}
		else {
			
			long long inx = _lower_bound(vv,0,vv.size()-1,arr[i] );
			vv[inx-1] = arr[i];
			answer[i].first = inx-1;
			answer[i].second = arr[i];
		}

	
	}
	long long t = ans;
	cout << ans + 1 << '\n';
	for (long long i = N-1; i >= 0; i--) {
		if (answer[i].first == t) {
			aa.push_back(arr[i]);
			t--;
		}


	}
	while (!aa.empty()) {
		cout << aa.back() << " ";
		aa.pop_back();

	}
	

	return 0;
}
