#include<stdio.h>
void main()
{
	int x,y,i,j,max=-9999,z=0,b=0;
	scanf("%d",&x);
	scanf("%d",&y);
	int a[100];
	for(i=0;i<x;i++)
	{
		for(j=0;j<y;j++)
		{
			scanf("%d",&a[z++]);
		}
	}
	//	printf("%d",a[2]);
    for(i=0;i<z;i++)
	{
		for(j=i;j<z;j++)
		{
		   b=a[j]+b;
		   if(b<0) break;
		   if(b>max) max=b;
		}
		b=0;
	}
	printf("%d",max);
}