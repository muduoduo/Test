#include "lib.h"
#ifdef PALINDROME
/*
*
*	回文字符串是指从左到右和从右到左相同的字符串，现给定一个仅由小写字母组成的字符串，你可以把它的字母重新排列，以形成不同的回文字符串。
*
*	输入：非空仅由小写字母组成的字符串，长度不超过100；
*	输出：能组成的所有回文串的个数（因为结果可能非常大，输出对1000000007取余数的结果）。
*
*	例如：输入"aabb" 输出为2（因为“aabb”对应的所有回文字符串有2个：abba和baab）
*
*/
#include <stdio.h>
#include <string.h>
#define MOD 1000000007

void discompose(int n,int *a,int step)
{
	int i;
	for (i=2;i<n+1;i++)
	{
		if(n%i==0)
		{
			a[i]+=step;
			n=n/i;
			i=1;
		}
	}
}

int palindrome(const char *s)
{
	int len=strlen(s);
	int i,t=0;
	long long count=1;
	int mark[200]={0},factorial[51]={0};

	for (i=0;i<len;i++)
		mark[s[i]]++;

	for (i=0;i<200;i++)
		t+=mark[i] & 1;
	if(t>1) return 0;

	for (i=2;i<((len>>1)+1);i++)
		discompose(i,factorial,1);

	for (i=0;i<200;i++)
		if((mark[i]/=2)>1)
			for(t=2;t<mark[i]+1;t++)
				discompose(t,factorial,-1);

	for (i=2;i<51;i++)
		for (t=0;t<factorial[i];t++)
			count=(count*i)%MOD;

	return (int)count;
}
#endif