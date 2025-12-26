#include <stdio.h>
#include <windows.h>
#include "functions.h"
#include <stdlib.h>
void clear_screen(void) {
#ifdef _WIN32
	system("cls");
#else
	system("clear");
#endif
}
void pause_console() {
#ifdef _WIN32
	system("pause");
#else
	system("read -p \"Press Enter to continue...\" dummy");
#endif
}

void menu1(void);
void run_menu1(void) {
	menu1();
	char n;
	do {
		scanf_s("%c", &n, 1);
		int c; while ((c = getchar()) != '\n' && c != EOF) {}
		if (n == 'H') { clear_screen(); run_help(); break; }
		else if (n == 'I') {
			clear_screen();
			run_transactions();
		}

		else if (n == 'V') {
			clear_screen();
			view_trans();
		}
			
		else if (n == 'A')
		{
			clear_screen();
			run_about();
		}
		else if (n == 'E')
		{
			clear_screen();
			exit(1);
		}

		else
			printf("please enter a correct alphabet \n");

	} while ( (n != 'H') | (n != 'E') | (n != 'V') | (n != 'A') | (n != 'I'));

}
void menu1(void) {

	printf("##########################\n"
		"#press one key of bellow #\n"
		"# I (enter transaction)  #\n"
		"# V (view trans)         #\n"
		"# H      (help)          #\n"
		"# A     (about)          #\n"
		"# E      (exit)          #\n"
		"##########################\n");
}


