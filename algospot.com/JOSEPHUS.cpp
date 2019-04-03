
//https://algospot.com/judge/problem/read/JOSEPHUS

#include <iostream>

using namespace std;
/*
A a;
ptr=new A(1);
���ÿ� ���� �ƴϸ� ���� ���� ����

��������Ʈ�� <list> �� �̿��ؼ� ���� ������ ��߸� �����ϱ�

���������� �ش纯���� �̸����� lvalue ���� ���� �ؾ� ��!!


*/
class PERSON {
public:
	bool alive = true;
	int index = 1;
	PERSON* previous = nullptr;
	PERSON* next = nullptr;
	void die() {
		this->alive = false;
	}
	bool isalive() {
		return this->alive;
	}
	PERSON(int a) {
		this->index = a;
	}
};

PERSON* generate_circle(PERSON* start,int num) {
	start = new PERSON(1);
	PERSON* iter = start;
	for (int i = 0; i < num-1; i++) {
		iter->next = new PERSON(i + 2);
		iter->next->previous = iter;
		iter = iter->next;

	}
	iter->next = start;
	start->previous = iter;
	return start;
}

void dieuntill2(PERSON* start, int K, int num,int ans[2]) {
	int left = num;
	PERSON* iter = start;
	while (left > 2) {
		iter->die();
		left--;
		if (left == 2) break;
		for (int i = 0;i<K ; ) {
			if (iter->next->isalive()) {
				iter = iter->next;
				i++;
			}
			else iter = iter->next;
		}
	}
	int i = 0;
	for (iter = start->next; iter != start; iter = iter->next) {
		if (iter->isalive()&& i!=2) {
			ans[i] = iter->index;
			i++;
		}
		if (i == 2) {
			break;
		}
	}

}




int main(void) {

	int test_case;
	cin >> test_case;
	for (int i = 0; i < test_case; i++) {
		int N, K;
		int ans[2];
		cin >> N;
		cin >> K;
		PERSON* start = nullptr;
		start=generate_circle(start, N);
		dieuntill2(start, K, N, ans);
		cout << ans[0] << " " << ans[1] << endl;

	}
	return 0;
}
