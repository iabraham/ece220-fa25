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

int write_data(char *filename, Flight *array, int numplanes) {
  /* Write data to disk */
  FILE *outfile = fopen(filename, "wb");
  if (outfile == NULL) {
    return 0;
  } else {
    fwrite(&numplanes, sizeof(int), 1, outfile);
    fwrite(array, sizeof(Flight), numplanes, outfile);
  }
  return fclose(outfile);
}

int main(void) {

  Flight f1 = {"AAL140", 1100, 1500, {11.34, 78.45}, {183.4, 129.4}};
  Flight planes[2] = {f1,
                      {"SPT34", 1200, 1600, {78.45, 11.34}, {129.4, 183.4}}};
  write_data("airport.bin", planes, 2);
}
