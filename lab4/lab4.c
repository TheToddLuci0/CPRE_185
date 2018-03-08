/* Lab 4 Wrapper Program */

#include <stdio.h>
#include <math.h>

#define TRUE 1

/* Put your function prototypes here */
double mag(double x, double y, double z);
int minutes (int t);
int seconds (int t);
int millis (int t);

int main(void) {
    /* DO NOT MODIFY THESE VARIABLE DECLARATIONS */
	int t;
	double  ax, ay, az; 	


	while (TRUE) {
		scanf("%d,%lf,%lf,%lf", &t, &ax, &ay, &az);	

/* CODE SECTION 0 */
		double sec = (double) t/1000;
		printf("Echoing output: %8.3lf, %7.4lf, %7.4lf, %7.4lf\n", sec, ax, ay, az);

/* 	CODE SECTION 1 
		printf("At %d ms, the acceleration's magnitude was: %lf\n", 
			t, mag(ax, ay, az));  */
/* 	CODE SECTION 2 
		printf("At %d minutes, %d seconds, and %d milliseconds it was: %lf\n", 
		minutes(t), seconds(t), millis(t), mag(ax,ay,az)); 
*/
	}

return 0;
}

double mag(double x, double y, double z){
	
	double magnatude = sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));

	return (magnatude);
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

int millis (int t){
	int mil = t % 60000;
	mil = mil % 1000;
return (mil);
}
/* Put your functions here */


