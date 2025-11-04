#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct dll_node {
  char *name;
  struct dll_node *next;
  struct dll_node *prev;
} dll_node;

void print_forward(dll_node *cursor) {
  printf("HEAD -> ");
  /* While cursor is not NULL */
  while (cursor) {
    /* Print cursor */

    /* Update cursor */
  }
  printf("NULL\n");
}

void delete_by_name(dll_node **cursor, char *key) { /* Left as an exercise */ }

void print_reverse(dll_node *cursor) {
  dll_node *tmp = cursor;

  /* Find tail element and set it to tmp */

  printf("TAIL ->");

  /* Go backwards as long as tmp is not NULL */
  while (tmp) {
    /* Print tmp */
    printf("%s -> ", tmp->name);
    /* Update tmp */
    tmp = tmp->prev;
  }
  printf("HEAD\n");
}

void dll_insert(dll_node **head, char *v) {
  /* Allocate space for new node */
  dll_node *new_node = malloc(sizeof(dll_node));

  /* Copy over string/name */

  /* Set next and prev to NULL */

  /* If list is empty or v is smallest value, then
   * add at head location */
  if (*head == NULL || strcmp((*head)->name, v) > 0) {

    /* New guys next should be current head */

    /* If head was not null update its prev value */

    /* Make new node the new head */

    return;
  }

  /* If not at beginning must find right position */
  dll_node *cursor = *head;

  /* Find the right place to insert new node,
   * cursor should point to node after which new node will
   * be inserted */
  while (cursor->next && strcmp(cursor->next->name, v) < 0)
    cursor = cursor->next;

  /* Insert the node, updating its prev and next*/

  /* If not adding at the tail position,
   * rewire succeeding element's prev to new node */

  /* Set cursor's next to new node */
}

int main(void) {
  dll_node *head = NULL;

  dll_insert(&head, "Ivan");
  dll_insert(&head, "Alex");
  dll_insert(&head, "Molly");
  dll_insert(&head, "David");
  dll_insert(&head, "John");
  dll_insert(&head, "Zoe");

  print_forward(head);
  printf("===============================\n");
  print_reverse(head);

  return 0;
}
