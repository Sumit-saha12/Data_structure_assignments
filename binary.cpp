#include<stdio.h>
int main()
{
    int i,n,j,temp,f,l,u,m,key,flag;
    printf("\nEnter the element size: ");
    scanf("%d",&n);
    int a[n]; 
    for(i=0;i<n;i++)                          //array input
    {
        printf("\nEnter the %dth value: ",i);
        scanf("%d",&a[i]);
    }
    printf("The elements are: \n");
    for(i=0;i<n;i++)                         //array output
    { 
        printf("   %d\n",a[i]);
    }
    for(i=0;i<n-1;i++)                       //bubble sort
    {
        f=0;
        for(j=0;j<n-i-1;j++)
        {
            if(a[j]>a[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
                f=1;
            }
        }
        if(f==0)
            break;
    }
    printf("After sorting the elements are: \n");  //after sort
    for(i=0;i<n;i++)
    {
        printf("   %d\n",a[i]);
    }
    flag=0;
    l=0;
    u=n-1;
    m=l+u/2;
    printf("Enter search element: ");
    scanf("%d",&key);
    while(l<=u)                                //binary search
    {
        m=(l+u)/2;
        if(a[m]==key)
        {
            flag=1;
            break;
        }
        else if(a[m]<key)
        {
            l=m+1;
        }
        else
        {
            u=m-1;
        }
    }
    if(flag==1)
    {
        printf("\nYour element %d position is %d\n",key,m);
    } 
    else
    {
        printf("\n%d is not found\n",key);
    }
}
