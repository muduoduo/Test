#include "lib.h"
#ifdef PERFECT_STRING
/*
*
*	我们要给每个字母配一个1-26之间的整数，具体怎么分配由你决定，但不同字母的完美度不同，
*	而一个字符串的完美度等于它里面所有字母的完美度之和，且不在乎字母大小写，也就是说字母F和f的完美度是一样的。
*
*	现在给定一个字符串，输出它的最大可能的完美度。
*	例如：dad，你可以将26分配给d，25分配给a，这样整个字符串最大可能的完美度为77。
*
*/
#include <ctype.h>
#include <string.h>
#include <stdio.h>

int perfect(const char *s)
{
	int len=strlen(s);
	int i,j,mark[256],cost[256];
	int max_cost=26,sum=0,max,max_pos=0;
	for (i=0;i<256;i++)
		mark[i]=cost[i]=0;
	for (i=0;i<len;i++)
		mark[tolower(s[i])]++;
	while(max_cost>0)
	{
		max=0;
		for (j=0;j<256;j++)
		{
			if(mark[j]>max)
			{
				max=mark[j];
				max_pos=j;
			}
		}
		cost[max_pos]=max_cost--;
		mark[max_pos]=0;
	}
	for (i=0;i<len;i++)
		sum+=cost[tolower(s[i])];
	return sum;
}

#endif