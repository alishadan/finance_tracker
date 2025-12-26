#include <stdio.h>
#include "../transaction.h"
#include <stdlib.h>
#include "../../functions.h"

void menu_enter_trans_amount(void) {
	clear_screen();
	printf("######################\n"
		"# enter account         #\n"
		"#########################\n"
	);

}
account get_ammount(void) {
	account money;

	do {
		clear_screen();
		printf("*** Enter Income with correctly ***\n");
		scanf_s("%d", &money.amount);
		int c; while ((c = getchar()) != '\n' && c != EOF) {}
	} while ((0 > money.amount) | (money.amount > 1000000000)); //from zero to one miliard

	printf("\n *** ENTER type of income ***\n"
		"** for example:"
		"hoquq "
		"coffee and ... **\n");
	scanf_s("%s", &money.type, (unsigned)sizeof(money.type));
	int c; while ((c = getchar()) != '\n' && c != EOF) {}

	return money;
}