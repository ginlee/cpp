#include <stdio.h>

void move(int n, char x, char y, char z){
	if (1 == n){
		printf("%c --> %c\n", x, z);
	}
	else{
		move(n-1, x, z, y);//move n-1 plates to z by y
		printf("%c --> %c\n", x, z);//move n plates to z from x
		move(n-1, y, x, z);//move n-1 plates to z from y by x
	}
}

int main(){
	int n;
	printf("Please enter Hanoi tower layers\n");
	scanf("%d", &n);
	printf("The move steps are like below:\n");
	move(n, 'x', 'y', 'z');
}