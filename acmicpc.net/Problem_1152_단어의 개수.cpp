#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <sstream>
#define INT_MAX 2147483647
using namespace std;




int main() {
		string input;
		string str;
		vector<string> tmp;

	getline(cin, input);

	stringstream ss(input);

	while (ss >> str) {
		tmp.push_back(str);
	}




		cout << tmp.size() << endl;


	
	
	

	system("pause");
	return 0;
}