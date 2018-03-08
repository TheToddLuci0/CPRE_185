#include <stdio.h>
#define TRUE 1

int millis (int t);

int main(int argc, char* argv[]){

while (TRUE){
double ax, ay, az;
int t;

scanf("%d, %lf, %lf, %lf", &t, &ax, &ay, &az);
int time = millis(t);

printf("%d, %lf, %lf, %lf\n", t, ax, ay, az);

printf("%d\n", millis(t));



}
return 0;
}
int millis (int t){
	int mil = t % 60000;
	mil = mil % 1000;
return (mil);
}