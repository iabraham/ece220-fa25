#include <iostream>

using std::cout, std::cin, std::endl;

float bmi(float ht, float wt, bool si = false) {
  float val = wt / (ht * ht);
  if (si)
    return val * 10000;
  else
    return val * 703;
}

int main() {
  char u;
  float wt, ht, bm_index;

  cout << "In USA? (u - Yes, else - No):\t";
  cin >> u;

  cout << "Enter weight:\t";
  cin >> wt;

  cout << "Enter height:\t";
  cin >> ht;

  bm_index = u == 'u' ? bmi(ht, wt) : bmi(ht, wt, true);

  cout << "Calculated BMI: " << bm_index << endl;

  return 0;
}
