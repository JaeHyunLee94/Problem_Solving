#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>

using namespace std;

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);



	int N;
	string tmp;
	cin >> N;
	vector<int> Stack;
	
	getline(cin, tmp);

	for (int i = 0; i < N; i++) {
		string inp;
		getline(cin,inp);
		stringstream ss(inp);
		string command;
		ss >> command;
		if (command == "push") {
			string to_pushstr;
			int to_push;
			ss>> to_pushstr;
			to_push = stoi(to_pushstr);
			Stack.push_back(to_push);
		}
		else if (command == "pop") {
			if (Stack.empty()) cout << -1 << '\n';
			else {
				cout << Stack.back() << '\n';
				Stack.pop_back();
			}

		}
		else if (command == "top") cout << (Stack.empty() ? -1 : Stack.back()) << '\n';
		else if (command == "size") cout << Stack.size() << '\n';
		else cout << (Stack.empty() ? 1 : 0)<< '\n';
	}






	system("pause");




	return 0;
}