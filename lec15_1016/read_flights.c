#include <stdio.h>

typedef struct geoloc {
  float lattitude;
  float longitude;
} geo;

typedef struct flight {
  char code[8];
  unsigned int arrival_time;
  unsigned int depart_time;
  geo origin;
  geo destination;
} Flight;

int exists(const char *filename) {
  /* Return 1 if file exists, else return 0 */
}

int load_data(char *filemame, Flight *array) {
  /* Return number of records read or -1 */
}

int main(void) {
  /* Read flight data and print it out. */
  Flight flights[10];
}
