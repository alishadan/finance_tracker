#include <stdio.h>
#include "../functions.h"
#include <string.h>
#include "../transactions/transaction.h"
#include <stdlib.h>
void menu_search_by_kind(void); void search_by_kind(void); void show_list_of_kinds(void);
void run_search_by_kind(void);

void menu_search_by_kind(void) {
	printf(
		"################################\n"
		"# A (show list of kinds)       #\n"
		"# K (search by kinds)          #\n"
		"# B (back to main menu)        #\n"
		"# E (exit program)             #\n"
		"################################\n"
	);
}
void search_by_kind(void){
	menu_search_by_kind();
	char n = 'a';
	do {
		scanf_s("%c", &n, 1);
		int c; while ((c = getchar()) != '\n' && c != EOF) {}
		if (n == 'A') {
			clear_screen();
			menu_search_by_kind();
			show_list_of_kinds();
			
		}
		if (n == 'K') {
			clear_screen();
			run_search_by_kind();
			menu_search_by_kind();
		}
		else if (n == 'B') {
			clear_screen();
			run_menu1();
		}
		else if (n == 'E')
			exit(1);
		else
			printf("please enter a correct alphabet \n");

	} while ( (n != 'B') | (n != 'E') | (n != 'A') | (n!='K') );
}
void show_list_of_kinds(void) {
	const char* file = "files/file.bin";
	// we read data from file.bin, data saved as v[0].id v[0].date v[0].amount
	FILE* files = fopen(file, "rb");
	if (files == NULL) printf("transaction_file is not can open\n");

	transaction trans;
	//int chunk = 256; int count_list = 100;
	while (fread(&trans, sizeof(transaction), 1, files) == 1) {
		printf("%s\n", trans.money.type);

	}
}
void run_search_by_kind(void) {
	const char* file = "files/file.bin";
	// we read data from file.bin, data saved as v[0].id v[0].date v[0].amount
	FILE* files = fopen(file, "rb");
	if (files == NULL) printf("transaction_file is not can open\n");

	printf("please enter kind of amount\n");
	char str[15];
	transaction trans;
	int total_amount = 0;
	//	int find_date[1000];
	if (scanf_s("%14[^\n]", str, (unsigned)_countof(str)) != 1) {
		printf("Input error.\n");
		return;
	}
	while (fread(&trans, sizeof(transaction), 1, files) == 1) {
		if (strcmp(str, trans.money.type) == 0) {
			total_amount = trans.money.amount + total_amount;
		}
	}
	if (fclose(files) != 0) printf("info.bin cant close\n");
	clear_screen();
	printf("\n\n sum amounts of type %s is :%d\n\n", str,total_amount);

}

