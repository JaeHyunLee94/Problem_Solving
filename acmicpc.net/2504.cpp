#include <iostream>
#include <vector>
#include <algorithm>
#include <string>


using namespace std;



int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string inp;
	int weight = 1;
	int ans = 0;

	int is_proper = 1;
	cin >> inp;
	vector<char> stack;
	vector<char> check;
	for (auto& n : inp) {
		if (n == '(' || n=='[') check.push_back(n);
		else if (n == ')') {
			if (check.empty() || check.back() != '(') {
				is_proper = 0;
				break;
			}
			else check.pop_back();
			
		
		}
		else if (n == ']') {
			if (check.empty() || check.back() != '[') {
				is_proper = 0;
				break;
			}
			else check.pop_back();
		}
	}
	if (!check.empty()) is_proper = 0;

	if (!is_proper) {
		cout << 0 << '\n';
		system("pause");
		return 0;
	}
	else {
		for (auto& n : inp) {

			if (n == '(') {
				weight *= 2;
				stack.push_back(n);

			}
			else if (n == '[') {
				weight *= 3;
				stack.push_back(n);
			}

			else if (n == ')') {

				if (stack.back() == '(') ans += weight;


				weight /= 2;
				stack.push_back(n);

			}

			else if (n == ']') {

				if (stack.back() == '[') ans += weight;
				weight /= 3;
				stack.push_back(n);
			}
		}

		cout << (weight == 1 ? ans : 0) << '\n';
	}

	




	system("pause");






	return 0;
}