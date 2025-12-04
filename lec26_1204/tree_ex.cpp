#include "person.hpp"
#include <iostream>

/* Template the function so that it can be used with any data type */
struct node {
  int data;
  struct node *left;
  struct node *right;
  node() : data(0), left(NULL), right(NULL) {};
  node(int d) : data(d), left(NULL), right(NULL) {};
  node(int d, node *l, node *r) : data(d), left(l), right(r) {};
};

/* Template the function so that it can be used with any data type */
void tree_print(node *cursor, int depth) {
  if (cursor == NULL)
    return;
  for (int i = 0; i < depth; i++)
    printf(i == depth - 1 ? "|-" : "  ");
  printf("%d\n", cursor->data);
  tree_print(cursor->left, depth + 1);
  tree_print(cursor->right, depth + 1);
}

// typedef int<char> inode;
// typedef node<char> inode;

/* Modify main function appropriately to test the templated tree structure */

int main() {
  node *left, *right;

  left = new node(6);
  right = new node(7, left, NULL);
  left = new node(4);
  left = new node(5, left, right);

  right = new node(9);
  right = new node(8, left, right);

  left = new node(1);
  left = new node(2, left, NULL);
  node *root = new node(3, left, right);

  tree_print(root, 0);
}

/*
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
*/
