/* Lab 5 Wrapper Program */

#include <stdio.h>
#include <math.h>
#include <stdbool.h>

#define TRUE 1

/* Put your lab 4 functions prototypes here, as well as the prototype for lab 5 */
double mag(double x, double y, double z);
double close_to(double tolerance, double point, double value);
int millis (int t);
int minutes (int t);
int seconds (int t);
double direction(double ax, double ay, double az);

int main(void) {
	int t, b1, b2, b3, b4, b5, s;
	double ax, ay, az; 	
	double tolerance, point, value;
	bool moving = 0;
	int lastTrue = 1;
	tolerance = .1;
	point = 1;

	while (TRUE) {
	
		scanf("%d, %lf, %lf, %lf, %d, %d, %d, %d, %d, %d", &t, &ax, &ay, &az, &b1, &b2, &b3, &b4, &b5, &s );	
			value = mag(ax, ay, az);
			moving = close_to(tolerance, point, value);
			int dir = direction(ax, ay, az);
			if (b2 == 1){
				return 0;
			}

			
			if ((dir != lastTrue) && moving == 0){
				
				printf("The current side facing up at %d minutes, %d seconds, and %d milliseconds is ", minutes(t), seconds(t), millis(t));
				switch (dir){
					case 1:
					printf("Top\n");
					break;
					case 2:
					printf("Bottom\n");
					break;
					case 3:
					printf("Front\n");
					break;
					case 4:
					printf("Back\n");
					break;
					case 5:
					printf("Right\n");
					break;
					case 6:
					printf("Left\n");
					break;
					default:
					printf("ERROR_SWITCH");
					
				}

			
				lastTrue = dir;
			}
			
	}


    return 0;
}

/* Put your lab 4 functions here, as well as your new function close_to */

double mag(double x, double y, double z){
	
	double magnatude = sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));

	return (magnatude);
}

double close_to(double tolerance, double point, double value){
	
	bool close;
	if ((value - tolerance) < point && (value + tolerance) > point){
		close = 0;
	}

	else{
		close = 1;
	}
	
	return (close);
	
}

int millis (int t){
	int mil = t % 60000;
	mil = mil % 1000;
return (mil);
}

int minutes (int t){
	int minute = t / 60000;
return (minute);
}

int seconds (int t){
	int sec = t % 60000;
	sec = sec / 1000;
return (sec);
}

double direction(double ax, double ay, double az){
	int direction;
	if((az > ax && az > ay) && az > 0) {
		direction = 1;
	}
	else if ((az < ax && az < ay) && az < 0){
		direction = 2;
	}
	else if ((ay < ax && ay < az) && ay < 0){
		direction = 3;
	}
	else if ((ay > ax && ay > az) && ay > 0){
		direction = 4;
	}
	else if ((ax < ay && ax < az) && ax < 0){
		direction = 5;
	}
	else if ((ax > ay && ax > az) && ax > 0){
	direction = 6; 
	}
	else {
		printf("ERROR_DIRECTION\n");
	}
return (direction);
}