#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>

using namespace std;
int main() {

	int N = 0, M = 0;

	cin >> N >> M;



	map <int, string> dogam;
	map <string,int> dogam2;

	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);



	for (int i = 1; i <= N; i++) {

		string tmp;
		cin >> tmp;
		dogam.insert(make_pair(i, tmp));
		dogam2.insert(make_pair(tmp, i));

	}

	for (int i = 1; i <= M; i++) {
		string tmp;
		
		cin >> tmp;
		if (tmp[0] >= 48 && tmp[0] <= 57)  cout << dogam[stoi(tmp)] << "\n";
		else cout << dogam2[tmp] << "\n";
			

		
	}














	return 0;




}