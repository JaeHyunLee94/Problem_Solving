#include <iostream>
#include <algorithm>
#include <string>






using namespace std;


int main() {

	int lookup_table[13] = { -1,31,28,31,30,31,30,31,31,30,31,30,31 };
	string yoil[7] = { "SUN","MON","TUE" ,"WED" ,"THU" ,"FRI" ,"SAT" };
	int x = 0, y = 0;
	int days = 0;
	cin >> x >> y;
	for (int i = 1; i < x; i++) {
		days += lookup_table[i];
	}
	days += y-1;

	cout << yoil[(days+1) % 7];






	return 0;
}