#include <stdio.h>
#include "../transaction.h"
#include <Windows.h>
#include <stdlib.h>
#include "../../functions.h"
void menu_enter_trans_date(void); date run_enter_trans_date(void); date enter_trans_date(void);

date get_trans_date() {
	date trans_date = run_enter_trans_date();
	return trans_date;
}
void menu_enter_trans_date(void) {
	clear_screen();
	printf("#########################\n"
		   "# enter date            #\n"
		   "#########################\n"
	);

}
date run_enter_trans_date(void) {
	menu_enter_trans_date();
	date trans_date = enter_trans_date();
	return trans_date;
}
date enter_trans_date(void) {
	date trans_date;
	printf("\n *** please enter Date *** \n");
	do {
		printf("\n *** day ***  please enter a number between 1 and 30\n");

		scanf_s("%d", &trans_date.day);
		int c; while ((c = getchar()) != '\n' && c != EOF) {}
	} while ((1 > trans_date.day) | (trans_date.day > 31));
	do {
		printf("\n *** mount ***  please enter a number between 1 and 12\n");
		scanf_s("%d", &trans_date.mount);
		int c; while ((c = getchar()) != '\n' && c != EOF) {}
	} while ((1 > trans_date.mount) | (trans_date.mount > 12));
	do {
		printf("\n *** year ***  please enter a number for yerar : 4 number\n");
		scanf_s("%d", &trans_date.year);
		int c; while ((c = getchar()) != '\n' && c != EOF) {}
	} while ( (1300 > trans_date.year) | (trans_date.year > 3000));

	return trans_date;
}