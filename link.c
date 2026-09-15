#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node *next;

} *head = NULL;

void insertbeg() {
    struct node *nw=(struct node*)malloc (sizeof(struct node));
    printf("Enter data part");
    scanf("%d", &nw->data);
    if (head == NULL) {
      head = nw;
      head->next = NULL;

    } else {
      nw->next = head;
      head = nw;
    }
}

void insertend()
{
  truct node *nw=(struct node*)malloc (sizeof(struct node));
    printf("Enter data part");
    scanf("%d", &nw->data);
    if (head == NULL) {
      head = nw;
      head->next = NULL;
    }
    else 
    {
      struct node *temp=head;
      while(temp->next!=NULL)
      {
        temp=temp->next;
      }
      temp->next=nw;
      nw->next=NULL;

    }
}


void delbeg()
{
  if(head ==NULL)
  {
    printf("Deletion not possible");

  }
  else
  {
    struct node *temp=head;
    head=head->next;
    free(temp);

  }
}

void main()
{
  

}