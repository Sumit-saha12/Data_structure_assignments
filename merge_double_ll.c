/********************************************************************
                        SUMIT SAHA
                  M.SC IN DATA SCIENCE
                 MERGE SORTED LINK LIST
********************************************************************/


#include<stdio.h>
#include<stdlib.h>

struct node
{
    struct node *prev;
    int data;
    struct node *next;
};
typedef struct node node;
node* insert(node *,int);
void display(node*);

int main()
{
    int i,n,m;
    node *head1,*head2,*head3,*p,*q,*r,*k;
    head1=NULL;
    head2=NULL;
    head3=NULL;
    printf("\nEnter the number of nodes of first link list: \n");
    scanf("%d",&n);
    printf("\nENter the data in sorted order: \n");
    head1=insert(head1,n);
    printf("\n First inklist: \n");
    display(head1);              //FIRST LINKLIST       
    printf("\nEnter the number of nodes of second link list: \n");
    scanf("%d",&m);
    printf("\nENter the data in sorted order: \n");
    head2=insert(head2,m);      //SECOND LINKLIST
    printf("\n Second inklist: \n");
    display(head2);
    p=head1;
    q=head2;
    while(p->next!=NULL)
    {
        p=p->next;
    }
    p->next=q;
    q->prev=p;

    printf("\nMerge linklist: \n");
    display(head1);
}


node * insert(node * head1,int n)
{
    int i,m;
    node *p,*q,*r,*k;
    for(i=0;i<n;i++)                                
    {
        p=(node*)malloc(sizeof(node));
        printf("Enter %dth data: ",i);
        scanf("%d",&p->data);
        if(head1==NULL)
        {
            head1=p;
            head1->next=NULL;
            head1->prev=NULL;
        }
        else
        {
            q=head1;
            while(q->next!=NULL)
            {
                q=q->next;       
            }
            q->next=p;
            p->prev=q;
            p->next=NULL;
        } 
    }
    return head1;
}

void display(node *head)
{
    node *q;
    printf("NULL <=>");
    for(q=head;q!=NULL;q=q->next)
    {
        printf("|%d| <=>",q->data);
    }
   
    printf("NULL");
}