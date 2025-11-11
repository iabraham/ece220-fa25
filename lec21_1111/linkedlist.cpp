#include "LinkedList.h"
using namespace std;

void LinkedList::print_list() {}

void LinkedList::add_at_head(Person p) {}

void LinkedList::del_at_head() {}

LinkedList::~LinkedList() {
  while (head)
    del_at_head();
}

int main() {
  // Define the names and birth years of some presidents
  const char *blue_names[] = {"Biden", "Carter", "Obama", "Clinton"};
  unsigned int blue_years[] = {1942, 1924, 1961, 1946};

  // Define the names and birth years of some presidents
  const char *red_names[] = {"Reagan", "Bush", "Trump", "Nixon"};
  unsigned int red_years[] = {1911, 1946, 1946, 1913};

  LinkedList prez_list;

  for (int i = 0; i < 4; i++) {
    Person p = Person(blue_names[i], blue_years[i]);
    prez_list.add_at_head(p);
  }

  prez_list.print_list();

  for (int i = 0; i < 4; i++) {
    Person p = Person(red_names[i], red_years[i]);
    prez_list.add_at_head(p);
  }

  prez_list.print_list();
}
