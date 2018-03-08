/* Lab 4 Wrapper Program */

#include <stdio.h>
#include <math.h>

#define TRUE 1

/* Put your function prototypes here */
int TotalButtons (int a, int y, int x, int b, int L3);

int main(void) {
    /* DO NOT MODIFY THESE VARIABLE DECLARATIONS */
	int t;
	double  ax, ay, az; 	
	int a, y, x, b, L3, slider; //Variables for buttons defined as though buttons on an XBox controller for easy recolection
while (TRUE){
	scanf("%d,%d,%d,%d,%d,%d", &a, &y, &x, &b, &L3, &slider);
	printf("Number of buttons currently pressed = %d \n", TotalButtons(a, y, x, b, L3));
	fflush(stdout);
	
	
}

return 0;
}

int TotalButtons (int a, int y, int x, int b, int L3){
	int total = a + y + x + b + L3;
return (total);
}



