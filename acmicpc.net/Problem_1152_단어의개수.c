

//https://www.acmicpc.net/problem/1152

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//문자열에서 단어의 개수 찾기!! 
char* move_index(char str[],int* index){
	int i=0; char* tmp=str;
	
	while(*(str+i)!='\n'&&*(str+i)!=' '){
		
		
		i++;
	}
	tmp=str+(i-1); *index=*index+i-1;
	
	return tmp;
}


int num_of_word(char str[]){
	int num=0; int i=0;
	char* ptr=str;
	
	while(*(str+i)!='\n'){
		if(*(str+i)!=' '){
		ptr=move_index(ptr,&i);
		num=num+1;
		i++;
		ptr=ptr+1;
		}
		else if(*(str+i)==' '){
		ptr=ptr+1;
		i++;
		}
	}
			
	return num;
}

int main(int argc, char*argv[]){
	
	char str[1000];
	
	fgets(str,sizeof(str),stdin);
	
	printf("number of word : %d", num_of_word(str)); 
	
	return 0;
}
