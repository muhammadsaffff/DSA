#include <stdio.h>
#include <stdlib.h>

struct node{
    int co;
    int exp;
    struct node *next;
}*poly1=NULL,*poly2=NULL,*poly3=NULL;

struct node *create(struct node *poly,struct node *nw)
{

    if(poly == NULL)
    {
        poly=nw;
        poly->next=NULL;
        return poly;

    }
    else
    {
        struct node *temp=poly;
        while(temp->next!=NULL)
        {
            temp=temp->next;

        }

    temp->next=nw;
    nw->next=NULL;
    poly=nw;
    return poly;

    }
}

struct node *add(struct node *poly1,struct node *poly2)
{
    struct node *temp1=poly1,*temp2=poly2;
    while(temp1!=NULL && temp2!=NULL)
    {
        struct node *nw=(struct node*)malloc(sizeof(struct node));
        if(temp1->exp==temp2->exp)
        {
            nw->co=temp1->co+temp2->co;
            nw->exp=temp1->exp;
            poly3=create(poly3,nw);
            temp1=temp1->next;
            temp2=temp2->next;
        }

        else if(temp1->exp>temp2->exp)
        {
            nw->co=temp1->co;
            nw->exp=temp1->exp;
            poly3=create(poly3,nw);
            temp1=temp1->next;

        }
        else
        {
            nw->co=temp2->co;
            nw->exp=temp2->exp;
            poly3=create(poly3,nw);
            temp2=temp2->next;
        
        }
    
        }

        while(temp1!=NULL)
        {
            struct node *nw=(struct node*)malloc(sizeof(struct node));
            nw->co=temp1->co;
            nw->exp=temp1->exp;
            poly3=create(poly3,nw);
            temp1=temp1->next;

        }

        while(temp2!=NULL)
        {
            struct node *nw=(struct node*)malloc(sizeof(struct node));
            nw->co=temp2->co;
            nw->exp=temp2->exp;
            poly3=create(poly3,nw);
            temp2=temp2->next;

        }
        return poly3;
        
}


void display(struct node *poly)
{
    struct node *temp=poly;
    while(temp!=NULL)
    {
        if(temp->next!=NULL)
        {
            printf("%d^x%d+",temp->co,temp->exp);
        }
        else
        {
            printf("%d^x%d",temp->co,temp->exp);

        }
        
    }
}

void main()
{
int i,n;
printf("Enter the range of first polynomial");
scanf("%d",&n);
for(i=0;i<n;i++)
{
    struct node *nw=(struct node*)malloc(sizeof(struct node));
    printf("Enter the coefficient ");
    scanf("%d",&nw->co);
    printf("Enter the exponent ");
    scanf("%d",&nw->exp);
    poly1=create(poly1,nw);

}
printf("Enter the range of second polynomial");
scanf("%d",&n);
for(i=0;i<n;i++)
{
    struct node *nw=(struct node*)malloc(sizeof (struct node));
    printf("Enter the coefficient ");
    scanf("%d",&nw->co);
    printf("Enter the exponent ");
    scanf("%d",&nw->exp);
    poly2=create(poly2,nw);
}

poly3 =add(poly1,poly2);
display(poly1);
display(poly2); 
display(poly3);

}


