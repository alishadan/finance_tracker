#compiler name
CC = gcc

# options compile
CFLAGS = -Wall -Wextra -O2

# source files
SRCS = main.c functions.c help.c view_trans.c\
transactions/enter_transactions.c\
transactions/save_data.c\
transactions/enter_transaction/get_amount.c\
transactions/enter_transaction/get_date.c\
transactions/enter_transaction/get_id_transaction.c\
vector/vector.c\
view_functions/search_by_date.c view_functions/search_by_kind.c view_functions/total_amounts.c

# object files
OBJS = $(SRCS:.c=.o)

# output name
TARGET = finance_trance

# main rule
all: $(TARGET)

#build program
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# rules for creates .o files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# clean build files
clean:
	rm -f $(OBJS) $(TARGET)