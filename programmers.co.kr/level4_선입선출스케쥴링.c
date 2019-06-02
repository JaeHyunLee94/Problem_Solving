

//DOMAIN: https://programmers.co.kr/learn/courses/30/lessons/12920?language=cpp



#include <stdio.h>
#include <stdlib.h>
#define SIZE 4
/*
ó���ؾ� �� �۾��� N���� ������̰� �̸� ó���ϱ����� CPU�� �ֽ��ϴ�. 
N���� �۾��� ��� ������ �۾��̶�� �����մϴ�.

�۾��� �����ϴ� CPU���� �������� �ھ �ִµ���. 
�ھ�� �� �۾��� �ɸ��� �ð��� �ٸ��ϴ�. 
�� �ھ�� �۾��� ������ �� �ھ ���� �۾��� �ٷ� ����, 
2�� �̻��� �ھ ���� ��� ���� �ھ���� ä���ݴϴ�. 
ó���ؾ� �� �۾��� ���� n��, �� �ھ��� ó�� �ð��� ��� �迭 core�� �־��� ��, 
������ �۾��� ���� �ھ��� ��ȣ�� ��ȯ���ִ� getCoreNumber �Լ��� �ϼ��ϼ���.

���� ��� �۾��� 6���̰�, CPU�� �ھ ó�� �ð��� [1,2,3] �̶�� 
ó�� 3���� �۾��� ���� 1,2,3���� ����, 
1�� �ð� �� 1�� �ھ 4��° �۾�, �ٽ� 1�� �ð� �� 1,2�� �ھ 5,6�� ° �۾��� ���Ƿ� 2�� 
��ȯ�� �ָ� �˴ϴ�.
*/

typedef struct cpu{
	int possible;
	int memory_size;
	int degree;
}CPU;

int getCoreNumber(int n,int msize[SIZE]){
	int i;
	CPU cpu[SIZE];
	for(i=0;i<SIZE;i++){
		cpu[i].degree=0;
		cpu[i].memory_size=msize[i];
		cpu[i].possible=1;
	}
	
	
	if(n<=SIZE){
		return n;
	}
	while(n>=0){
		
		for(i=0;i<SIZE;i++){
			if(cpu[i].possible==1){
				cpu[i].possible=0;
				n=n-1;
				if(n==0){
					return i+1;
				}
			}
		}//���� ���� �ֱ� 
		for(i=0;i<SIZE;i++){
			if(cpu[i].possible==0){
				cpu[i].degree=cpu[i].degree+1;
			}
		} //�ִ°� �ϳ��� ���� 
		for(i=0;i<SIZE;i++){
			if(cpu[i].degree>=cpu[i].memory_size){
				cpu[i].degree=0;
				cpu[i].possible=1;
			}
		} //�� �Ȱ� ��ȯ 
		
	}
}

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int i=0; int work_num;
	int cpu_msize[SIZE];
	
	while(1){
		printf("input work number: ");
		scanf("%d", &work_num);
		for(i=0;i<SIZE;i++){
			printf("input %d core memory size: ",i+1);
			scanf("%d", &cpu_msize[i]);
		}
		printf("last core number is: %d\n",getCoreNumber(work_num,cpu_msize));
	}
	return 0;
}
