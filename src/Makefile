CC = gcc -Wall -Werror -Wextra
GCOV = -fprofile-arcs -ftest-coverage
C_TESTS = tests_calc/suite_tests.c tests_calc/test_runner.c
C_FILES = project/create_stack_digit.c project/create_stack_sign.c project/calc.c project/support_func.c project/validation.c
#ASAN = -g -O0 -fanalyzer -fsanitize=address #-fsanitize=undefined
SUITE_CASES_O = obj_dir/suite_*.o
SUITE_CASES_C = tests_calc/suite_*.c
FLAG_COV = --coverage 
S21_CALC_C = project/*.c 
S21_CALC_O = obj_dir/*.o
PACKAGE = smart_calc
VERSION = `date +"%Y.%m.%d"`
ARCHIVE = $(PACKAGE)-$(VERSION)

all: install run

install:
	mkdir -p obj_dir
	cd project && qmake
	cd project && $(MAKE) install
	@mv project/*.o obj_dir
	rm -rf project/smart_calc project/smart_calc.app

run: 
	open -Fn smart_calc/smart_calc*

uninstall: clean
	cd project && $(MAKE) clean
	cd project && $(MAKE) uninstall
	rm -rf project/Makefile
	rm -rf project/.qmake.stash
	rm -rf project/.qtc_clangd

dvi: calc.dvi

calc.dvi: calc.texi
	texi2dvi calc.texi

clean:
	rm -rf *.css *.info *.out  *.html *.gcno *.gcda *.o *.a *.tar
	rm -rf project/*.o project/*.out project/smart_calc.pro.user
	rm -rf obj_dir
	rm -rf tests_calc/tests.out

dist:
	@tar -cf $(ARCHIVE).tar $(C_FILES) project/*.h Makefile

tests:
	$(CC) $(C_TESTS) $(C_FILES) -lcheck -o tests_calc/tests.out
	tests_calc/./tests.out

gcov_report:
	$(MAKE) -f test.mk gcov_report