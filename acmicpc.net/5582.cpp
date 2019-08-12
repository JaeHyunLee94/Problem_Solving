#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>




using namespace std;




int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string str1, str2;

	cin >> str1 >> str2;
	int ans = 0;
	for (int i = 0; i < str1.size(); i++) {
		int start1 = i;
		int start2 = 0;
	
		int tmp_ans = 0;
		while (start1 < str1.size() && start2 < str2.size()) {
			int tmp_ans = 0;
			while (str1[start1] == str2[start2] && start1 < str1.size() && start2<str2.size()) {
				start1++;
				start2++;
				tmp_ans++;
			}
			if (tmp_ans > ans) ans = tmp_ans;
			start1++;
			start2++;

		}
	}
	for (int i = 0; i < str2.size(); i++) {
		int start1 = 0;
		int start2 =i;

		int tmp_ans = 0;
		while (start1 < str1.size() && start2 < str2.size()) {
			int tmp_ans = 0;
			while (str1[start1] == str2[start2] && start1 < str1.size() && start2<str2.size()) {
				start1++;
				start2++;
				tmp_ans++;
			}
			if (tmp_ans > ans) ans = tmp_ans;
			start1++;
			start2++;

		}
	}
	
	cout << ans;


	return 0;
}