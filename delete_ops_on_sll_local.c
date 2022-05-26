#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
typedef struct node NODE;
NODE *ins_beg(NODE*);
NODE *ins_end(NODE*);
NODE *ins_after_node(NODE*);
NODE *ins_bef_node(NODE*);
NODE *ins_spec_pos(NODE*);
NODE *create(NODE*);
NODE *display(NODE*);
NODE *del_beg(NODE*);
NODE *del_end(NODE*);
NODE *del_spec_pos(NODE*);
NODE *del_spec_val(NODE*);
NODE *del_after_pos(NODE*);
NODE *del_before_pos(NODE*);
NODE *reverse(NODE*);
NODE *sort(NODE*);


int main()
{
    NODE *head = NULL;
    create(head);
	int ch,opt,ch1;
	while(1)
	{
	    printf("\n1.Insert at beg.\n2.Insert at end\n3.Insert at any pos.\n4.Delete from end\n5.Delete from begining\n6.Delete from any position\n7.Delete at specific value\n8.Reverse List\n9.Sort List\n10.Display\n11.Exit\n");
	    printf("enter your choice: ");
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
		    	printf("\n1.Insert after node\n2.Insert before node\n3.Insert specific pos\n4.Exit\n");
		    	printf("\nenter your choice: ");
		    	scanf("%d",&opt);
		    	switch(opt)
			    {
			    	case 1:
			    		head=ins_after_node(head);
			    		break;
			    	case 2:
			    		head=ins_bef_node(head);
			    		break;
			    	case 3:
				    	head=ins_spec_pos(head);
				    	break;
                    case 4:
                        printf("\nOperation Exit\n");
                        exit(1);
                    default:
                        printf("\nWrong choice\n");    
		    	}
		    	break;
		    case 4:
		    	head=del_end(head);
                break;
		    case 5:
			    head=del_beg(head);
                break;
            case 6:
                printf("\n1.delete after node\n2.delete before node\n3.delete at specific position\n4.Exit");
                printf("Enter your choice: ");
                scanf("%d",&ch1);
                switch(ch1)
                {
                    case 1:
                        head=del_after_pos(head);
                        break;                            
                    case 2:
                        head=del_before_pos(head);
                        break;
                    case 3:
                        head=del_spec_pos(head);
                        break;
                    case 4:
                        printf("\nOperation Exit\n");
                        exit(1);
                    default:
                        printf("\nWrong choice\n");       
                }
				break;
            case 7:
                head=del_spec_val(head);
                break;
            case 8:
                head=reverse(head);
                break;
            case 9:
                head=sort(head);
                break;
	    	case 10:
                display(head);
                break;
            case 11:
                printf("\nOPERATION EXIT\n");
                exit(1);
            default:
                printf("\nWrong choice\n");        
	    }
	}
	return 0;
}

NODE *create(NODE *head)
{
    NODE *p;
	p=(NODE*)malloc(sizeof(NODE));
	return p;
}

NODE *ins_beg(NODE *head)
{
	NODE *p;
	p=(NODE*)malloc(sizeof(NODE));
	printf("enter the data: ");
	scanf("%d",&p->data);
	if(head==NULL)
	{
		head=p;
		head->next= NULL;
	}
	else
	{
		p->next = head;
		head=p;
	}
	return head;
}

NODE *ins_end(NODE *head)
{
	NODE *p,*q;
	p=(NODE*)malloc(sizeof(NODE));
	printf("enter the data: ");
	scanf("%d",&p->data);
	if(head==NULL)
	{
		head=p;
		head->next= NULL;
	}
	else
	{
		q=head;
		while(q->next!=NULL)
		{
			q=q->next;
		}
		q->next = p;
		p->next = NULL;
	}
	return head;
}

