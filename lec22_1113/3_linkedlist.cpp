#include <iostream>

using namespace std;

template <typename T> class Node {
  T data;

public:
  Node<T> *next;

  // Constructor
  Node(T inval) {}

  void print() { cout << "[" << data << "]"; }
};

template <class T> class LinkedList {
  Node<T> *head;

public:
  // Constructor
  LinkedList<T>() {}

  // Destructor
  ~LinkedList<T>() {}

  void add_at_head(T value) {}

  void print_list() {
    Node<T> *cursor = head;
    cout << "HEAD ->";
    while (cursor) {
      cursor->print();
      cout << "->";
      cursor = cursor->next;
    }
    cout << "NULL";
  }
};

int main(void) {
  // LinkedList<int> *superlist = new LinkedList<int>; // Int List
  LinkedList<char> *superlist = new LinkedList<char>; // Char List
  // LinkedList<char *> *superlist = new LinkedList<char *>; // String List

  const char *mynames[5] = {"Ivan", "Abel", "Matt", "Josh", "Mary"};
  for (int i = 0; i < 5; i++) {
    // superlist->add_at_head(i); // Int List
    superlist->add_at_head(mynames[2][i]); // Char List
    // superlist->add_at_head((char *)mynames[i]); // String List
  }
  superlist->print_list();
}
