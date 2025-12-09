#include "person.hpp"
#include <iostream>

/* Template the function so that it can be used with any data type */
template <typename T> struct node {
  T data;
  struct node<T> *left;
  struct node<T> *right;
  //  node() : data(0), left(NULL), right(NULL) {};
  node(T d) : data(d), left(nullptr), right(nullptr) {};
  node(T d, node<T> *l, node<T> *r) : data(d), left(l), right(r) {};
};

/* Template the function so that it can be used with any data type */
template <typename T> void tree_print(node<T> *cursor, int depth) {
  if (cursor == NULL)
    return;
  for (int i = 0; i < depth; i++)
    printf(i == depth - 1 ? "|-" : "  ");
  //  printf("%d\n", cursor->data);
  cout << cursor->data << endl;
  tree_print(cursor->left, depth + 1);
  tree_print(cursor->right, depth + 1);
}

/* Modify main function appropriately to test the templated tree structure

typedef node<char> inode;
int main() {
  inode *left, *right;

  left = new inode(65);
  right = new inode(67, left, NULL);
  left = new inode(74);
  left = new inode(65, left, right);

  right = new inode(69);
  right = new inode(68, left, right);

  left = new inode(71);
  left = new inode(72, left, NULL);
  inode *root = new inode(73, left, right);

  tree_print(root, 0);
}

*/

typedef node<Person> inode;

int main() {
  inode *left, *right;
  left = new inode(Person("Alice", 65));
  right = new inode(Person("Bob", 67), left, (inode *)nullptr);
  left = new inode(Person("Rick", 68));
  left = new inode(Person("Susan", 65), left, right);

  right = new inode(Person("Mike", 69));
  right = new inode(Person("Matt", 68), left, right);

  left = new inode(Person("Damon", 71));
  left = new inode(Person("Mark", 72), left, (inode *)nullptr);
  inode *root = new inode(Person("Johnny", 73), left, right);

  tree_print(root, 0);
}
