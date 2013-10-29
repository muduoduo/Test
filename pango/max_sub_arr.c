#include <stdio.h>
/*
  最大数组长度 暴力法， 分治法
*/

void max_sub_arr(int *a,int n)
{
	int i,j,c,m=1<<31,l,h; 
	for(i=0;i<n;i++)
	{
		c=0; 
		for(j=i;j<n;j++)
		{
			c+=a[j];
			if(c>=m) 
				m=c,l=i,h=j;
		}
	}		
	printf("%d->%d:%d\n",l,h,m);
}

int max_sub_arr1(int *a, int n)
{
	int mid=n>>1;
	int i,max,rmax,lmax=rmax=1<<31,t;
	if(n<2) return a[0];
	i=mid-1;
	t=0;
	while(a+i>=a)
	{
		t+=a[i--];
		if (t>lmax)
			lmax=t;
	}
	i=mid+1;
	t=0;
	while(a+i<a+n)
	{
		t+=a[i++];
		if (t>rmax)
			rmax=t;
	}
	max=a[mid]+(lmax>0?lmax:0)+(rmax>0?rmax:0);
	lmax=max_sub_arr1(a,mid);
	rmax=max_sub_arr1(a+mid+1,n-mid-1);
	return (max>lmax) && (max>rmax)? max : lmax>rmax ? lmax : rmax;
}