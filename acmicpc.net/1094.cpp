#include <iostream>
#include <bitset>
#include <string>
using namespace std;


int main() {
	int n;
	cin >> n;	
	cout << bitset<7>(n).count();



	return 0;
}