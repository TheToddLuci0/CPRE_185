// Lab 10 ExTalker Skeleton Code

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <ncurses/ncurses.h>
#include <ncurses.h>
#include <unistd.h>
#include <time.h>
#include <stdbool.h>
#include <math.h>
#define TRUE 1
#define MAXWORDS 100
#define WORDLEN 11
#define DEBUG 0   // set to 0 to disable debug output

// reads words from the file
// into wl and trims the whitespace off of the end
// DO NOT MODIFY THIS FUNCTION
int readWords(char* wl[MAXWORDS], char* filename); 

//modifies s to trim white space off the right side
// DO NOT MODIFY THIS FUNCTION
void trimws(char* s) ;

int main(int argc, char* argv[]) {
	char* wordlist[MAXWORDS];
	int wordCount;
	int i, j, dist, row, col, timer, oldRow, oldDist;
	int* lastMove;
	int t, db, ub, lb, rb, jb, slider, dj, uj, lj, rj, xmag, ymag;

	wordCount = readWords(wordlist, argv[1]);

	if (DEBUG) {
		printf("Read %d words from %s \n",wordCount, argv[1]);
		for (i = 0; i< wordCount; i++) {
			printf("%s,", wordlist[i]);

			}
		printf("\n");
		}

// most of your code goes here. Don't forget to include the ncurses library 
	
	initscr();
	dist = 2;
	i=0;
	j=0;
	row = 0;
	col = 0;
	while (i<wordCount){
		
		mvprintw(row, dist, "%s", wordlist[i]);
		col++;
		dist = dist + 10;
		if (col == 5){
			row++;
			col = 0;
			dist = 2;
		}
		i++;
		refresh();
	}
	refresh();
	
	dist = 1;
	i=0;
	j=0;
	row = 0;
	col = 0;
	bool RTRUE, WORDADDED = 0;
	char sentance[1000];
	char sentWords[1000][10];
	int sentMods[1000];
	char cover[1000];
	int modNum = 0;
	char oldSentance[4][1000];
	int wordNum = 0;
	int* lastTrue;
	int timer2 = 0;
	int tempLen, over=0;
	int numToPrint=0;
	int* tempSpot;
	
	for (i=0; i<4; i++){
		strcpy(oldSentance[i],"\0");
	}
	for (i=0; i<1000; i++);
	{
		cover[i] = ' ';
	}
		mvprintw(26,0,cover);
		refresh();

	while (TRUE){
		scanf("%d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d", &t, &db, &ub, &lb, &rb, &jb, &slider, &dj, &uj, &lj, &rj, &xmag, &ymag);
//Beginning of selection indicator movement----------------------------------------------------
		mvprintw(row, dist, ">");
		if(dj==1 && (lastMove != &dj && timer == 0) && row < 25){
			row++;
			timer = 1;
		}
		if(uj==1 && (lastMove != &uj && timer == 0) && row > 0){
			row--;
			timer = 1;
		}
		if(lj==1 && lastMove != &lj && timer == 0 && col > 0 ){
			col--;
			dist = dist - 10;
			timer = 1;
		}
		if(rj==1 && (lastMove != &rj && timer == 0) && col < 4 ){
			col++;
			dist = dist + 10;
			timer = 1;
		}
		if (timer != 0){
			timer++;
			if (timer == 20){
				timer = 0;
				lastMove = NULL;
			}
		}
		if (oldDist != dist || oldRow != row){
			mvprintw(oldRow, oldDist, " ");
		}
		oldDist = dist;
		oldRow = row;
		refresh();
//end of selection indicator movement-------------------------------------------------------------
//Beginning of sentance manipulation

		wordNum = (row * 5) + col;
		if(rb == 1){
			RTRUE = 1;
		}
		
		if (ub == 1 && lastTrue != &ub){
			/*strcat(sentance, " ");
			strcat(sentance, wordlist[wordNum]);
			sentMods[modNum] = strlen(wordlist[wordNum]) + 1;
			lastTrue = &ub;
			timer2 = 1;
			modNum++;
			*/
			WORDADDED = 1;
			strcpy(sentWords[numToPrint], " ");
			mvprintw(27,0, sentWords[numToPrint]);
			numToPrint++;

			strcpy(sentWords[numToPrint], wordlist[wordNum]);
			if (RTRUE == 1){
				toupper(sentWords[numToPrint][0]);
				RTRUE=0;
			}
			
			numToPrint++;
			lastTrue = &ub;
			mvprintw(30, 0, "%d", ub);
			timer2 = 1;
		}
		else if (lb == 1 && lastTrue != &lb){
			/*strcat(sentance, " ");
			strcat(sentance, wordlist[wordNum]);
			sentMods[modNum] = strlen(wordlist[wordNum]) + 1;
			lastTrue = &ub;
			timer2 = 1;
			modNum++;
			*/
			WORDADDED = 1;
			strcpy(sentWords[numToPrint], wordlist[wordNum]);
			if (RTRUE == 1){
				toupper(sentWords[numToPrint][0]);
				RTRUE=0;
			}
			numToPrint++;
			lastTrue = &lb;
						timer2 = 1;

		}
		else if (db == 1 && lastTrue != &db && numToPrint > 0){
			//tempLen = strlen(sentance);
			/*for (i = sentMods[modNum-1] - 1; i>0; i--){
				mvprintw(26, tempLen - sentMods[modNum-1], " ");
			}
			sentance[tempLen-sentMods[modNum - 1]] = '\0';
			modNum--;
			*/
			numToPrint--;
			lastTrue = &db;
		}
		else if(jb == 1){
			numToPrint = 0;
			mvprintw(26, 0, cover);
						timer2 = 1;

		}
		/*
		switch to array of words, print each array term, i.e. arr0, arr1, arr2
		if delete, only print terms up to there, clear w/ spaces
		*/
		if(timer2 != 0){
			timer2++;
			if (timer2 == 200){
				timer2=0;
				lastTrue = NULL;
			}
		}		
		
		if(WORDADDED == 1){
			for(i=0; i<= numToPrint; i++){
				tempLen = strlen(sentWords[i]);
				
				strcat(sentance, sentWords[i]);
				mvprintw(27, over, sentWords[i]);
				mvprintw(40,0, "%d %d", numToPrint, i);
				over = over + tempLen;
			}
		

			//tempLen = strlen(sentance);
			//mvprintw(26, 0, sentance);
			//mvprintw(26, tempLen, cover);
			
			mvprintw(26, 0, "%s", sentWords);
			
			
			refresh();
		}

	}
	
	endwin();
	
    return 0;
	}

// DO NOT MODIFY THIS FUNCTION
void trimws(char* s) {
        int len = strlen(s) ;
        int x;
        if (len ==0) return;
        x = len-1;
        while (isspace(s[x]) && (x>=0)) {
                s[x] = '\0';
                x--;
                }
        }


// DO NOT MODIFY THIS FUNCTION
int readWords(char* wl[MAXWORDS], char* filename) {
	int numread =0;
	char line[WORDLEN];
	char *p;
	FILE* fp = fopen(filename,"r");
	while (!feof(fp)) {
		p  =fgets(line, WORDLEN, fp);
		if (!feof(fp) && p !=NULL) {
			trimws(line);
			wl[numread] = (char *)  malloc(strlen(line)+1);
			strcpy(wl[numread], line);
			numread++;
			}
		} 
	fclose(fp);
	return numread;	
	}
