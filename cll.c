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
NODE *search(NODE*);


int main()
{
    NODE *head = NULL;
    create(head);
	int ch,opt,ch1;
	while(1)
	{
	    printf("\n1.Insert at beg.\n2.Insert at end\n3.Insert at any pos.\n4.Delete from end\n5.Delete from begining\n6.Delete from any position\n7.Delete at specific value\n8.Reverse List\n9.Search value\n10.Display\n11.exit\n");
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
                printf("\n1.delete after node\n2.delete before node\n3.delete at specific position\n4.Exit\n");
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
            /*case 9:
                head=sort(head);
                break;*/
	    	case 9:
                head=search(head);
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
	NODE *p,*q;
	p=(NODE*)malloc(sizeof(NODE));
	printf("enter the data: ");
	scanf("%d",&p->data);
	if(head==NULL)
	{
		head=p;
		head->next= head;
	}
	else
	{
		q=head;
        while(q->next!=head)
        {
            q=q->next;
        }
        p->next=head;
        head=p;
        q->next=head;
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
		head->next= head;
	}
	else
	{
		q=head;
		while(q->next!=head)
		{
			q=q->next;
		}
		q->next = p;
		p->next = head;
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
	while(i!=pos&&q->next!=head)
	{
		q=q->next;
		i++;
	}
	if(i==pos&&q->next!=head)
	{
		p->next=q->next;
		q->next=p;
	}
	else if(i==pos&&q->next==head)
	{
		q->next=p;
		p->next=head;
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
	if(head->next==head)
	{
		p->next=head;
		head=p;
	}
	else
	{
		while(i!=pos&&q->next!=head)
		{
			q=q->next;
			i++;
		}
		if(i==pos&&q->next!=head)
		{
			p->next=q->next;
			q->next=p;
		}
		else if(i==pos&&q->next==head)
		{
			q->next=p;
			p->next=head;
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
	if(head->next==head)
	{
		p->next=head;
		head=p;
	}
	else
	{
		while(i!=pos&&q->next!=head)
		{
			q=q->next;
			i++;
		}
		if(i==pos&&q->next!=head)
		{
			p->next=q->next;
			q->next=p;
		}
		else if(i==pos&&q->next==head)
		{
			q->next=p;
			p->next=head;
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
        while(r->next!=head)
        {
            q=r;
            r=r->next;
        }
        q->next=head;
        r->next=NULL;
        printf("\nDeleted value: %d",r->data);
    }
    
    return head;
}

NODE *display(NODE *head)
{
	NODE *p=head;
	if(head==NULL)
	printf("Empty list.");
	else
	{
		p=head;
		printf("The list is :");
		do
		{
			printf("|%d|->",p->data);
			p=p->next;
		}
		while(p!=head);
		printf("Head");
	    
	    
    } 
    return head;   
}

NODE *del_beg(NODE *head)
{
    NODE *q,*p;
    if(head==NULL)
    {
        printf("\nEMPTY LIST\n");
    }
    else
    {
        p=head;
        if(head->next==head)
        {
        	printf("Deleted data is %d.",head->data);
            head=NULL;
		}	
        else
        {
        	q=head;
        	while(p->next!=head)
        	    p=p->next;
            head=head->next;
            p->next=head;
            q->next=NULL;
            printf("Deleted data is %d.",q->data);
        }
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
        if(head->next==head&&head->data==key)
        {
            printf("Deleted value is: %d",head->data);
            head=NULL;
        }
        else
        {
            q=p;
            while(p->next!=head&&p->data!=key)
            {
                q=p;
                p=p->next;
            }
            if(p->data==head->data&&p->next!=head)
            {
                head=head->next;
                p->next=NULL;
                printf("Deleted value is: %d",p->data);
            }
            else if(p->data==key&&p->next==head)
            {
                q->next=head;
                printf("Deleted value is: %d",p->data);
            }
            else  if(p->data==key&&p->next!=head)
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
            
            while(p->next!=head&&i!=key)
            {
                q=p;
                p=p->next;
                i++;
            }
            if(key==1&&p->next!=head)
            {
                head=head->next;
                p->next=NULL;
                printf("Deleted data is: %d",p->data);
            }
            else if(p->next==head&&i==key)
            {
                q->next=head;
                printf("Deleted data is %d",p->data);
            }
            else if(p->next!=head&&i==key)
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
        if(head->next==head&&key==1)
        {
            printf("Node doesn't exit");
        }
        else
        {
        
            q=p;
            i=1;
            
            while(p->next!=head&&i!=key)
            {
                q=p;
                p=p->next;
                i++;
            }
            if(i==key&&p->next==head)
            {
                q->next=head;
                printf("Deleted data is: %d",p->data);
            }
            else if(p->next==head)
            {
                printf("Position doesn't exist");
            }
            else if(p->next!=head&&i==key)
            {
                q->next=p->next;
                p->next=head;
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
        if(head->next==head&&key==1)
        {
            printf("Node doesn't exit");
        }
        else
        {
        
            q=p;
            i=1;
            
            while(p->next!=head&&i!=key)
            {
                q=p;
                p=p->next;
                i++;
            }
            if(key==1&&p->next!=head)
            {
                head=head->next;
                q->next=head;
                printf("Deleted data is: %d",p->data);
            }
            else if(i==0)
            {
                printf("Position doesn't exist");
            }
            else if(p->next!=head&&i==key)
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
        while(p->next!=head)
        {
            
            q=head;
            while(q->next!=head)
            {
                r=q;
                q=q->next;
            }
            if(i==1)
            {
                
                head=q;
                r->next=head;
                q->next=p;
                l=q;
            }
            else if(p->next!=head)
            {
                q->next=l->next;
                l->next=q;
                l=l->next;
                r->next=head;
            }
            i++;
            
        }
        printf("\nList reverse \n");
    }
    return head;
}

NODE *search(NODE *head)
{
    int i=1,value,f=0;
    NODE *p,*q;
    p=head;
    q=head;
    if(head==NULL)
        printf("\nEmpty list\n");
    else
    {
        printf("Enter data which do you want search: ");
        scanf("%d",&value);
        while(p->next!=head&&q->data!=value)
        {
            p=p->next;
            q=q->next;
            i++;
        }
        if(q->data==value)
        {
            printf("The value %d is found at %d index",value,i);
            f++;
        }
        else
        {
            printf("\nwrong input\n");
        }
    }
    return head;

}