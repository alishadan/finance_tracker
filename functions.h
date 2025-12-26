#pragma once
#include "vector/vector.h"
#ifdef _WIN32
#include <io.h>
#define access _access
#define F_OK 0
#else
#include <unistd.h>
#endif
#pragma once

#ifdef _WIN32
#include <windows.h>
#define delay_ms(ms) Sleep(ms)
#else
#include <unistd.h>
#define delay_ms(ms) usleep((ms) * 1000)
#endif


void run_menu1(void);
void run_help(void);
void run_about(void);
void run_transactions(void);
void clear_screen(void);
void view_trans(void);
void pause_console(void);



