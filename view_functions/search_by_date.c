#include <stdio.h>
#include "../functions.h"
#include "../transactions/transaction.h"
#include <stdlib.h>
void menu_search_by_date(void); void search_by_date(void); void run_search_by_date(void);
void enter_date(int date[3]); int sum_amount_date(int first[3], int last[3]);

void menu_search_by_date(void) {
	//system("cls");
	printf(
		"################################\n"
		"# A (enter first and last date)#\n"
		"# B (back to main menu)        # \n"
		"# E (exit program)             #\n"
		"################################\n"
	);

}
void search_by_date(void) {
	menu_search_by_date();
	char n = 'a';
	do {
		scanf_s("%c", &n, 1);
		int c; while ((c = getchar()) != '\n' && c != EOF) {}
		if (n == 'A') {
			clear_screen();
			run_search_by_date();
		}
		if (n == 'B') {
			clear_screen();
			run_menu1();
		}
		else if (n == 'E')
			exit(1);
		else
			printf("please enter a correct alphabet \n");

	} while ( (n != 'B') | (n != 'E')|( n!='A'));
}
void run_search_by_date(void) {

	int first_date[3], last_date[3];
	printf("please enter first date\n"
		"day,mount and year\n");
	enter_date(first_date);
	clear_screen();
	printf("please enter last date\n"
		"day,mount and year\n");
	enter_date(last_date);
	//sum amounts between first_date and last_date
	int sum_amounts=sum_amount_date(first_date,last_date);
	clear_screen();
	printf("\n\n sum amount between first date and last date is :%d\n\n", sum_amounts);
	search_by_date();

}
void enter_date(int date[3]) {
	do {
		printf("\n day, please enter a number between 1 and 30\n");
		scanf_s("%d", &date[0]);
		int c; while ((c = getchar()) != '\n' && c != EOF) {}
	} while ((1 > date[0]) | (date[0] > 31));
	do {
		printf("\n mount, please enter a number between 1 and 12\n");
		scanf_s("%d", &date[1]);
		int c; while ((c = getchar()) != '\n' && c != EOF) {}
	} while ((1 > date[1]) | (date[1] > 12));
	do {
		printf("\n year, please enter a year\n");
		scanf_s("%d", &date[2]);
		int c; while ((c = getchar()) != '\n' && c != EOF) {}
	} while ((1300 > date[2]) | (date[2] > 3000) );

}

int sum_amount_date(int first[3],int last[3]) {
	const char* file = "files/file.bin";
	// we read data from file.bin, data saved as v[0].id v[0].date v[0].amount
	FILE* files = fopen(file, "rb");
	if (files == NULL) printf("transaction_file is not can open\n");
	int total_amount = 0;
	transaction trans;
	while (fread(&trans, sizeof(transaction), 1, files) == 1) {
		if ((trans.date.year > first[2]) & (trans.date.year <  last[2])) {
			if ((trans.date.mount > first[1]) & (trans.date.mount < last[1])) {
				if ((trans.date.day > first[0]) & (trans.date.mount < last[0])) {
					total_amount = trans.money.amount + total_amount;

				}
			}

		}
		
	}
	if (fclose(files) != 0) printf("info.bin cant close\n");
	return total_amount;
}






