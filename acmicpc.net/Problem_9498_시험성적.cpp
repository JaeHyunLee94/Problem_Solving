
//https://www.acmicpc.net/problem/9498

#include <iostream>


int main(void) {

	int data;
	std::cin >> data;
	if (data > 89 && data < 101) {
		std:: cout << 'A';
	}
	else if (data < 90 && data>79) {
		std::cout << 'B';
	}
	else if (data < 80 && data>69) {
		std::cout << 'C';
	}
	else if (data < 70 && data>59) {
		std::cout << 'D';
	}
	else {
		std::cout << 'F';
	}
	
	return 0;
}
