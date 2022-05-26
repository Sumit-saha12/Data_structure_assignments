#include<stdio.h>

int main()
{
	int i,n;
	printf("Enter the element size: ");
	scanf("%d",&n);
	int a[n];
	for(i=0;i<n;i++)
	{
		printf("Enter the %dth element: ",i);
		scanf("%d",&a[i]);
	}
	printf("The elements are: \n");
	for(i=0;i<n;i++)
	{
		
		printf("%d\n",a[i]);
	}
	
	for(i=1;i<n;i++)
	{
		t=a[i];
		c=i-1;
		while(c>=0&&a[c]>t)
		{
			a[c+1]=a[c];
			c--;
		}
		t=a[c+1];
	}
	printf("After sorting the elements are: \n");
	for(i=0;i<n;i++)
	{
		
		printf("%d\n",a[i]);
	}
}
	
	
	
