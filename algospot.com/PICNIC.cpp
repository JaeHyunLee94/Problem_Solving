

//https://algospot.com/judge/problem/read/PICNIC

#include <iostream>
#include  <vector>

int num_ways = 0;


using namespace std;
/*
재귀 호출에서 함수의 역할!! 함수는 부분 문제를 해결하기 위한 조각!!!!
경우의 수 겹치는 것 고려!!! 순서 매기기
친구관계?!!!---> 불리언 배열에 저장하면 편했을 것을,,,,

초기조건 잘 검토하기!!-- >원하는 때에 종료 되었는가? 
1.원하는 때보다 빨리 종료되어도 늦게 종료 되어도 안됌!!
2.깊이 탐색에서 끝까지 가는게 보장되어야 함!!

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
