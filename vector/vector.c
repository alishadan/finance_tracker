#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vector.h"

void vector_create(vector* v, size_t x) {
	//creat an array with 3 element of integers
	v->size = 0;
	v->add = add_element;
	v->remove = remove_element;
	v->capacity = 3;
	v->type = x;
	v->arr = malloc(v->type * v->capacity);
	if (v->arr == NULL) {
		printf("memory error \n");
		exit(1);
	}

}
void add_element(vector* v) {
		v->size++;
	
}
void remove_element(vector* v, int remove_element) {
	(void)remove_element;
	v->size--;
}
