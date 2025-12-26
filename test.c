#include <stdio.h>
#include <stdlib.h>
#include "vector/vector.h"
#include "transactions/transaction.h"
vector create_vector1(void); int get_number_of_transactions(const char*);
vector create_vector1(void) {
	vector v;
	v.create = create;
	v.create(&v, sizeof(transaction));
	return v;
}
void test_f(void) {
	const char* info = "files/info.bin";
	const char* file = "files/file.bin";
	//get number of transactions
	int number_trans=get_number_of_transactions(info);

	// we read data from file.bin, data saved as v[0].id v[0].date v[0].amount
	int capacity = 256;
	transaction* trans = malloc(sizeof(transaction) * capacity);

	FILE* files = fopen(file, "rb");
	if (files == NULL) printf("transaction_file is not can open\n");
	fread(trans, sizeof(transaction),number_trans, files);
	if (fclose(files) != 0) printf("info.bin cant close\n");

	printf("v.size is : %d \n", trans[0].money.amount);
}
int get_number_of_transactions(const char* info) {
	//read data in info_file
	int number_of_transactions;
	FILE* infos = fopen(info, "rb");
	if (infos == NULL) printf("transaction_file is not can open\n");
	fread(&number_of_transactions, sizeof(int), 1, infos);
	fclose(infos);
	return number_of_transactions;

}