#include <stdio.h>
#include <math.h>
#include <stdbool.h>

#define TRUE 1

double mag(double x, double y, double z);
double close_to(double tolerance, double point, double value);

int main(int argc, char* argv[]){
	int t = 0;
	int startTime, endTime, second;
	int inputs = 0;
	int timing = 50;
	int timing2 = 25;
	double ax, ay, az, fallDist, fallTime;
	int cycles = 0;
	bool moving;
	bool moved = 0;
	bool complete = 0;
	double tolerance = .2;
	double value;
	double point = 1;
fallDist = 1;
fallTime = 1;
	scanf("%d, %lf, %lf, %lf", &t, &ax, &ay, &az);
	value = mag(ax, ay, az);
	if(t != 0){
		printf("ok, I'm now recieving data.\n");
	}
	else {
		printf("ERROR_NO_DATA");
		return 0;
	}
	
	while (TRUE){
		scanf("%d, %lf, %lf, %lf", &t, &ax, &ay, &az);
		inputs ++;
		value = mag(ax, ay, az);
		moving = close_to(tolerance, point, value);
		if(cycles == 0){
			printf("I'm waiting");
			cycles = cycles + 1;
		}
		
		else if (moving == 0 && cycles > 0 && moved == 0){
			if (inputs % timing == 0 && moved ==0){
				printf(".");
				cycles++;
			}
		}
		
		if (moving == 1 && moved == 0 && az < .8){
			printf("\n \n      Help me! I'm, falling");
			startTime = t;
			moved = 1;
		}
		else if (moving == 1 && moved == 1 && az < .8){
			if (inputs % timing2 == 0){
				printf("!");
			}
		}
		else if (moved == 1 && moving == 0){
			endTime = t;
			fallTime = endTime - startTime;
			fallTime = fallTime / 1000;
			fallDist = fabs(.5 * 9.8 * (fallTime * fallTime));
			printf("\n\n          Ouch! I fell %lf meters in %lf seconds.\n", fallDist, fallTime);
			return 0;
		}
	
	fflush(stdout);
	}
	return 0;
}

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
