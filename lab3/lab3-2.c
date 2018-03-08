#include <stdio.h>

int main(int argc, char* argv[]){

	int answerA, answerB, answerE, answerF, answerJ;
	double answerC, answerD, answerG, answerH, answerI, answerK;
	
	answerA = 6472+1752;
	printf("6472 + 1752 = %d\n", answerA);

	answerB = (6971*3925)-95;
	printf("(6971 * 3925) - 95 = %d\n", answerB);
	
	answerC = 79+12/5;
	printf("79 + 12 / 5 = %.2lf\n", answerC);
	
	answerD = 3640.0/107.9;
	printf("3640.0 / 107.9 = %.2lf\n", answerD);
	
	answerE = (22/3)*3;
	printf("(22 / 3) * 3 = %d\n", answerE);
	
	answerF = 22/(3*3);
	printf("22 / (3 * 3) = %d\n", answerF);
	
	answerG = 22/(3*3);
	printf("22 / (3 * 3) = %.2lf\n", answerG);
	
	answerH = 22/3*3;
	printf("22 / 3 * 3 = %.2lf\n", answerH);
	
	answerI = (22.0/3)*3.0;
	printf("(22.0 / 3) * 3.0 = %.2lf\n", answerI);
	
	answerJ = 22.0/(3*3.0);
	printf("22.0 / (3 * 3.0) = %d\n", answerJ);
	
	answerK = 22.0/3.0*3.0;
	printf("22.0 / 3.0 * 3.0 = %.2lf\n", answerK);
	
	
//Area = pi radius^2	
//Circumference = 2 pi r
	double pi = 3.14159265359;
	double circum = 23.567;
	double radius;
	double area;
	
	radius = circum / 2 /pi;		//To get the area, first solve for the radius
	area = pi * radius * radius;    //then solve using the area formula
	printf("The area of a circle with a circumference of %lf is %lf\n", circum, area);
	
	double feet = 14;
	double meters;
	
	meters = .3048 * feet; //Use the given converson factor to solve for meters
	printf("%lf feet is %lf meters.\n", feet, meters);
	
	
	double degF = 76;
	double degC;
	
	degC = (degF - 32) / 1.8; //Use the conversion formula to solve
	printf("%lf degrees Fahrenheit is %lf degrees Centigrade.\n", degF, degC);
	
	
	
	return 0;
}