

//https://algospot.com/judge/problem/read/PICNIC

#include <iostream>
#include  <vector>

int num_ways = 0;


using namespace std;
/*
��� ȣ�⿡�� �Լ��� ����!! �Լ��� �κ� ������ �ذ��ϱ� ���� ����!!!!
����� �� ��ġ�� �� ���!!! ���� �ű��
ģ������?!!!---> �Ҹ��� �迭�� �����ϸ� ������ ����,,,,

�ʱ����� �� �����ϱ�!!-- >���ϴ� ���� ���� �Ǿ��°�? 
1.���ϴ� ������ ���� ����Ǿ �ʰ� ���� �Ǿ �ȉ�!!
2.���� Ž������ ������ ���°� ����Ǿ�� ��!!

*/




void findways(size_t child[][2],size_t size,size_t left) {
	
	if (size == 0) return;
	else if (size == 1&&left==1) {
		num_ways++;
		return;
	}


	for (size_t i = 0; i < size; i++){

		size_t iter = 0;
		size_t next_child[90][2] = { 0, };
		for (size_t j = i+1; j < size; j++)
		{
			if (!(child[j][0] == child[i][0] || child[j][0] == child[i][1] || child[j][1] == child[i][0] || child[j][1] == child[i][1])) {
				next_child[iter][0] = child[j][0];
				next_child[iter][1] = child[j][1];
				iter++;
			}
		}

		findways(next_child, iter,left-1);

	}
	

}


int main(void) {

	size_t test_case;
	cin >> test_case;

	for (size_t i = 0; i < test_case; i++) {
		size_t child_num;
		size_t pair_num;

		cin >> child_num;
		cin >> pair_num;
		size_t children[90][2];
		for (size_t j = 0; j < pair_num; j++) {

			cin >> children[j][0];
			cin >> children[j][1];

		}
		findways(children, pair_num,child_num/2);

		cout << num_ways<<endl;
		num_ways = 0;
		

	}


	return 0;
}
