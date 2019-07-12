#include <cstdio>
#include <algorithm>
#include<iostream>
#include <vector>
#include <set>
using namespace std;

int power(int a, int b) {
	int tmp = 1;
	for (int i = 0; i < b; i++) {
		tmp *= a;
	}
	return tmp;
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	int N;
	int K;
	//freopen("input.txt", "r", stdin);
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> N >> K;
		vector<int> table;
		set<int> my;
		char tmp = 0;
		for (int j = 0; j < N; j++) {
			cin >> tmp;
			if (tmp >= 48 && tmp < 58) table.push_back(tmp - 48);
			else table.push_back(tmp - 55);
		}

		for (int i = 0; i < N; i++) {
			int tmp = 0;
			for (int j = 0; j < N / 4; j++) {
				tmp += table[(i + j) % N] * power(16, N / 4 - j - 1);
			}
			my.insert(tmp);


		}
		vector<int> se(my.begin(), my.end());
		sort(se.begin(), se.end());

		cout << "#" << test_case << " " << *(se.end() - K) << endl;


	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}