NODE *ins_after_node(NODE *head)
{
	NODE *p,*q;
	p=(NODE*)malloc(sizeof(NODE));
	int i=1,pos;
	q=head;
	printf("enter the data: ");
	scanf("%d",&p->data);
	printf("enter position: ");
	scanf("%d",&pos);
	while(i!=pos&&q->next!=NULL)
	{
		q=q->next;
		i++;
	}
	if(i==pos&&q->next!=NULL)
	{
		p->next=q->next;
		q->next=p;
	}
	else if(i==pos&&q->next==NULL)
	{
		q->next=p;
		p->next=NULL;
	}
	else
	{
		printf("position not exist\n");
	}
	return head;
	
}

NODE *ins_bef_node(NODE *head)
{
	NODE *p,*q;
	p=(NODE*)malloc(sizeof(NODE));
	int i=1,pos;
	q=head;
	printf("enter the data: ");
	scanf("%d",&p->data);
	printf("enter position: ");
	scanf("%d",&pos);
	pos=pos-1;
	if(head->next==NULL)
	{
		p->next=head;
		head=p;
	}
	else
	{
		while(i!=pos&&q->next!=NULL)
		{
			q=q->next;
			i++;
		}
		if(i==pos&&q->next!=NULL)
		{
			p->next=q->next;
			q->next=p;
		}
		else if(i==pos&&q->next==NULL)
		{
			q->next=p;
			p->next=NULL;
		}
		else
		{
			printf("position not exist\n");
		}
	}
	return head;
}

NODE *ins_spec_pos(NODE *head)
{
	NODE *p,*q;
	p=(NODE*)malloc(sizeof(NODE));
	int i=1,pos;
	q=head;
	printf("enter the data: ");
	scanf("%d",&p->data);
	printf("enter position: ");
	scanf("%d",&pos);
	pos=pos-1;
	if(head->next==NULL)
	{
		p->next=head;
		head=p;
	}
	else
	{
		while(i!=pos&&q->next!=NULL)
		{
			q=q->next;
			i++;
		}
		if(i==pos&&q->next!=NULL)
		{
			p->next=q->next;
			q->next=p;
		}
		else if(i==pos&&q->next==NULL)
		{
			q->next=p;
			p->next=NULL;
		}
		else
		{
			printf("position not exist\n");
		}
	}
	return head;
}

NODE *del_end(NODE *head)
{
    NODE *r,*q;
    r=head;
    if(head==NULL)
    {
        printf("\nEmpty list\n");
    }
    else
    {
        while(r->next!=NULL)
        {
            q=r;
            r=r->next;
        }
        q->next=NULL;
    }
    printf("\nDeleted value: %d",r->data);
    return head;
}

NODE *display(NODE *head)
{
	NODE *q=head;
    if(head==NULL)
    {
        printf("\nEmpty list\n");
    }
    else
    {    
	    while(q!=NULL)
	    {
		    printf("|%d|->",q->data);
	
		    if(q->next==NULL)
		    {
		     printf("NULL");
		    }
		    q=q->next;
	    }
	    
    } 
    return head;   
}

NODE *del_beg(NODE *head)
{
    NODE *q;
    if(head==NULL)
    {
        printf("\nEMPTY LIST\n");
    }
    else
    {
        q=head;
        head=head->next;
        q->next=NULL;
        printf("Deleted data is: %d",q->data);
    }
    return head;
}

NODE *del_spec_val(NODE *head)
{
    int key;
    NODE *q,*p=head;
    
    if(head==NULL)
    {
        printf("\nEmpty list\n");
    }
    else
    {
        printf("\nEnter the value do you want delete: \n");
        scanf("%d",&key);
        if(head->next==NULL&&head->data==key)
        {
            printf("Deleted value is: %d",head->data);
            head=NULL;
        }
        else
        {
            q=p;
            while(p->next!=NULL&&p->data!=key)
            {
                q=p;
                p=p->next;
            }
            if(p->data==head->data&&p->next!=NULL)
            {
                head=head->next;
                p->next=NULL;
                printf("Deleted value is: %d",p->data);
            }
            else if(p->data==key&&p->next==NULL)
            {
                q->next=NULL;
                printf("Deleted value is: %d",p->data);
            }
            else  if(p->data==key&&p->next!=NULL)
            {
                q->next=p->next;
                p->next=NULL;
                printf("Deleted value: %d",p->data);
            }
            else
            {
                printf("\nWrong input\n");
            }
        }
    }
    return head;    
}

