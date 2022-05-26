#include<stdio.h>
#include<stdlib.h>

struct node
{
    int cof,exp;
    struct node *next;
};
typedef struct node pol;
pol* polynomial(pol *,int);
void display(pol *);
int main()
{
    pol *head1,*head2,*head3,*k;
    int i,n,m,c,e;
    head1=NULL;
    head2=NULL;
    head3=NULL;
    pol *p=head1,*nw1;
    pol *q=head2,*nw2;
    pol *r=head3,*nw3;
    printf("Enter the term of 1st polinomial: ");
    scanf("%d",&n);
    head1=polynomial(head1,n);
    printf("Enter the term of 2nd polinomial: ");
    scanf("%d",&m);
    head2=polynomial(head2,m);
    printf("\nThe first polynomial is: \n");
    display(head1);
    
    printf("\nThe second polynomial is: \n");
    display(head2);
    p=head1;
    q=head2;
    while(p!=NULL&&q!=NULL)
    {
        r=head3;
        if(p->exp==q->exp)
        {
            c=p->cof+q->cof;
            e=p->exp;
            p=p->next;
            q=q->next;
        }
        else if(p->exp>q->exp)
        {
            c=p->cof;
            e=p->exp;
            p=p->next;
        }
        else
        {
            c=q->cof;
            e=q->exp;
            q=q->next;
        }
        nw3=(pol*)malloc(sizeof(pol));
        nw3->cof=c;
        nw3->exp=e;
        if(head3==NULL)
        {
            head3=nw3;
            nw3->next=NULL;
        }
        else
        {
            while(r->next!=NULL)
            {
                r=r->next;
            }
            r->next=nw3;
            nw3->next=NULL;
        }
    }
    printf("\nAddition of two polynomial: \n");
    display(head3);

    return 0;
}


pol* polynomial(pol *head1,int n)
{
    int i;
    pol *p,*nw1,*k;
    for(i=0;i<n;i++)
    {
        p=head1;
        nw1=(pol*)malloc(sizeof(pol));
        printf("\nEnter the coefficient value: ");
        scanf("%d",&nw1->cof);
        printf("\nEnter the exponent value: ");
        scanf("%d",&nw1->exp);
        if(head1==NULL)
        {
            head1=nw1;
            head1->next=NULL;
        }
        else
        {
           
            while(p->next!=NULL)
            {
                p=p->next;
            }
            p->next=nw1;
            nw1->next=NULL;
        }
    }
    return head1;
}

void display(pol *head1)
{
    pol *p;
    for(p=head1;p!=NULL;p=p->next)
    {
        if(p->exp!=0)
        {
            printf(" %dX^%d +",p->cof,p->exp);
        }
        else
        {
            printf(" %d",p->cof);
        }
    }
}