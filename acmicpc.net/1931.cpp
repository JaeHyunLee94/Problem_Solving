#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct node {
	int start;
	int end;
};

bool operator < (const node& a, const node& b) {
	if (a.end < b.end) return true;
	else if (a.end == b.end) return a.start < b.start;
	else return false;
}

int main() {


	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	vector<node> meeting(n);
	for (int i = 0; i < n; i++) {
		int start, end;
		cin >> start >> end;
		meeting[i] = node{ start,end };
	}

	sort(meeting.begin(), meeting.end());
	int before_index = 0;
	int answer = 1;
	for (int i = 1; i < meeting.size(); i++) {
		if (meeting[before_index].end <= meeting[i].start) {
			before_index = i;
			answer++;
		}
	}
	cout << answer;

	return 0;
}