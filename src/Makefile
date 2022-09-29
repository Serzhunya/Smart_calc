CC = gcc -Wall -Werror -Wextra
GCOV = -fprofile-arcs -ftest-coverage

all: install run

install: 
	cd project_calc && qmake
	cd project_calc && $(MAKE) install
	rm -rf project_calc/smart_calc project_calc/smart_calc.app

run: 
	open smart_calc/smart_calc*

uninstall:

dvi:

clean:
	rm -f *.out
	rm -rf report
	rm -f project_calc/*.o
	rm -f *.gcda	
	rm -f *.gcno
	rm -f *.html
	rm -f *.out
	rm -f *.css
	rm -f *.info
	rm -f project_calc/*.out
	rm -f project_calc/Makefile
	rm -R smart_calc
	rm -f project_calc/.qmake.stash
	rm -R project_calc/.qtc_clangd

dist:

tests:

gcov_report: