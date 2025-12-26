#include "transaction.h"
#include "../vector/vector.h"
#include <stdio.h>
#include <stdlib.h>
#include "../functions.h"


int create_file1(const char*);
void save_data(vector* v) {
	const char* file = "files/file.bin";
	int return_value = create_file1(file);
	if (return_value == 0) {
		//transaction_file is empty
		FILE* trans_file = fopen(file, "wb");
		if (trans_file == NULL) printf("transactions_file.bin is not can open\n");
		fwrite(v->arr, v->type, v->size, trans_file);
		fclose(trans_file);
		if (fclose(trans_file) != 0) printf("transactions_file.bin cant close\n");
		printf("data saved\n");
		delay_ms(3000);
	}

	if (return_value == 1) {
		//transaction_file is not empty
		FILE* trans_file = fopen(file, "ab");
		if (trans_file == NULL) printf("transactions_file.bin is not can open\n");
		fwrite(v->arr, v->type, v->size, trans_file);
		fclose(trans_file);
		if (fclose(trans_file) != 0) printf("transactions_file.bin cant close\n");
		printf("data saved\n");
	}

	free(v->arr);
	v->arr = malloc(v->type * v->capacity);
	if (!v->arr) {
		printf("malloc failed \n");
		exit(1);
	}
	v->size = 0;

}
int create_file1(const char* file) {
	if (access(file, F_OK) != 0) {
		FILE* info = fopen(file, "wb");
		if (info == NULL) printf("info.bin can not created\n");
		if (fclose(info) != 0) printf("info.txt not closed\n");
		return 0;
	}

	if (access(file, F_OK) == 0) {
		return 1;
	}
	return 1;

}