#include <iostream>
#include <vector>
#include <string>
// https://algospot.com/judge/problem/read/ENDIANS

/*

��Ʈ ������!!!
������ >> �� �ý��ۿ� ���� ������ ���� ���� ����!!!!!!!!!!!!
%2�� �������� ��Ʈ 0���� �����!!!!!!!!!!!!!

*/
using namespace std;


int main(void) {
	

	int test_case;
	cin >> test_case;
	vector <size_t> my;
	for (int i = 0; i < test_case; i++) {
		size_t tmp;
		cin >> tmp;
		my.push_back(tmp);
		

	}
	for (int i = 0; i < test_case; i++) {
		size_t tmp = my[i];
		size_t m1 = tmp%256 << 24;
		size_t m2 = (tmp >> 8) % 256 <<16;
		size_t m3 = (tmp >> 16) % 256 << 8;
		size_t m4 = (tmp>>24)%256 ;

		cout << m1 + m2 + m3 + m4 << endl;



	}

	//system("pause");

	return 0;
}
