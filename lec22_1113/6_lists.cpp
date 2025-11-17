#include <iostream>
#include <iterator>
#include <list>
using namespace std;

template <typename T> void showlist(list<T> g) {
  //  typename list<T>::iterator it;
  for (auto it = g.begin(); it != g.end(); ++it)
    cout << '\t' << *it;
  cout << endl;
}

int main() {

  list<int> gqlist1, gqlist2;

  for (int i = 0; i < 10; ++i) {
    gqlist1.push_back(i * 2);
    gqlist2.push_front(i * 3);
  }

  cout << "\nList 1 (gqlist1) is : ";
  showlist(gqlist1);

  cout << "\nList 2 (gqlist2) is : ";
  showlist(gqlist2);

  cout << "\ngqlist2.sort(): ";
  gqlist2.sort();
  showlist(gqlist2);

  return 0;
}
