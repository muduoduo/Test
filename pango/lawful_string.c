#include "lib.h"
#ifdef LAWFUL_STRING
/*
*	用n个不同的字符（编号1 - n），组成一个字符串，有如下2点要求：
*	1、对于编号为i 的字符，如果2 * i > n，则该字符可以作为最后一个字符，但如果该字符不是作为最后一个字符的话，则该字符后面可以接任意字符；
*	2、对于编号为i的字符，如果2 * i <= n，则该字符不可以作为最后一个字符，且该字符后面所紧接着的下一个字符的编号一定要 >= 2 * i。
*	问有多少长度为M且符合条件的字符串。
*	例如：N = 2，M = 3。则abb, bab, bbb是符合条件的字符串，剩下的均为不符合条件的字符串。
*
*	输入：n,m  (2<=n,m<=1000000000)；
*	输出：满足条件的字符串的个数，由于数据很大，输出该数Mod 10^9 + 7的结果。
*		
*
*/
#define M 1000000009

int f(int l,int e,int n)
{
	int c=0,i;
	if(l==1)
		return 1;
	else if((e<<(l-1))>n>>1)
		return 0;
	else if(l==2)
		return n-e<<1+1;
	else
		for (i=n-(e<<l-1)+1;i>0;i=i-2)
			c+=i;
	return c;
}

int powx(int n,int k) 
{ 
	int r = 1 ; 
	while(k) 
	{ 
		if(k & 1 ) 
			r *= n; 
		k >>= 1; 
		n *= n; 
	} 
	return r; 
}


int validstring(int n,int m) 
{
	int r=1,c=0,l=1,i,j;
	while((1<<l-1)<n)
	{
		for (i=1;i<n && r;i++)
		{
			r=f(l,i,n);
			for(j=0;j<m-l;j++)
				c=c+r*powx(n>>1,j)*powx(n>>1,m-l-j);
		}
		l++;
	}
	c+=powx(n>>1,m);
}

#endif
