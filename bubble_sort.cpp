#include<stdio.h>
int main()
{
	int n,i,f,t,j;
	printf("Enter the element length: ");
	scanf("%d",&n);
	int a[n];
	for(i=0;i<n;i++)
	{
		printf("\nEnter the %dth element: \n",i);
		scanf("%d",&a[i]);
	}
	printf("Elements are: \n");
	for(i=0;i<n;i++)
	{
		printf("   %d\n",a[i]);
	}
	for(i=0;i<n-1;i++)
	{
		f=0;
		for(j=0;j<n-i-1;j++)
		{
			if(a[j]>a[j+1])
			{
				t=a[j];
				a[j]=a[j+1];
				a[j+1]=t;
				f=1;
			}
		}
		if(f==0)
			break;
	}
	printf("After sorting elements are: \n");
	for(i=0;i<n;i++)
	{
		printf("   %d\n",a[i]);
	}
}
