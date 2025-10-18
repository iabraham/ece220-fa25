#include <stdio.h>

enum weekday { SUN, MON, TUE, WED, THR, FRI, SAT };

int is_workday(enum weekday day) {
  if (day > SUN && day < SAT)
    return 1;
  else
    return 0;
}

enum weekday what_day_nfrom_now(enum weekday today, int n) {}

int main(void) {

  enum weekday today = THR;
  enum weekday day_after_next = today + 2;

  printf("Today is day #%d of the week.\n", today);
  printf("Today is %s\n", is_workday(today) ? "a workday" : "not a workday");

  printf("\n");
  printf("Day after tomorrow is day #%d of the week.\n", day_after_next);
  printf("That day is %s\n",
         is_workday(day_after_next) ? "a workday" : "not a workday");
}
