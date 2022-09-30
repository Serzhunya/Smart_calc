CC = gcc -Wall -Werror -Wextra
GCOV = -fprofile-arcs -ftest-coverage

all: install run

install:
	cd project_calc && qmake
	cd project_calc && $(MAKE) install
	rm -rf project_calc/smart_calc project_calc/smart_calc.app

run: 
	open -Fn smart_calc/smart_calc*

uninstall: clean
	cd project_calc && $(MAKE) clean
	cd project_calc && $(MAKE) uninstall
	rm -rf project_calc/Makefile
	rm -rf project_calc/.qmake.stash
	rm -rf project_calc/.qtc_clangd

dvi:
	open dvi.pdf

clean:
	rm -rf *.css *.info *.out  *.html *.gcno *.gcda
	rm -rf project_calc/*.o
	rm -rf project_calc/*.out
	rm -rf project_calc/smart_calc.pro.user

dist:

tests:

gcov_report: