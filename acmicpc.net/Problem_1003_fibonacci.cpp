
//https://www.acmicpc.net/problem/1003

#include <iostream>
using namespace std;


int main()
{
	int test_case, fibo_num;

	int fibo_array[41][2];
	fibo_array[0][0] = 1;
	fibo_array[0][1] = 0;
	fibo_array[1][0] = 0;
	fibo_array[1][1] = 1;

	cin >> test_case;

	for (size_t i = 2; i < 41; i++)
	{
		fibo_array[i][0] = fibo_array[i - 1][0] + fibo_array[i - 2][0];
		fibo_array[i][1] = fibo_array[i - 1][1] + fibo_array[i - 2][1];

	}
	for (size_t i = 0; i < test_case; i++)
	{
		cin >> fibo_num;
		cout << fibo_array[fibo_num][0] << " " << fibo_array[fibo_num][1] << endl;

	}
	
	return 0;
}
