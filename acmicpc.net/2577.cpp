#include <iostream>
#include <algorithm>
#include <vector>
#include <string>



using namespace std;


int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long a, b, c;

	long long res;

	cin >> a >> b >> c;
	res = a * b * c;
	string str_res = to_string(res);
	vector<int> ma(10, 0);

	for (auto& i : str_res) {
		ma[i - 48]++;
	}
	for (auto&  i:ma) 
	{
		cout << i << '\n';
	}















	return 0;
}