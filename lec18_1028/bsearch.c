#include "linkedlists.c"

node *middle(node *start, node *last) {
  node *slow, *fast;
  /* List is empty */
  if (start == NULL) {
    return NULL;
  }

  /* Initialize slow and start pointers */
  slow = start;
  fast = start->next;

  while (fast != last) {
    /* Update fast once */
    fast = fast->next;
    if (fast != last) {
      /* Update slow once */
      slow = slow->next;

      /* Update fast once more */
      fast = fast->next;
    }
  }

  /* Return slower pointer */
  return slow;
}

node *binary_search(node *cursor, unsigned int year) {
  /* This function calls middle */
  node *start, *end;
  start = cursor;
  end = NULL;

  do {
    node *mid = middle(start, end);
    if (mid == NULL) {
      /* Didn't find item */
      return NULL;
    }
    if (mid->byear == year) {
      /* Found item */
      return mid;
    } else if (mid->byear < year) {
      /* Need to go right */
      start = mid->next;
    } else {
      /* Need to go left */
      end = mid;
    }
  } while (end == NULL || start != end);

  return NULL;
}

node *headptr_prez = NULL;

int main(void) {
  char *gops[] = {"Biden", "Carter", "Obama", "Clinton"};
  unsigned int gop_years[] = {1942, 1924, 1961, 1946};

  char *dems[] = {"Reagan", "Bush", "Trump", "Nixon"};
  unsigned int dem_years[] = {1911, 1946, 1946, 1913};

  node temp;
  for (int i = 0; i < 4; i++) {
    temp.name = gops[i];
    temp.byear = gop_years[i];
    temp.next = NULL;
    insert(&headptr_prez, &temp);
  }

  for (int i = 0; i < 4; i++) {
    temp.name = dems[i];
    temp.byear = dem_years[i];
    temp.next = NULL;
    insert(&headptr_prez, &temp);
  }

  print_list(headptr_prez);

  node *ww2_baby = binary_search(headptr_prez, 1942);
  printf("President %s was born during WWII\n", ww2_baby->name);
  destroy(&headptr_prez);
}
