#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <sstream>

using namespace std;

int mod(string s, int p)
{

	int ret = 0;
	for (int i = 0; i<s.size(); i++) ret = (ret * 10 + (s[i] - '0')) % p;
	return ret;
}


int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string p, tmp,kk;
	int k;
	int is_good = 1;
	int ex;
	getline(cin, tmp);

	stringstream ss(tmp);
	ss >> p;
	ss >> kk;
	k = stoi(kk);

	vector<int>is_deleted(k + 1, 0);
	vector<int>sosu;

	for (int i = 2; i < k; i++) {

		if (!is_deleted[i]) {
			sosu.push_back(i);
			int start = 1;
			while (i*start <= k) {
				if (!is_deleted[i*start]) {
					is_deleted[i*start] = 1;
					
				}
				start++;
			}
		}
		else continue;
	}
	for (auto& n : sosu) {
		if (mod(p, n) == 0) {
			is_good = 0;
			ex = n;
			break;
		}
	}
	if (is_good) cout << "GOOD" << '\n';
	else cout << "BAD " << ex << '\n';


	return 0;
}