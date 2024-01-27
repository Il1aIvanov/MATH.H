CC=gcc
CFLAGS=-Wall -Wextra -Werror -std=c11
CHECKFLAG=-lcheck
GCOVFLAG=--coverage
AR=ar rcs

s21_=s21_*

TEST_DIR=tests
REP_DIR=report

TEST=test
LIB=s21_math

.PHONY: all $(LIB) $(TEST) clean rebuild format_n format_i

all: $(LIB).a

$(LIB).a:
	$(CC) -c $(CFLAGS) $(s21_).c assistive.c
	$(AR) $(LIB).a $(s21_).o assistive.o

$(TEST): clean $(LIB).a
	$(CC) $(CFLAGS) $(CHECKFLAG) $(LIB).a ./$(TEST_DIR)/test_s21_*.c ./$(TEST_DIR)/test_main.c -o $(TEST)
	./$(TEST)

test_coverage: clean
	$(CC) -c $(CFLAGS) ./$(TEST_DIR)/test_s21_*.c ./$(TEST_DIR)/test_main.c
	$(CC) $(CFLAGS) $(CHECKFLAG) $(GCOVFLAG) $(s21_).c assistive.c test_s21_*.o test_main.o -o $(TEST)
	./$(TEST)

gcov_report: test_coverage
	@mkdir -p $(REP_DIR)
	gcovr --html-details -o $(REP_DIR)/index.html --filter "./*"
	open $(REP_DIR)/index.html

lcov_report: test_coverage
	lcov -t "Coverage_Report" -o Coverage_Report.info -c -d .
	genhtml -o $(REP_DIR) Coverage_Report.info
	open $(REP_DIR)/index.html

clean:
	rm -rf *.o *.a *.gcno *.gcda *.info $(TEST) $(REP_DIR) *.out

rebuild:
	make clean
	make all

format_n:
	clang-format -n --style=Google ./*.[ch] $(TEST_DIR)/*.[ch]

format_i:
	clang-format -i --style=Google ./*.[ch] $(TEST_DIR)/*.[ch]
