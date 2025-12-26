#pragma once
struct account;
struct transaction;
struct Date;
typedef struct Date {
	int mount;
	int day;
	int year;
}date;
typedef struct account {
	int amount;
	char type[20];
}account;
typedef struct transaction {
	int id;
	struct account money;
	date date;
}transaction;

