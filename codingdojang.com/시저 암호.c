#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 100

void caesar(int n, char str[]){
	int i=0;
	for(i=0;i<SIZE;i++){
		if(str[i]>=65&&str[i]<=90){
			str[i]=(str[i]-65+n)%26+65;
		}
		else if(str[i]>=97&&str[i]<=122){
			str[i]=(str[i]-97+n)%26+97;
		}
	}
}

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	char str[SIZE]; int n;
	printf("input n: ");
	scanf("%d",&n);
	fflush(stdin);
	printf("input string: ");
	fgets(str,SIZE,stdin);
	caesar(n,str);
	printf("converted string: %s",str);
	
	return 0;
}