NODE *del_spec_pos(NODE *head)
{
    NODE *p=head,*q;
    int i,key;
    if(head==NULL)
    {
        printf("EMPTY LIST");
    }
    else
    {
        printf("Enter position for delete data: ");
        scanf("%d",&key);
        if(head->next==NULL&&key==0)
        {
            printf("Deleted data is: %d",head->data);
            head=NULL;
        }
        else
        {
        
            q=p;
            i=1;
            
            while(p->next!=NULL&&i!=key)
            {
                q=p;
                p=p->next;
                i++;
            }
            if(key==1&&p->next!=NULL)
            {
                head=head->next;
                p->next=NULL;
                printf("Deleted data is: %d",p->data);
            }
            else if(p->next==NULL&&i==key)
            {
                q->next=NULL;
                printf("Deleted data is %d",p->data);
            }
            else if(p->next!=NULL&&i==key)
            {
                q->next=p->next;
                p->next=NULL;
                printf("Deleted data is %d",p->data);
            }
            else
                printf("\nPosition doesn't exist\n");
        }        
    }
    return head;
}

NODE *del_after_pos(NODE *head)
{
    NODE *p=head,*q;
    int i,key;
    if(head==NULL)
    {
        printf("EMPTY LIST");
    }
    else
    {
        printf("Enter position for delete data: ");
        scanf("%d",&key);
        key=key+1;
        if(head->next==NULL&&key==1)
        {
            printf("Node dpesn't exit");
        }
        else
        {
        
            q=p;
            i=1;
            
            while(p->next!=NULL&&i!=key)
            {
                q=p;
                p=p->next;
                i++;
            }
            if(i==key&&p->next==NULL)
            {
                q->next=NULL;
                printf("Deleted data is: %d",p->data);
            }
            else if(p->next==NULL)
            {
                printf("Position doesn't exist");
            }
            else if(p->next!=NULL&&i==key)
            {
                q->next=p->next;
                p->next=NULL;
                printf("Deleted data is %d",p->data);
            }
            else
                printf("\nPosition doesn't exist\n");
        }        
    }
    return head;
}

NODE *del_before_pos(NODE *head)
{
    NODE *p=head,*q;
    int i,key;
    if(head==NULL)
    {
        printf("EMPTY LIST");
    }
    else
    {
        printf("Enter position for delete data: ");
        scanf("%d",&key);
        key=key-1;
        if(head->next==NULL&&key==1)
        {
            printf("Node doesn't exit");
        }
        else
        {
        
            q=p;
            i=1;
            
            while(p->next!=NULL&&i!=key)
            {
                q=p;
                p=p->next;
                i++;
            }
            if(key==1&&p->next!=NULL)
            {
                head=head->next;
                q->next=NULL;
                printf("Deleted data is: %d",p->data);
            }
            else if(i==0)
            {
                printf("Position doesn't exist");
            }
            else if(p->next!=NULL&&i==key)
            {
                q->next=p->next;
                p->next=NULL;
                printf("Deleted data is %d",p->data);
            }
            else
                printf("\nPosition doesn't exist\n");
        }        
    }
    return head;
}
NODE *reverse(NODE *head)
{
    NODE *p,*q,*r,*l;
    int i=1;
    p=head;
    if(head==NULL)
    {
        printf("Empty list");
    }
    else
    {
        while(p->next!=NULL)
        {
            
            q=head;
            while(q->next!=NULL)
            {
                r=q;
                q=q->next;
            }
            if(i==1)
            {
                q->next=head;
                head=q;
                r->next=NULL;
                l=q;
            }
            else if(p->next!=NULL)
            {
                q->next=l->next;
                l->next=q;
                l=l->next;
                r->next=NULL;
            }
            i++;
            
        }
        printf("\nList reverse \n");
    }
    return head;
}

NODE *sort(NODE *head)
{
    NODE *p=head,*q;
    int temp;
    if(head==NULL)
    {
        printf("Empty list");
    }
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
    
    printf("\nLIST SORTED\n");
    return head;
}