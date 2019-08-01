#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long X, Y, Z;
	cin >> X >> Y;
	Z = ((100 * Y) / X);

	if (99 * X - 100 * Y <= 0) cout << -1 << '\n';

	else if (Z >= 99) cout << -1 << '\n';

	else {
		long long ans = (X*(Z + 1) - 100 * Y) / (99 - Z);
		if ((X*(Z + 1) - 100 * Y) % (99 - Z) == 0) cout << ans << '\n';
		else cout << ans+1<< '\n';
	}

	system("pause");





	return 0;
}