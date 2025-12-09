#include "farey_seq.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
  int n;
  printf("Please enter n: ");
  scanf("%d", &n);
  node *head;
  head = farey_seq(n);
  if (head == NULL)
    printf("The linked list is empty");
  else
    print_list(head, n);
  delete_list(head);
}

node *make_node(int num, int den) {
  node *head = (node *)malloc(sizeof(node));
  head->numerator = num;
  head->denominator = den;
  head->next = NULL;
  return head;
}

node *farey_seq(int n) {
  if (n < 1)
    return NULL;
  if (n == 1) {
    node *head = make_node(0, 1);
    head->next = make_node(1, 1);
    return head;
  }
  node *farey_prev = farey_seq(n - 1);
  node *prev = farey_prev;
  node *curr = farey_prev->next;
  while (curr) {
    int a, b, c, d;
    a = prev->numerator;
    b = curr->numerator;
    c = prev->denominator;
    d = curr->denominator;
    if (c + d <= n) {
      prev->next = make_node(a + b, c + d);
      prev->next->next = curr;
    }
    prev = curr;
    curr = curr->next;
  }
  return farey_prev;
}

void print_list(node *head, int n) {
  if (head == NULL)
    return;
  printf("level %d: ", n);
  while (head != NULL) {
    printf("%d/%d ", head->numerator, head->denominator);
    head = head->next;
  }
  printf("\n");
}

void delete_list(node *head) {
  node *temp;
  while (head != NULL) {
    temp = head->next;
    free(head);
    head = temp;
  }
}
