#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>

using namespace std;

int gcd(int a, int b) {
	if (a < b) swap(a, b);
	if (a%b == 0) return b;
	while (b != 0) {
		int tmp = a;
		a = b;
		b = tmp % b;
	}
	return a;
}



int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int a1, b1, a2, b2;
	cin >> a1 >> b1 >> a2 >> b2;

	int bunza = a1*b2 + b1*a2;
	int bunmo = b1*b2;
	int gcdd = gcd(bunza, bunmo);
	cout << bunza / gcdd << " " << bunmo / gcdd << '\n';


	return 0;
}