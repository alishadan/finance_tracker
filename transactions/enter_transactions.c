#include "../vector/vector.h"
#include <stdio.h>
#include "../functions.h"
#include "transaction.h"
#include "functions_trans.h"
#include <windows.h>
#include <stdlib.h>

void menu_run_transaction(void); void enter_transactions(void); vector create_vector(void);
transaction enter_transaction(void); void secondary_menu(void); void run_secondary_menu(vector*);

void run_transactions(void) {
	menu_run_transaction();
	enter_transactions();
}
void menu_run_transaction(void) {
	printf(
		"##################################\n"
		"# wellcome to enter transactions #\n"
		"##################################\n\n"
	);
}
void secondary_menu(void) {
	printf(
		"##################################\n"
		"# N (enter next transaction)     #\n"
		"# S (save data)                  #\n"
		"# B (main menu)                  #\n"
		"# E (exit)                       #\n"
		"##################################\n\n"
	);

}
void run_secondary_menu(vector* v) {
	clear_screen();
	secondary_menu();
	char n;
	do {
		scanf_s("%c", &n, 1);
		int c; while ((c = getchar()) != '\n' && c != EOF) {}
		if (n == 'S') {
			save_data(v);
			clear_screen();
			return;
		}

		else if (n == 'B')
		{
			clear_screen();
			run_menu1();
			
		}
		else if (n == 'N')
		{
			clear_screen();
			return;
		}
		else if (n == 'E')
		{
			clear_screen();
			exit(1);
		}

		else {
			clear_screen();
			secondary_menu();
			printf(" \n please enter a correct alphabet \n");
		}

	} while ((n != 'N') | (n != 'S') | (n != 'B') | (n != 'E'));
}
void enter_transactions(void) {
	//create a vector that save transactions
	vector v = create_vector();
	
	// fil vector with transactions
	//create transaction

	//transaction* trans = (transaction*)v.arr; // cast v.arr to type of transaction
	do {
		if (v.size == v.capacity) {
			save_data(&v);
		}
		v.add(&v); //v.size++
		transaction* trans = (transaction*)v.arr;  // refresh pointer
		trans[v.size-1] = enter_transaction();
		run_secondary_menu(&v); // what do user want
	} while (1);


}
vector create_vector(void) {
	vector v;
	v.create = vector_create;
	v.create(&v, sizeof(transaction));
	return v;
}
transaction enter_transaction(void) {
	// each transaction have id,Date,amount and kind
	transaction trans;
	trans.id = get_now_id_transaction();
	trans.money = get_ammount();
	trans.date = get_trans_date();
	return trans;
}
