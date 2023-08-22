#include "test.h"

int main(void) {
  SRunner *runner = srunner_create(suite_create("s21_smart_calc"));
  srunner_add_suite(runner, s21_calc_suite());
  srunner_set_fork_status(runner, CK_NOFORK);
  srunner_run_all(runner, CK_NORMAL);
  int result = srunner_ntests_failed(runner) > 0;
  srunner_free(runner);
  return result;
}