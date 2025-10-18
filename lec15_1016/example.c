#include <stdio.h>

struct geoloc {
  float lattitude;
  float longitude;
};

typedef struct flight {
  char code[8];
  unsigned int arrival_time;
  unsigned int depart_time;
  struct geoloc origin;
  struct geoloc destination;
} Flight;

int main(void) {
  Flight f1 = {"AAL140", 1100, 1500, {11.34, 78.45}, {183.4, 129.4}};

  return 0;
}
