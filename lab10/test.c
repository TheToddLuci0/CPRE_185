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

int main(int argc, char* argv[]) {
	int t, db, ub, lb, rb, jb, slider, dj, uj, lj, rj, xmag, ymag;
		scanf("%d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d", &t, &db, &ub, &lb, &rb, &jb, &slider, &dj, &uj, &lj, &rj, &xmag, &ymag);
		printf("%d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d", t, db, ub, lb, rb, jb, slider, dj, uj, lj, rj, xmag, ymag);

}