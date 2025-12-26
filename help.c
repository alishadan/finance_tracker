#include <stdio.h>
#include <stdlib.h>
#include "functions.h"
void help_fi(void); void run_about(void);
void help_fi(void) {
	printf(
		"###################################################################\n"
		"# welcome to HELP f finance tracker#\n"
		"# with finance tracker you can enter income and expences #\n"
		"# this program have a useful UI and you can go with menus#\n"
		"# files saved on your computer#\n"
		"# for any problem or have questions email to alishadan84@gmail.com#\n"
		"##\n"
		"###################################################################\n"
		"#       E (exit)                       #\n"
		"#       B (back to main menu)          #\n"
	);


}

void run_help(void) {
	help_fi();
	char n;
	do {
		scanf_s("%c", &n, 1); 
		int c; while ((c = getchar()) != '\n' && c != EOF) {}
		if (n == 'B')
		{
			clear_screen();
			run_menu1();
			break;
		}
		else if (n == 'E')
		{
			clear_screen();
			exit(1);
		}
		else
			printf("please enter a correct alphabet \n");

	} while ( (n != 'B') | (n != 'E') );
}

void about_menu(void) {
	printf(
		"###############################\n"
		"# finance tracker program     #\n"
		"# whit this program you can enter expences and incomes an view them#\n"
		"# developed by Ali Shadan #\n"
		"# this project hosted in Github.com/alishadan#\n"
		"# emali: alishadan84@gmail.com#\n"
		"# website: http://ngarsh.ir#\n"
		"###############################\n"
		"# press E (exit) #\n"
		"# press B (back to main menu) #\n"
	);

}
void run_about(void) {
	about_menu();
	 char n;
	do {
		scanf_s("%c", &n, 1); 
		int c; while ((c = getchar()) != '\n' && c != EOF) {}
		if (n == 'B')
		{
			clear_screen();
			run_menu1();
			break;
		}
		else if (n == 'E')
		{
			clear_screen();
			exit(1);
		}
		else
			printf("please enter a correct alphabet \n");

	} while ( (n != 'B') | (n != 'E')  );
}

