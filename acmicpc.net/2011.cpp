#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

string now;

int find_w(int i,vector<int>& DP) {

	if (DP[i] != -1) return DP[i];
	if (now[i] == '0') return DP[i] = 0;

	if (i == now.size() - 1) {
		if (now[i] > '0' && now[i] <= '9') return 1;
		else return 0;
	}
	
	if (i == now.size() - 2) {
		int sec = (now[i] - '0') * 10 + now[i + 1] - '0';
		if (sec > 26 || sec == 10 || sec == 20)return 1;
		else if (sec > 10 && sec <= 26) return 2;
		else return 1;
	}
	
	int second = (now[i]-'0') * 10 + now[i+1]-'0';

	int& ret = DP[i];
	ret = 0;

	ret += (find_w(i + 1,DP)%1000000);
	ret = ret % 1000000;
	if (second <= 26) ret += (find_w(i + 2, DP))%1000000;
	ret = ret % 1000000;
	return ret;

}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	
	cin >> now;

	vector<int>DP(now.size(), -1);


	cout << find_w(0, DP) % 1000000;



	return 0;
}