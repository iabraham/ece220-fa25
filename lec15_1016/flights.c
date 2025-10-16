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

int write_data(char *filename, Flight *array, int numplanes) {
  /* Write data to disk */
}

int main(void) {}
