#ifndef SRC_TESTS_CALC_TESTS_H_
#define SRC_TESTS_CALC_TESTS_H_

#include <check.h>

#include "../project/s21_calc.h"

Suite *suite_s21_calc_notation(void);

void run_tests(void);
void run_testcase(Suite *testcase);

#endif  // SRC_TESTS_CALC_TESTS_H_
