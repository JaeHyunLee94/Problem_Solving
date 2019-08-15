#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

string flip_grid(string init) {

	if (init.size() == 1 && init[0] == 'b') return "b";
	else if (init.size() == 1 && init[0] == 'w') return "w";
	
	if (init[0] == 'x') {
		int second_end_inx = 2, third_end_inx = 3, fourth_end_inx = 4;
		int first_inx = 1;
		int second_inx = 1;
		int third_inx = 1;
		int fourth_inx = 1;
		while (second_end_inx != second_inx) {
			if (init[second_inx] == 'x') second_end_inx += 4;
			second_inx++;

		}
		while (third_end_inx != third_inx) {
			if (init[third_inx] == 'x') third_end_inx += 4;
			third_inx++;

		}
		while (fourth_end_inx != fourth_inx) {
			if (init[fourth_inx] == 'x') fourth_end_inx += 4;
			fourth_inx++;

		}

		string first(init.begin() + 1, init.begin() + second_end_inx);
		string second(init.begin() + second_end_inx, init.begin() + third_end_inx);
		string third(init.begin() + third_end_inx, init.begin() + fourth_end_inx);
		string fourth(init.begin() + fourth_end_inx, init.end());
		return "x" + flip_grid(third) + flip_grid(fourth) + flip_grid(first) + flip_grid(second);
	}
	else {
		string front(init.begin() , init.begin()+1);
		string back(init.begin() + 1, init.end() );
		return  front+flip_grid(back);
	}
	



}


int main() {



	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int test_case;
	cin >> test_case;
	for (int t = 1; t <= test_case; t++) {

		string init;
		cin >> init;


		cout << flip_grid(init) << '\n';






	}










	return 0;
}