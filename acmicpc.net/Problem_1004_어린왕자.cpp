
//https://www.acmicpc.net/problem/1004

#include <iostream>
using namespace std;



int main()
{
	int test_case;
	cin >> test_case;
	for (int i = 0; i <test_case; i++)
	{
		int start_x, start_y, end_x, end_y, num_of_stellar, answer;
		cin >> start_x;
		cin >> start_y;
		cin >> end_x;
		cin >> end_y;
		cin >> num_of_stellar;
		answer = 0;

		for (int j = 0; j < num_of_stellar; j++) {
			int tmp_x, tmp_y, tmp_radius;
			cin >> tmp_x;
			cin >> tmp_y;
			cin >> tmp_radius;
			int start = (tmp_x - start_x)*(tmp_x - start_x) + (tmp_y - start_y)*(tmp_y - start_y);
			int end= (tmp_x - end_x)*(tmp_x - end_x) + (tmp_y - end_y)*(tmp_y - end_y);
			if ((start - tmp_radius * tmp_radius)>0&& (end - tmp_radius * tmp_radius)<0) answer++;
			else if((start - tmp_radius * tmp_radius)<0 && (end - tmp_radius * tmp_radius)>0)answer++;
	
		}
		cout << answer << endl;


	}
	
	return 0;
}

