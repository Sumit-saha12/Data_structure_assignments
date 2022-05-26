#include<stdio.h>
#include<stdlib.h>

struct node
{
    struct node *prev;
    int data;
    struct node *next;
};
typedef struct node NODE;
NODE *push(NODE *,int);
NODE *pop(NODE *);
NODE *display(NODE *);

int main()
{
    int max,ch,data;
    NODE *top;
    int t=-1;
    top=NULL;
    printf("Stack length: ");
    scanf("%d",&max);
    while (1)
    {
    
        printf("\n1.FOR PUSH\n2.FOR POP\n3.DISPLAY\n4.EXIT\n");
        printf("Enter your choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                if(t==max-1)
                {
                    printf("\nSTACK IS OVERFLOW\n");
                }
                else
                {
                printf("Enter the data: ");
                scanf("%d",&data);
                top=push(top,data);
                t++;
                }
                break;
            case 2:
                if(t==-1)
                    printf("\nEmpty stack\n");
                else
                {
                    top=pop(top);
                    t--;
                }
                break;
            case 3:
                top=display(top);
                break;
            case 4:
                printf("\nOperation exit\n");
                exit(1);
            default:
                printf("\nWrong choice\n");
        }
    }    
    return 0;
}

NODE *push(NODE *top,int data)
{
    
    
    NODE *nw1;
    nw1=(NODE*)malloc(sizeof(NODE));
    
    

        
    nw1->data=data;
    if(top==NULL)
    {
            top=nw1;
            nw1->next=NULL;
            nw1->prev=NULL;
    }
    else
    {
            nw1->next=top;
            nw1->prev=NULL;
            top=nw1; 
    }
    
        
    return top;
}

NODE *pop(NODE *top)
{
    int data;
    NODE *p=top;
    
        if(top->next==NULL)
        {
            data=top->data;
            top=NULL;
        }
        else
        {
            data=p->data;
            top=top->next;
            p->next=NULL;
            top->prev=NULL;
        }
        printf("The deleted data is %d",data);
        
    
    return top;
}

NODE *display(NODE *top)
{
    NODE *p;
    p=top;
    if(top==NULL)
        printf("\nStack is empty\n");
    else
    {
        printf("\nNULL\n");

        while(p!=NULL)
        {
           
           
            printf("\n|%d|\n",p->data);

            p=p->next;
        }
        printf("\nNULL\n");
    }
    return top;
}