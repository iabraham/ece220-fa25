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

int main(void) {}
