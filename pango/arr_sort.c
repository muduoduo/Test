#include "lib.h"
#ifdef ARR_SORT
/*
*
*	给定一个包含1-n的数列，我们通过交换任意两个元素给数列重新排序。求最少需要多少次交换，能把数组排成按1-n递增的顺序，其中，数组长度不超过100。
*	例如：
*	原数组是3,2,1， 我们只需要交换1和3就行了，交换次数为1，所以输出1。
*	原数组是2,3,1，我们需要交换2和1，变成1,3,2，再交换3和2，变为1，2，3，总共需要的交换次数为2，所以输出2。
*
*/
#include <malloc.h>

void  swap(int *a,int *b)
{
	int c;
	c=*a;
	*a=*b;
	*b=c;
}
int run(const int *a,int n)
{
	int *arr=malloc(sizeof(int)*(n+1));
	int i,count=0;
	for (i=1;i<n+1;i++)
		arr[i]=a[i-1];
	for (i=1;i<n+1;i++)
	{
		while (arr[i]!=i)
		{
			swap(arr+i,arr+arr[i]);
			count++;
		}
	}
	return count;
}
#endif
