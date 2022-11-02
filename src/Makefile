CC = gcc -Wall -Werror -Wextra
GCOV = -fprofile-arcs -ftest-coverage
C_TESTS = tests_calc/suite_tests.c tests_calc/test_runner.c
C_FILES = project/create_stack_digit.c project/create_stack_sign.c project/calc.c project/support_func.c project/validation.c
VERSION = `date +"%Y.%m.%d"`
ARCHIVE = smart_calc-$(VERSION)

all: install

install:
	mkdir -p obj_dir
	cd project && qmake
	cd project && $(MAKE) install
	@mv project/*.o obj_dir
	rm -rf project/smart_calc project/smart_calc.app

run:
	open -Fn smart_calc/smart_calc.app

uninstall: clean
	cd project && $(MAKE) clean
	cd project && $(MAKE) uninstall
	rm -rf project/Makefile
	rm -rf project/.qmake.stash
	rm -rf project/.qtc_clangd

dvi: 
	mkdir -p docs
	doxygen Doxyfile
	@mv html latex docs
	open docs/html/index.html

dist:
	@tar -cf $(ARCHIVE).tar $(C_FILES) project/*.h Makefile

tests:
	$(CC) -c $(C_TESTS)
	@mv suite_*.o obj_dir
	$(CC) $(GCOV) -o tests_calc/tests.out $(C_TESTS) $(C_FILES) -lcheck
	tests_calc/./tests.out
	@mv *.gcno *.gcda test_runner.o obj_dir

gcov_report: tests
	gcov obj_dir/*.gcda 
	@mv *.gcov tests_calc/./tests.out obj_dir
	gcovr
	gcovr --html-details -o report.html
	@mv *.css *.html obj_dir

open_report:
	open obj_dir/report.html

clean:
	rm -rf *.css *.info *.out  *.html *.gcno *.gcda *.o *.a *.tar .clang-format
	rm -rf project/*.o project/*.out project/smart_calc.pro.user tests_calc/tests.out
	rm -rf obj_dir docs

check:
	cppcheck project/*.h project/*.c tests_calc/*.h tests_calc/*.c
	cp ../materials/linters/.clang-format .clang-format
	clang-format -n project/s21_calc.h project/mainwindow.h  project/*.c tests_calc/*.c tests_calc/*.h
	CK_FORK=no leaks --atExit -- obj_dir/./tests.out
