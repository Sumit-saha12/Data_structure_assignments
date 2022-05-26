#include<stdio.h>
#include<stdlib.h>

struct node
{
    struct node *prev;
    int data;
    struct node *next;
};
typedef struct node NODE;
NODE *ins_beg(NODE *);
NODE *ins_end(NODE *);
NODE *ins_any(NODE *);
NODE *del_beg(NODE *);
NODE *del_end(NODE *);
NODE *del_any(NODE *);
NODE *sort(NODE *);
NODE *reverse(NODE *);
NODE *display(NODE *);


int main()
{
    NODE *head;
    int ch,ch1,ch2;
    head=(NODE*)malloc(sizeof(NODE));
    head=NULL;
    while(1)
    {
        printf("\n**********MENU*********\n");
        printf("1.INSERT AT BEGINNING\n");
        printf("2.INSERT AT END \n");      
        printf("3.INSERT ANY POSITION\n");
        printf("4.DELETE AT BEGINNING\n");
        printf("5.DELETE AT END\n");
        printf("6.DELETED ANY POSITION\n");
        printf("7.SORT LIST\n");
        printf("8.REVERSE LIST\n");
        printf("9.DISPLAY\n");
        printf("\nEnter the choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                head=ins_beg(head);
                break;
            case 2:
                head=ins_end(head);
                break;
            case 3:
                head=ins_any(head);
                
                break;
            case 4:
                head=del_beg(head);
                break;
            case 5:
                head=del_end(head);
                break;
            case 6:
                head=del_any(head);
                break;
            case 7:
                head=sort(head);
                break;
            case 8:
                head=reverse(head);
                break;
            case 9:
                head=display(head);
                break;
            default:
                printf("\nWrong choice\n");
                break;
        }
    }
}

NODE *ins_beg(NODE *head)
{
    NODE *nw1;
    nw1=(NODE*)malloc(sizeof(NODE));
    int i,data;
    printf("Enter the data: ");
    scanf("%d",&data);
    nw1->data=data;
    if(head==NULL)
    {
        nw1->next=NULL;
        nw1->prev=NULL;
        head=nw1;
    }
    else
    {
      
        
        nw1->next=head;
        
        nw1->prev=NULL;
        head->prev=nw1;
        head=nw1;
    }
    return head;

}

NODE *display(NODE *head)
{
    NODE *p=head;
    if(head==NULL)
        printf("Empty list\n");
    else
    {
        printf("NULL <=>");
        while(p!=NULL)
        {
            printf("|%d| <=>",p->data);
            p=p->next;
            
        }
        printf("NULL");

    }
    return head;
}

NODE *ins_end(NODE *head)
{
    int data;
    NODE *p;
    NODE *nw2;
    nw2=(NODE*)malloc(sizeof(NODE));
    printf("Enter the data: ");
    scanf("%d",&nw2->data);
    if(head==NULL)
    {
        nw2->prev=NULL;
        nw2->next=NULL;
        head=nw2;
    }
    else
    {
        p=head;
        while(p->next!=NULL)
        {
           
            p=p->next;
            
        }
        p->next=nw2;
        nw2->prev=p;
        nw2->next=NULL;

    }
    return head;
}

NODE *ins_any(NODE *head)
{
    int i=1,pos,data;
    NODE *p,*q;
    NODE *nw2;
    nw2=(NODE*)malloc(sizeof(NODE));
    printf("Enter position: ");
    scanf("%d",&pos);
    printf("Enter the data: ");
    scanf("%d",&nw2->data);
    if(head==NULL&&pos==1)
    {
      nw2->next=NULL;
      nw2->prev=NULL;
      head=nw2;
    }
    else
    {
        p=head;
        while(p!=NULL&&i!=pos)
        {
            q=p;
            i++;
            p=p->next;
            
        }
        if(pos==1&&head->next!=NULL)
        {
           head->prev=nw2;
           nw2->next=head;
           nw2->prev=NULL;
           head=nw2;
        }
        
        else if(i==pos&&p->next==NULL)
        {
            q->next=nw2;
            nw2->prev=q;
            nw2->next=p;
            p->prev=nw2;
        }
        else if(i==pos&&p->next!=NULL)
        {
            q->next=nw2;
            nw2->prev=q;
            nw2->next=p;
            p->prev=nw2;
        }
        else
            printf("\nWrong position\n");

    }
    return head;
}

NODE *del_beg(NODE *head)
{
    NODE *p,*q;
    if(head==NULL)
        printf("Empty list\n");
    else
    {
        if(head->next==NULL)
        {
            printf("Deleted data is %d",head->data);
            head=NULL;
        }
        else
        {
            p=head;
            q=p;
            head=p->next;
            p=head;
            p->prev=NULL;
            printf("Deleted data is %d",q->data);
        }
    }
    return head;
}

NODE *del_end(NODE *head)
{
    NODE *p,*q;
    if(head==NULL)
    {
        printf("Empty list\n");
    }
    else
    {
        if(head->next==NULL)
        {
            printf("Deleted data is %d",head->data);
            head=NULL;
        }
        else
        {
            p=head;
            while(p->next!=NULL)
            {
                q=p;
                p=p->next;

            }
            q->next=NULL;
            printf("Deleted data is %d",p->data);
        }
    }
    return head;
}
NODE *del_any(NODE *head)
{
    NODE *p,*q,*r;
    int i=1,pos;
    printf("Enter position: ");
    scanf("%d",&pos);
    if(head==NULL)
        printf("Empty list\n");
    else
    {
        p=head;
        while(i!=pos&&p!=NULL)
        {
            q=p;
            p=p->next;
            i++;
        }
        if(pos==1&&head->next==NULL)
        {
            printf("Deleted data is %d",head->data);
            head=NULL;
        }
        else if(pos==1&&head->next!=NULL)
        {
            head=p->next;
            printf("Deleted data is %d",p->data);
            p=head;
        }
        else if(i==pos&&p->next==NULL)
        {
            q->next=NULL;
            printf("Deleted data is %d",p->data);
        }
        else if(i==pos&&p->next!=NULL)
        {
           r=p->next;
           q->next=r;
           r->prev=q;
           printf("Deleted data is %d",p->data);

        }
        else
            printf("Wrong input\n");
    }
    return head;

}

NODE *sort(NODE *head)
{
    NODE *p,*q;
    int temp;
    p=head;
    if(head==NULL)
        printf("Empty list\n");
    else
    {
        while(p->next!=NULL)
        {
            q=p->next;
            while(q!=NULL)
            {
                if(p->data>q->data)
                {
                    temp=p->data;
                    p->data=q->data;
                    q->data=temp;
                }
                q=q->next;
            }
            p=p->next;
        }
    }
    printf("List sorted\n");
    return head;
    
}

NODE *reverse(NODE *head)
{
    
	NODE *ptr1,*ptr2;
	ptr1=head;
	ptr2=ptr1->next;
	ptr1->next=NULL;
	ptr1->prev=ptr2;
	while(ptr2!=NULL)
	{
		ptr2->prev=ptr2->next;
		ptr2->next=ptr1;
		ptr1=ptr2;
		ptr2=ptr2->prev;
	}
	head=ptr1;
	
    printf("Reverse list\n");
    return head;
}

