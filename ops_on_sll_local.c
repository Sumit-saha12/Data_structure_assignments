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


int main()
{
    NODE *head = NULL;
    create(head);
	int ch,opt;
	while(1)
	{
	    printf("\n1.insert at beg.\n2.insert at end\n3.insert at any pos.\n4.display\n5.exit\n");
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
		    	printf("\n1.insert after node\n2.insert before node\n3.insert specific pos\n4.delete from beginning");
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
		    	}
		    	break;
		    case 4:
		    	head=display(head);
		    	break;
		    case 5:
			    printf("\noperation exit\n");
		    	exit(1);
	    	default:
		    	printf("\nwrong input........please try again!!!!!!\n");
		    	break;
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

NODE *display(NODE *head)
{
	NODE *q=head;
	while(q!=NULL)
	{
		printf("|%d|->",q->data);
	
		if(q->next==NULL)
		{
		    printf("NULL");
		}
		q=q->next;
	}
	return head;
}
