/*******************************************************************************
 *                          SUMIT SAHA
 *                    M.SC IN DATA SCIENCE
 *                   QUEUE USING LINKEDLIST
 * ****************************************************************************/





#include<stdio.h>
#include<stdlib.h>

struct node 
{
    int data;
    struct node *next;
};
typedef struct node NODE;
NODE *enqueue(NODE *);
NODE *dequeue(NODE *);
NODE *display(NODE *);

int main()
{
    int max,ch,front=-1,rear=-1,data;
    NODE *head=NULL;
    printf("Enter queue size: ");
    scanf("%d",&max);
    while(1)
    {
        printf("\n1.FOR ENQUEUE\n2.FOR DEQUEUE\n3.DISPLAY\n4.EXIT\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                
                if(rear==max-1)
                {
                    printf("\nQueue is full\n");
                }
                else
                {
                    rear++;
                    if(rear==0)
                        front=0;
                    head=enqueue(head);
                    
                
                }
                break;
            case 2:
                if(rear==-1&&front==-1)
                    printf("Queue is empty\n");       
                else
                {
                    head=dequeue(head);
                    if(rear==front)
                    {
                        rear=-1;
                        front=-1;
                    }
                    front++;
                    
                }
                break;
            case 3:
                    if(rear==-1&&front==-1)
                    {
                        printf("Queue is empty\n");
                    }
                    else
                    {
                        head=display(head);
                    }
                    break;
            case 4:
                    printf("\nOperation exit\n");
                    exit(1);
            default:
                    printf("\nWrong choice\n");
        }
    }
}

NODE *enqueue(NODE *head)
{
    NODE *p,*q;
    p=(NODE*)malloc(sizeof(NODE));
    printf("Enter the data: ");
    scanf("%d",&p->data);
    if(head==NULL)
    {
        head=p;
        head->next=head;
    }
    else
    {
        q=head;
        while(q->next!=head)
        {
            q=q->next;
        }
        q->next=p;
        p->next=head;


    }
    return head;
}

NODE *dequeue(NODE *head)
{
    NODE *p,*q;
    if(head==NULL)
    {
        printf("Empty list");
    }
    else
    {
        p=head;
        if(head->next==head)
        {
            head=NULL;
        }
        else
        {
            q=head;
            while(q->next!=head)
                q=q->next;
            head=head->next;
            p->next=NULL;
            q->next=head;
        }
    }
    printf("Deleted data is %d",p->data);
    return head;
}

NODE *display(NODE *head)
    {
        NODE *p;
        p=head;
        if(p==NULL)
            printf("Empty list");
        else{
            do
            {
                printf("  |%d|->",p->data);
                p=p->next;
            }
            while(p!=head);
            printf("  head");
        }
        return head;
    }
    


