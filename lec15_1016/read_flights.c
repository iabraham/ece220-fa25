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
  FILE *file = fopen(filename, "r");
  if (file) {
    fclose(file);
    return 1;
  } else {
    return 0;
  }
}

int load_data(char *filename, Flight *array) {
  /* Return number of records read or -1 */
  int numplanes;
  FILE *infile;
  if (!exists(filename)) {
    return 0;
  } else {
    infile = fopen(filename, "rb");
    fread(&numplanes, sizeof(int), 1, infile);
    fread(array, sizeof(Flight), numplanes, infile);
  }
  if (!fclose(infile)) {
    return numplanes;
  } else {
    return -1;
  }
}

int main(void) {
  /* Read flight data and print it out. */
  Flight flights[50];
  int i;
  int numplanes = load_data("airport.bin", flights);
  for (i = 0; i < numplanes; i++) {
    printf("\nFlight %s \n", flights[i].code);
    printf("Departed at: %d\n", flights[i].depart_time);
    printf("Arrives at: %d\n", flights[i].arrival_time);
    printf("-----------------\n");
  }

  return 0;
}
