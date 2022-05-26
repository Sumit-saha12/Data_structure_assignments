/******************************************************************************
                            SUMIT SAHA
                      M.SC IN DATA SCIENCE    
                 BINARY SEARCH WITH RECURSIVE                    

******************************************************************************/



#include<stdio.h>

int binarysearch(int *a,int l,int u, int key)
{
   
    int mid;
    if(l>u)
    {
     
        return -1;
    }
    else
    {
        mid = (l+u)/2;
        if(a[mid]==key)
        {
            
            return mid;
        }
        else if(a[mid]>key)
        {
            binarysearch(a,l,mid-1,key);
        }
        else
        {
            binarysearch(a,mid+1,u, key);
        }
    }
}


int main()
{
    int i,j,n,l,u,mid,key,f;
    printf("Enter the element length: ");
    scanf("%d",&n);
    int a[n];
    for(i=0;i<n;i++)
    {
        printf("Enter %d element: ",i);
        scanf("%d",&a[i]);
    }
    printf("\nElements are:\n");
    for(i=0;i<n;i++)
    {
        printf("  %d\n",a[i]);
    }
    f=0;
   for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(a[j]>a[j+1])
            {
                int temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
                int f=1;
            }
        }
    }
    printf("\nAfter sorting elements are:\n");
    for(i=0;i<n;i++)
    {
        printf("  %d\n",a[i]);
    }
    l=0;
    u=n-1;
    mid = (l+u)/2;
    printf("\nEnter the element which do you want search: \n");
    scanf("%d",&key);
    int result=binarysearch(a,l,u,key);
    if(result==-1)
    {
        printf("%d is not found",key);
    }
    else  
    {
        printf("%d is found at %dth position",key,mid);   
    }
    
}
