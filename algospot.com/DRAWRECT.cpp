
// https://algospot.com/judge/problem/read/DRAWRECT

#include <iostream>

using namespace std;


int main(void) {


	size_t test_case;
	cin >> test_case;

	for (size_t i = 0; i < test_case; i++)
	{
		int x[3];
		int y[3];
		int myx;
		int myy;
		for (size_t j = 0; j < 3; j++) {
			cin >> x[j];
			cin >> y[j];
			
			
		}
		if (x[0] == x[1]) {
			myx = x[2];
		}
		else if (x[1] == x[2]) {
			myx = x[0];
		}
		else myx = x[1];

		if (y[0] == y[1]) {
			myy = y[2];
		}
		else if (y[1] == y[2]) {
			myy = y[0];
		}
		else myy = y[1];

		cout << myx << " " << myy << endl;
		

	}


	//system("pause");





	return 0;
}
