#include "tree.h"
#include <stdio.h>

// FUNCTION DEFINITIONS
node *convert(node *root);
void convertRecursive(node *current, node **lastNode);
void printList(node *head);

// Don't change the main function
int main(int argc, char *argv[]) {
  if (argc < 2) {
    printf("Not enough arguments\n");
    return -1;
  }

  node *root = create_tree(argv[1]);
  root = convert(root);
  printList(root);
  deleteList(root);
}

// Converts a tree to a doubly linked list
node *convert(node *root) {
  node *prev = NULL;
  convertRecursive(root, &prev);
  // Find the head of the list
  while (prev->left != NULL) {
    prev = prev->left;
  }
  return prev;
}

// Recursive helper function for converting a tree to a doubly linked list
void convertRecursive(node *current, node **lastNode) {
  if (current == NULL) {
    return;
  }
  convertRecursive(current->left, lastNode);
  if (*lastNode == NULL) {
    *lastNode = current;
  } else {
    (*lastNode)->right = current;
    current->left = *lastNode;
  }
  *lastNode = current;
  convertRecursive(current->right, lastNode);
}

// Given a doubly linked list prints out the list from left to right
// then from right to left (ensures all left and right pointers are correct)
void printList(node *head) {
  node *previous;
  printf("Left to right traversal: \n");
  while (head != NULL) {
    printf("%d ", head->value);
    previous = head;
    head = head->right;
  }
  printf("\nRight to left traversal: \n");
  head = previous;
  while (head != NULL) {
    printf("%d ", head->value);
    head = head->left;
  }
  printf("\n");
}
