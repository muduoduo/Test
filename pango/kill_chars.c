#include "lib.h"
#ifdef KILL_CHARS
/*
*
*	给定一个字符串，仅由a,b,c 3种小写字母组成。当出现连续两个不同的字母时，你可以用另外一个字母替换它，如
*
*	有ab或ba连续出现，你把它们替换为字母c；
*	有ac或ca连续出现时，你可以把它们替换为字母b；
*	有bc或cb 连续出现时，你可以把它们替换为字母a。
*
*	你可以不断反复按照这个规则进行替换，你的目标是使得最终结果所得到的字符串尽可能短，求最终结果的最短长度。
*
*	输入：字符串。长度不超过200，仅由abc三种小写字母组成。
*	输出： 按照上述规则不断消除替换，所得到的字符串最短的长度。
*
*	例如：输入cab，输出2。因为我们可以把它变为bb或者变为cc。
*	输入bcab，输出1。尽管我们可以把它变为aab -> ac -> b，也可以把它变为bbb，但因为前者长度更短，所以输出1。
*
*/
#include <stdio.h>
#include <string.h>
#define swap(a,b) a^=b^=a^=b
int minLength(const char *s)
{
	char stack[201],tmp;
	int i,j,top,len=strlen(s);
	int min_len=300,sum='a'+'b'+'c';
	for(i=0;i < len;i++)
	{
		top=0;
		for (j=i-1;j>-1;j--)
		{
			stack[top++]=s[j];
			while(top>1 && stack[top-1] != stack[top-2])
			{
				stack[top-2]=sum-stack[top-1]-stack[top-2];
				top--;
			}
		}
		for (j=0;j<top;j++)
			swap(stack[j],stack[top-1-j]);
		for (j=i;j<len;j++)
		{
			stack[top++]=s[j];
			while(top>1 && stack[top-1] != stack[top-2])
			{
				stack[top-2]=sum-stack[top-1]-stack[top-2];
				top--;
			}
		}
		if(top<min_len)
			min_len=top;
	}
	return min_len;
}

#endif