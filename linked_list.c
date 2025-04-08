#include "linked_list.h"

#include <stdlib.h>

struct list_node *new_node(size_t value) { 
  list_node * nd = malloc(sizeof(list_node));
  nd -> value = value;
  nd -> next = NULL;
  return nd;
  }

void insert_at_head(struct linked_list *list, size_t value) {
  list_node * ptr = new_node(value); 
  ptr -> next = list -> head; // insert new node before head
  list -> head = ptr;
  return;
}

void insert_at_tail(struct linked_list *list, size_t value) {
  list_node * ptr = new_node(value); 
  list -> head -> next = ptr;
  return;
}

size_t remove_from_head(struct linked_list *list) { 
  if (list -> head == NULL)
  {
    return 0;
  }
  list -> head = list -> head -> next 
  return 0; 
}

size_t remove_from_tail(struct linked_list *list) { 
  linked_list * list2 = list;
  while(list2 -> head -> next != NULL)
  {
    list2 -> head = list2 -> head -> next;
  }
  list2 -> head = NULL;
  //how do i delete the last node without losing the head?
  return 0; 
}

void free_list(struct linked_list list) {
  linked_list list2 = list
  while(list -> head != NULL)
  {
    list2 -> head = list2 -> head -> next;
    free(list -> head);
    list = list2;
  } 
}

// Utility function to help you debugging, do not modify
void dump_list(FILE *fp, struct linked_list list) {
  fprintf(fp, "[ ");
  for (struct list_node *cur = list.head; cur != NULL; cur = cur->next) {
    fprintf(fp, "%zu ", cur->value);
  }
  fprintf(fp, "]\n");
}
