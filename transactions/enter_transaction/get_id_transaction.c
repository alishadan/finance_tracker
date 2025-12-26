#include <stdio.h>
#include <Windows.h>
#include <direct.h>
#include <errno.h>
#include "../../functions.h"
void create_folder(const char* folder);
int create_file(const char* file);

int get_now_id_transaction(void) {
	int id_last_trans = 0;
	//we check existence of file folder
	const char* folder = "files";
	create_folder(folder);
	//then we check existence of files/info.bin
	const char* file = "files/info.bin";
	int return_value = create_file(file);
	if (return_value == 0) {
		//info.bin is empty
		FILE* info = fopen(file, "wb");
		if (info == NULL) printf("info.bin is not can open\n");
		(void)fwrite(&id_last_trans, sizeof(int), 1, info);
		if (fclose(info) != 0) printf("info.bin cant close\n");
	}
	if (return_value == 1) {
		//info.bin is not empty
		FILE* info = fopen(file, "rb");
		if (info == NULL) printf("info.bin is not can open\n");
		(void)fread(&id_last_trans, sizeof(int), 1, info);
		if (fclose(info) != 0) printf("info.bin cant close\n");
	}
	int new_id_trans = id_last_trans + 1;
	//update info.bin with new id trans
	FILE* info = fopen(file, "wb");
	if (info == NULL) printf("info.bin is not can open\n");
	(void)fwrite(&new_id_trans, sizeof(int), 1, info);
	if (fclose(info) != 0) printf("info.bin cant close\n");

	return new_id_trans;
}
void create_folder(const char* folder) {
	if (_mkdir(folder) == -1) {
		if (errno == EEXIST) {
			//printf("files folder is exsist\n");
		}
		else {
			printf("files folder is not create\n");
		}
	}
}
int create_file(const char* file) {
	if (_access(file, 0) != 0) {
		FILE* info = fopen(file, "wb");
		if (info == NULL) printf("info.bin can not created\n");
		if (fclose(info) != 0) printf("info.txt not closed\n");
		return 0;
	}

	if (_access(file, 0) == 0) {
		return 1;
	}
	return 0;

}