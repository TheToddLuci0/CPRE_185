// LAB2-3.c
#include <stdio.h>

int main(int argc, char* argv[]){

	int x, y, z, vol;
	printf("Enter a width:");
	scanf("%d", &x);
	printf("Enter a height:");
	scanf("%d", &y);
	printf("Enter a depth:");
	scanf("%d", &z);
	vol = x*y*z;
	printf("A %d by %d by %d rectangular prisms volume is %d\n", x,y,z,vol);


	return 0;
}