

// DOMIAN: https://algospot.com/judge/problem/read/BOGGLE

#include <iostream>
#include <vector>
#include <string>


using namespace std;
int call_Stack = 0;

int ispromising(const char matrix[5][5], string tofind, int startx, int starty) {

	int x_min = startx - 1 >= 0 ? startx - 1 : 0;
	int x_max = startx + 1 <= 4 ? startx + 1 : 4;
	int y_min = starty - 1 >= 0 ? starty - 1 : 0;
	int y_max = starty + 1 <= 4 ? starty + 1 : 4;

	if (tofind.size() == 1) {
		return matrix[starty][startx] == tofind[0];
	}

	if (matrix[starty][startx] == tofind[0]) {

		for (int i = y_min; i <= y_max; i++) {
			for (int j = x_min; j <= x_max; j++) {
				if (matrix[i][j] == tofind[1] && !(i == starty && j == startx)) {
					return 1;
				}

			}
		}

	}

	return 0;
}

int canfind(const char matrix[5][5], string tofind, int num_left, int startx, int starty) {



	if (matrix[starty][startx] != tofind[0]) {
		return 0;
	}

	if (num_left == 1 ) {
		return 1;
	}


	int x_min = startx - 1 >= 0 ? startx - 1 : 0;
	int x_max = startx + 1 <= 4 ? startx + 1 : 4;
	int y_min = starty - 1 >= 0 ? starty - 1 : 0;
	int y_max = starty + 1 <= 4 ? starty + 1 : 4;

	
		

	
		for (int i = y_min; i<=y_max; i++) {
			for (int j = x_min; j<=x_max; j++) {
				if (canfind(matrix, tofind.substr(1), num_left - 1, j, i)==1 && !(i == starty && j == startx)) {
					
					return 1;
				}

			}
		}

		return 0;
		

	



}

int main(void) {

	int test_case, string_num;
	char matrix[5][5];

	cin >> test_case;

	for (int i = 0; i<test_case; i++) {

		for (int j = 0; j<5; j++) {
			for (int k = 0; k<5; k++) {
				cin >> matrix[j][k];
			}
		}

		cin >> string_num;
		vector<string> ob_string;
		ob_string.reserve(string_num);
		vector <bool> yes_or_no(string_num, false);

		cin.ignore();

		for (int j = 0; j<string_num; j++) {
			string tmp;
			getline(cin, tmp);
			ob_string.push_back(tmp);
		}
		for (int i = 0; i<string_num; i++) {
			for (int j = 0; j<5; j++) {
				for (int k = 0; k<5; k++) {
					if (canfind(matrix, ob_string[i], ob_string[i].size(), k, j)) {
						yes_or_no[i] = true;
					}
				}
			}
		}
		for (int i = 0; i<string_num; i++) {
			if (yes_or_no[i]) cout << "YES";
			else cout << "NO";

			cout << endl;
		}



	}


	return 0;
}
