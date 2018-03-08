// WII-MAZE Skeleton code written by Jason Erbskorn 2007
// Edited for ncurses 2008 Tom Daniels
//Updated for Esplora 2013 TeamRursch185


// Headers
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

// Number of samples taken to form an average for the accelerometer data
// Feel free to tweak this.  You may actually want to use the moving averages
// code you created last week 
#define NUM_SAMPLES 5  


// 2D character array which the maze is mapped into
char MAZE[COLMS][ROWS];


// POST: Generates a random maze structure into MAZE[][]
//You will want to use the rand() function and maybe use the output %100.  
//You will have to use the argument to the command line to determine how 
//difficult the maze is (how many maze characters are on the screen).
void generate_maze(int difficulty);

// PRE: MAZE[][] has been initialized by generate_maze()
// POST: Draws the maze to the screen 
void draw_maze(void);

// PRE: 0 < x < COLS, 0 < y < ROWS, 0 < use < 255
// POST: Draws character use to the screen and position x,y
void draw_character(int x, int y, char use);

// PRE: -1.0 < y_mag < 1.0
// POST: Returns tilt magnitude scaled to -1.0 -> 1.0
// You may want to reuse the pitch function written in previous labs.  
float calc_pitch(float y_mag);

// Functions from previous labs
void updatebuffer(double buffer[], int length, double new_item);
double avg(double buffer[], int num_items);
double close_to(double tolerance, double point, double value);
void draw(int y, int fallen, int* oldY, int* oldFall);


// Main - Run with './explore.exe -t -a -b' piped into STDIN
void main(int argc, char* argv[])
{

	int difficulty = 0;  
	if (argc>1) {
		sscanf(argv[1], "%d", &difficulty );
		printf("You entered a difficulty of %d\n", difficulty);
	}
	else {
		printf("Enter a difficulty on the command line\n");
		return;
	}
	if (difficulty <1 || difficulty >99) {
		printf("Invalid difficulty\n");
		return;
	}
	// setup screen    
	initscr();
	refresh();
	
	//Variable declarations
	int t, b1, b2, b3, b4, b5, slider;
	int sensitivity = 0;
	int cycles = 0;
	int fallen = 1;
	int y = COLMS/2;
	int oldY, oldFall;
	double ax, ay, az, average;
	double buffArr[NUM_SAMPLES];
	bool lastState = 0;

	// Generate and draw the maze, with initial avatar
	generate_maze(difficulty);
	draw_maze();
	draw_character((COLMS/2), 1, AVATAR);
	
	
	// Read accelerometer data to get ready for using moving averages.    
	do{
	scanf("%d, %lf, %lf, %lf, %d, %d, %d, %d, %d, %d", &t, &ax, &ay, &az, &b1, &b2, &b3, &b4, &b5, &slider );
	updatebuffer(buffArr, NUM_SAMPLES, ax);
	cycles ++;
	} while(cycles <= NUM_SAMPLES);
	
	
	// Event loop
	do
	{

		// Read data, update average
		scanf("%d, %lf, %lf, %lf, %d, %d, %d, %d, %d, %d", &t, &ax, &ay, &az, &b1, &b2, &b3, &b4, &b5, &slider );
		updatebuffer(buffArr, NUM_SAMPLES, ax);
		average = avg(buffArr, NUM_SAMPLES);
		// Is it time to fall?  if so, then move avatar
		if(t % 500 == 0 && lastState == 0 && MAZE[fallen + 1][y] != '*'){
			fallen++;
			lastState = 1;
		}
		else if(t % 500 != 0 && lastState == 1){
			lastState = 0;
		}
		
		//determine if esplora indicates to move left/right and if left/right is available
	if(average > .1 && MAZE[fallen][y-1] != '*' && y-1 >= 0 ){
		y--;
	}
	else if(average < -.1 && MAZE[fallen][y+1] != '*' && y+1 <= ROWS){
		y++;
	}
	
	//draw_character(y, fallen, AVATAR);
	if (MAZE[fallen][y+1] == '*' && MAZE[fallen][y-1] == '*' && MAZE[fallen+1][y] == '*'){
		endwin();
		printf("You lose!\n");
		return;
	}
	

		draw(y, fallen, &oldY, &oldFall);
		/*draw_character(y, fallen, AVATAR); //For Final, set to retutn to maze original
		if (oldY != y || oldFall != fallen){
			draw_character(oldY, oldFall, EMPTY_SPACE); // covers the space the avatar was
		}
		oldY = y;
		oldFall = fallen;	*/	
	
	} while(fallen != ROWS); // Change this to end game at right time 

	// Print the win message
	endwin();

		printf("YOU WIN!\n");
	
}



// PRE: 0 < x < COLS, 0 < y < ROWS, 0 < use < 255
// POST: Draws character use to the screen and position x,y
//THIS CODE FUNCTIONS FOR PLACING THE AVATAR AS PROVIDED.
//YOU DO NOT NEED TO CHANGE THIS FUNCTION.
void draw_character(int x, int y, char use)
{
	mvaddch(y,x,use);    
	refresh();
}

void draw(int y, int fallen, int* oldY, int* oldFall){
			draw_character(y, fallen, AVATAR);
		if (*oldY != y || *oldFall != fallen){
			draw_character(*oldY, *oldFall, EMPTY_SPACE); // covers the space the avatar was
		}
		*oldY = y;
		*oldFall = fallen;
	
	
}


void updatebuffer(double buffer[], int length, double new_item){
	int i;
	for (i=0; i<length - 1; i++){
		buffer[i] = buffer[i+1];
	}
	buffer[length-1] = new_item;
	return;
}


double avg(double buffer[], int num_items){
	double avg;
	double sum = 0;
	int i;
	
	for (i=0; i<num_items; i++){
		sum = buffer[i] + sum;
	}
	avg = (double)sum/num_items;
	return (avg);
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


void generate_maze(int difficulty){
	srand(time(NULL));
	int i, j;
	for(i=0; i<COLMS; i++){
		for(j=0; j<ROWS; j++){
			if ( ((rand() % 100) < difficulty)){
				MAZE[i][j] = WALL;
			}
			else {
				MAZE[i][j] = EMPTY_SPACE;
			}
			
		}
		
	}
	
return;	
}

void draw_maze(void){
	int i, j;
	for(i=0; i<COLS; i++){
		for(j=0; j<ROWS; j++){
			if (MAZE[i][j] == EMPTY_SPACE){
				mvaddch(i, j, EMPTY_SPACE);
			}
			else if(MAZE[i][j] == WALL){
				mvaddch(i, j, WALL);
			}
		}
	}
	return;
}