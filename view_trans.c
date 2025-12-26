#include <stdio.h>
#include <stdlib.h>
#include "view_functions/view_functions.h"
#include "functions.h"
#include <stdlib.h>
void view_menu(void);
void view_trans(void) {
	view_menu();
	char n = 'a';
	do {
		scanf_s("%c", &n, 1); 
		int c; while ((c = getchar()) != '\n' && c != EOF) {}
		if (n == 'A') {
			clear_screen();
			total_amounts();
		}
		else if (n == 'D') {
			clear_screen();
			search_by_date();
		}
		else if (n == 'K') {
			clear_screen();
			search_by_kind();
		}
		else if (n == 'B')
			run_menu1();
		else if (n == 'E')
			exit(1);
		else
			printf("please enter a correct alphabet \n");

	} while ((n != 'A') | (n != 'B') | (n != 'C') | (n != 'D') | (n != 'E'));

}
void view_menu(void) {
	clear_screen();
	printf("Tell me what you want\n\n\n"
		"########################\n"
		"# A (total of amounts) #\n"
		"# D (search by date)   #\n"
		"# K (search by kind)   #\n"
		"# B (back to main menu)#\n"
		"# E (exit program)     #\n"
		"########################\n"
	);
}