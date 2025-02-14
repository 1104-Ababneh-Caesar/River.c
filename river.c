/*
 * Author: Caesar Ababneh
 * Date: 2/14/2025
 * Purpose: This is a text-based game I wrote a few
 * months ago. It's based on an old river-crossing riddle
 * I read about that I thought was interesting. Not
 * a lot of time was spent on the code, so it's a
 * bit of a disorganized mess.
 */

#include <stdio.h>

short int state = 1;
unsigned short int wolves = 0, sheep = 0;
const char number[4][6] = {"zero", "one", "two", "three"};

int count(short int x) {
	int a = x - ((state > 0) * 3);
	return a * ((a > 0) * 2 - 1);
}

void check() {
	if (count(wolves) > count(sheep) && count(sheep) > 0) {
		printf("\nYOU LOSE\nThe sheep you brought didn't have a chance, they were eaten on the boat.\n");
		state = 0;
	}
}

char error() {
	printf("\nI can't do that.\n");
	return '*';
}

int main() {
	printf("\nRIVER - BY CAESAR ABABNEH\nInput (q) at any time to quit.\n");
	printf("\nYou need to cross the river with all your animals.\nThe boat here can only hold two animals,\nYou need to have at-least one in the boat, when crossing the river.\nYou have three wolves and sheep.\nThe wolves can never out-number the sheep.\n");
	while (state) {
		printf("\nYou stand on ");
		if (state < 0) printf("the other");
		else printf("a");
		printf(" river-bank.\nNext to you are %s wolves and %s sheep.\n", number[count(wolves)], number[count(sheep)]);
		char in;
		do {
			printf("\nDo you want to send (w)olves, (s)heep, or (b)oth across? -->");
			scanf(" %c", &in);
			switch(in) {
				default:
					printf("I don't know what that is.\n");
					in = error();
				break;
				case 'q':
					state = 0;
				break;
				case 'w':
					printf("\n(o)ne or (t)wo? -->");
					scanf(" %c", &in);
					if (in == 't') {
						if (count(wolves) >= 2) wolves += 2 * state;
						else in = error();
					} else if (in == 'o') {
						if (count(wolves) > 0) wolves += state;
						else in = error();
					} else in = error();
				break;
				case 's':
					printf("\n(o)ne or (t)wo? -->");
					scanf(" %c", &in);
					if (in == 't') {
						if (count(sheep) >= 2) sheep += 2 * state;
						else in = error();
					} else if (in == 'o') {
						if (count(sheep) > 0) sheep += state;
						else in = error();
					} else in = error();
				break;
				case 'b':
					if (count(wolves) > 0&&count(sheep) > 0) {
						wolves += state;
						sheep += state;
					} else in = error();
				break;
			}
		} while (in == '*');
		check();
		if (in == 'r') state = 1;
		else state = 0 - state;
		check();
		if (sheep + wolves == 6) {
			printf("\nYOU WIN\nAll the animals were brought across the river safely.\n");
			state = 0;
		}

	}
	printf("\nThank you for playing!\n");
	return 0;
}