#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <string>

using namespace std;




int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int M;
	cin >> M;
	int SET = 0;
	string command;
	for (int i = 1; i <= M; i++) {
	
		cin >> command;
		if (command == "add") {
			string t;
			cin >> t;
			int to_add = stoi(t);
			SET |=(1 << to_add);
		}
		else if (command == "remove") {
			string t;
			cin >> t;
			int to_remove = stoi(t);
			SET &= ~(1 << to_remove);
		}
		else if (command == "check") {
			string t;
			cin >> t;
			int to_check = stoi(t);
			cout <<((SET & (1 << to_check)) ? 1: 0 )<< '\n';
		}
		else if (command == "toggle") {
			string t;
			cin >> t;
			int to_toggle = stoi(t);
			SET ^= (1 << to_toggle);
		}
		else if (command == "all") {
			SET = ((1 << 21) - 1);
		}
		else {
			SET = 0;
		}

		

	}

	


	return 0;
}