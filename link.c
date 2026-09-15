#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node *next;

} *head = NULL;

void insertbeg() {
    struct node *nw=(struct node*)malloc(sizeof)(struct node));
    printf("Enter data part");
    scanf("%d", nw->data);
    if (head == NULL) {
      head = nw;
      head->next = NULL;

    } else {
    }
}