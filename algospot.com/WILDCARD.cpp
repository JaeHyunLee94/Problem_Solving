#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

string pattern;
string token;

int is_match(int i,int j,vector<vector<int>>& DP) {
	int& ret = DP[i][j];

	if (DP[i][j] != -1) return DP[i][j];

	ret = 0;

	if (i == pattern.size() - 1 || j == token.size() - 1) {
		if (i == pattern.size() - 1 && j != token.size() - 1) {
			return ret = 0;
		}

		else if (i != pattern.size() - 1 && j == token.size() - 1) {
			if (pattern[i] == '*') {
				return ret = is_match(i + 1, j, DP);
			}
			else return ret = 0;
		}
		else return ret = 1;
	}

		
	if (pattern[i] == '?' || pattern[i] == token[j]) return ret = is_match(i + 1, j + 1, DP);
	else if (pattern[i] == '*') {

		for (int k = j; k < token.size(); k++) {
			ret = ret || is_match(i + 1, k, DP);
		}
		return ret;
	}
	else return ret = 0;
}


int main() {


	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);



	int test_case;
	cin >> test_case;
	for (int t = 1; t <= test_case; t++) {
		

		cin >> pattern;
		pattern += '.';
		int n;
		cin >> n;
		vector<string> ans;
		for (int i = 0; i < n; i++) {
	
			cin >> token;
			token += '.';
			int N = pattern.size();
			int M = token.size();


			vector<vector<int>> DP(N, vector<int>(M, -1));

			if (is_match(0,0,DP)) ans.push_back(token);
			


		}
		sort(ans.begin(), ans.end());
		for (auto& n : ans) {
			n.pop_back();
		}
		for (auto& n : ans) cout <<n << '\n';




	}










	return 0;
}