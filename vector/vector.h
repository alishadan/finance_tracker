#pragma once
//#include "../transactions.h"
#include <stdio.h>
//declare functions and structs
typedef struct vector {
	void (*create)(struct vector* v, size_t x);
	void (*add)(struct vector* v);
	void (*remove)(struct vector* v, int);
	void* arr;
	int size; // length of array;
	int capacity;
	size_t type;
}vector;
void vector_create(struct vector* v, size_t x);
void add_element(struct vector* v);
void remove_element(struct vector* v, int);


