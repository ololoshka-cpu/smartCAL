CFLAGS = -Wall -Werror -Wextra -std=c11
TESTFLAGS = -lcheck
CC = gcc

all: gcov_report install

install:
	sh install.sh

uninstall:
	rm -rf build

debug: 
	$(CC) $(CFLAGS) *.c -o stack
	./stack

clean:
	-rm *.gc* 
	-rm test 
	-rm report.info
	-rm -rf html_report
	-rm -rf html
	-rm -rf latex
	-rm stack
	-rm *.tar
	-rm -rf jarlygri_SmartCal_v1

style:
	cp ../materials/linters/.clang-format .
	clang-format -n *.c *.h tests/*.c tests/*.h SmartCalc_v1_0/*.cpp SmartCalc_v1_0/*.h
	clang-format -i *.c *.h tests/*.c tests/*.h SmartCalc_v1_0/*.cpp SmartCalc_v1_0/*.h
	rm .clang-format

dvi:
	doxygen doxyconfig
	open ./html/index.html

test:
	$(CC) $(CFLAGS) $(TESTFLAGS) s21*.c tests/*.c -o test
	./test

leaks: test
	leaks --atExit -- ./test

gcov_report: CFLAGS += -fprofile-arcs -ftest-coverage
gcov_report: test
	lcov -t "report" -o report.info -c -d .
	genhtml -o "html_report" report.info
	open html_report/index.html

dist:
	tar -cf jarlygri_SmartCal_v1.tar *.c *.h Makefile SmartCalc_v1_0

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: all test gcov_report style clean dvi debug