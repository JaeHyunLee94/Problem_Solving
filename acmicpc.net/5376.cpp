 #include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

long long gcd(long long a, long long b)
{
	return b ? gcd(b, a % b) : a;
}

// Returns 10^n
long long poww(int n)
{
	long long power = 1ll;
	for (int i = 0; i < n; i++)
		power *= 10;
	return power;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	long long test_case = 0;
	cin >> test_case;

	for (int t = 1; t <= test_case; t++) {
		string tmp;
		cin >> tmp;
		int startp = 0, endp = 0;
		

		long long a1 = 0, b1 = 1, a2 = 0, b2 = 1;
		for (int i = 2; i < tmp.size(); i++) {

			if (tmp[i] == '(') {
				startp = i;
			
			}
			else if (tmp[i] == ')') {
				endp = i;
			}
		}
		string repeat;
		string non_repeat;
		if (startp) {
			non_repeat = string(tmp.begin()+2, tmp.begin()+startp);
			repeat = string(tmp.begin() + startp+1, tmp.begin() + endp);
		}
		else {
			non_repeat = string(tmp.begin()+2, tmp.end());
		}
		long long total = stoll(non_repeat + repeat);
		

		if (!repeat.empty()) {
			a2 = stoll(repeat);
			
		}
		if (!non_repeat.empty()) {
			a1 = stoll(non_repeat);
		}
		

		long long num = a2 ? total - a1 : a1;
		long long denom = repeat.size() ? poww(repeat.size() + non_repeat.size()) - poww(non_repeat.size()) : poww(non_repeat.size());
		
		long long gcdd = gcd(num, denom);
		cout << num/gcdd << "/" << denom/gcdd << '\n';




	}
	
	return 0;
}
