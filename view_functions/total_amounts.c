#include <stdio.h>
#include "../functions.h"
#include "../transactions/transaction.h"
#include <stdlib.h>
int record_counts(const char*); int sum_amount(int);
void menu_total_amounts(void) {
	
	printf(
		"################################\n"
		"# B (back to main menu)        # \n"
		"# E (exit program)             #\n"
		"################################\n"
	);

}
void total_amounts(void) {
	menu_total_amounts();
	const char* info = "files/info.bin";
	int record_count = record_counts(info);
	
	printf("sum of amounts of transactions is: \n%d tooman\n", sum_amount(record_count));

	char n = 'a';
	do {
		scanf_s("%c", &n, 1);
		int c; while ((c = getchar()) != '\n' && c != EOF) {}
		if (n == 'B') {
			clear_screen();
			run_menu1();
		}
		else if (n == 'E')
			exit(1);
		else
			printf("please enter a correct alphabet \n");

	} while ( (n != 'B') | (n != 'E'));
}

int sum_amount(int record_count) {
	(void)record_count;
	const char* file = "files/file.bin";
	// we read data from file.bin, data saved as v[0].id v[0].date v[0].amount
	FILE* files = fopen(file, "rb");
	if (files == NULL) printf("transaction_file is not can open\n");
	int total_amount = 0;
	transaction trans;
	while (fread(&trans, sizeof(transaction), 1, files) == 1) {
		total_amount = trans.money.amount + total_amount;
	}
	if (fclose(files) != 0) printf("info.bin cant close\n");
	return total_amount;
}
int record_counts(const char* info){
	//read data in info_file
	int number_of_transactions;
	FILE* infos = fopen(info, "rb");
	if (infos == NULL) printf("transaction_file is not can open\n");
		fread(&number_of_transactions, sizeof(int), 1, infos);
		fclose(infos);
		return number_of_transactions;
}

