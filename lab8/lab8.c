#include <stdio.h>


#define MAXPOINTS 10000

// compute the average of the first num_items of buffer
double avg(double buffer[], int num_items);

//update the max and min of the first num_items of array
void maxmin(double array[], int num_items, double* max, double* min);

//shift length-1 elements of the buffer to the left and put the 
//new_item on the right.
void updatebuffer(double buffer[], int length, double new_item);


int main(int argc, char* argv[]) {
	
	/* DO NOT CHANGE THIS PART OF THE CODE */

	double x[MAXPOINTS], y[MAXPOINTS], z[MAXPOINTS];
	int lengthofavg = 0;
	if (argc>1) {
		sscanf(argv[1], "%d", &lengthofavg );
		printf("You entered a buffer length of %d\n", lengthofavg);
	}
	else {
		printf("Enter a length on the command line\n");
		return -1;
	}
	if (lengthofavg <1 || lengthofavg >MAXPOINTS) {
		printf("Invalid length\n");
		return -1;
	}


	
	/* PUT YOUR CODE HERE */
	int t, b1, b2, b3, b4, b5, slider;
	int cycles = 0;
	double ax, ay, az, minx, maxx, miny, maxy, minz, maxz, avex, avey, avez;
	//double arrx[lengthofavg];
	//double arry[lengthofavg];
	//double arrz[lengthofavg];

	do {
		scanf("%d, %lf, %lf, %lf, %d, %d, %d, %d, %d, %d", &t, &ax, &ay, &az, &b1, &b2, &b3, &b4, &b5, &slider );
		//printf("%d %lf %lf %lf\n", t, ax, ay, az);
		if (cycles < lengthofavg){
			updatebuffer(x, lengthofavg, ax);
			updatebuffer(y, lengthofavg, ay);
			updatebuffer(z, lengthofavg, az);
		}
		else if(cycles >= lengthofavg){
			updatebuffer(x, lengthofavg, ax);
			updatebuffer(y, lengthofavg, ay);
			updatebuffer(z, lengthofavg, az);
			
			avex = avg(x, lengthofavg);
			avey = avg(y, lengthofavg);
			avez = avg(z, lengthofavg);
			
			maxmin(x, lengthofavg, &minx, &maxx);
			maxmin(y, lengthofavg, &miny, &maxy);
			maxmin(z, lengthofavg, &minz, &maxz);
			int tempI;
			/*for(tempI = 0; tempI<lengthofavg; tempI++){
				printf("%lf", x[tempI]);
			}
			printf("\n");*/
			//printf("X:%lf Y:%lf Z:%lf AVEX:%lf AVEY:%lf AVEZ:%lf MINX:%lf MINY:%lf MINZ:%lf MAXX:%lf MAXY:%lf MAXZ:%lf \n", ax, ay, az, avex, avey, avez, minx, miny, minz, maxx, maxy, maxz);
			printf("%lf, %lf, %lf, %lf, %lf, %lf, %lf, %lf, %lf, %lf, %lf, %lf \n", ax, ay, az, avex, avey, avez, minx, miny, minz, maxx, maxy, maxz);

		}
		
		fflush(stdout);
		
		cycles++;
	} while (b3 == 0);
	
return 0;
}

// compute the average of the first num_items of buffer
double avg(double buffer[], int num_items){
	double avg;
	double sum = 0;
	int i;
	
	for (i=0; i<num_items; i++){
		sum = buffer[i] + sum;
	}
	avg = (double)sum/num_items;
//printf("IN_AVG\n");
	return (avg);
}

//update the max and min of the first num_items of array
void maxmin(double array[], int num_items, double* max, double* min){
	int i;
	*max = array[0];
	*min = array[0];
	for (i=0; i<num_items; i++){
		if(array[i] > *max){
			*max = array[i];
		}
		if(array[i] < *min){
			*min = array[i];
		}
//printf("min:%lf max:%lf ", *min, *max);
	}
//printf("\n");
//printf("IN_MINMAX\n");
	return;
}

//shift length-1 elements of the buffer to the left and put the 
//new_item on the right.
void updatebuffer(double buffer[], int length, double new_item){
	int i;
	double temp;
	for (i=0; i<length - 1; i++){
		buffer[i] = buffer[i+1];
	}
	buffer[length-1] = new_item;
//printf("IN_UPDATEBUFFER\n");
	return;
}
