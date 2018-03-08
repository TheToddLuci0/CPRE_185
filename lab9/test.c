#include <stdio.h>
#include <math.h>
#include <ncurses/ncurses.h>
#include <unistd.h>
#include <time.h>
#include <stdbool.h>
#include <stdlib.h>

// Mathematical constants
#define PI 3.14159

// Screen geometry
// Use ROWS and COLS for the screen height and width (set by system)
// MAXIMUMS
#define COLMS 100
#define ROWS 80

// Character definitions taken from the ASCII table
#define AVATAR 'A'
#define WALL '*'
#define EMPTY_SPACE ' '

int main(int argc, char* argv[]){
	int difficulty = 4;
	int t, b1, b2, b3, b4, b5, slider;
	int cycles = 0;
	int fallen = 1;
	int y = COLMS/2;
	int oldY, oldFall;
	double ax, ay, az;
	//double buffArr[NUM_SAMPLES];
	bool lastState = 0;
	/*srand(time(NULL));
	int i, j;
	for(i=0; i<COLMS; i++){
		for(j=0; j<ROWS; j++){
			printf("%d\n", ((rand() % 100) % (100 - difficulty)));
				

}
}*/
	while (b1 ==0){
		scanf("%d, %lf, %lf, %lf, %d, %d, %d, %d, %d, %d", &t, &ax, &ay, &az, &b1, &b2, &b3, &b4, &b5, &slider );
		printf("%lf, %lf, %lf\n", ax, ay, az);
	}
return 0;	

}