#include<stdio.h>
void main()
{
	int a[10][10],b[10][10],c[10][10],i,j,k;
	int r1,c1,r2,c2;
	printf("enter the rows and colomns I:");
	scanf("%d %d",&r1,&c1);
	printf("enter the rows and colomns II:");
	scanf("%d %d",&r2,&c2);cc
	if(c1!=r2)
	{
		printf("multiplication not possible");
		exit(0);
	}
	for(i=0;i<=r1;i++)
	{
		for(j=0;j<=c1;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	for(i=0;i<=r2;i++)
	{
		for(j=0;j<=c2;j++)
		{
			scanf("%d",&b[i][j]);
		}
	}
	for(i=0;i<=r1;i++)
	{
		for(j=0;j<=c2;j++)
		{
			c[i][j]=0;
			for(k=0;k<r2;k++)
			{
				
				c[i][j]+=a[i][k]*b[k][j];
			}
		}
	}
	
	for(i=0;i<=r1;i++)
	{
		for(j=0;j<=c2;j++)
		{
			printf("\t %d",c[i][j]);
		}
		printf("\n");
	}
}
