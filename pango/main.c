#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

int cmp(int *a, int *b)
{
	return -(*a-*b);
}

void swap(void *a,void *b,int size)
{
	void *tmp=malloc(size);
	memcpy(tmp,a,size);
	memcpy(a,b,size);
	memcpy(b,tmp,size);
	free(tmp);
}

void _qsort(void *a,int n,int size,int(*cmp)(const void *,const void *))
{
	int i,j=0,k=n-1,p=0;
	for (i=0;i<n;i++)
	{
		while(cmp((int)a+size*p,(int)a+size*j)>0)
			j++;


	}
	qsort(a,i,size,cmp);
	qsort((int)a+size*i,n-i,size,cmp);
}

main()
{
	char s[]="bbbbcacbbabccabbbcabccaccbccaccbaaaabcbabaaacbbbbccabaccbcbccabacaaaccaaabbaaabcabacbabbbabababaabbabcbcbbcabbcccccbbbacbbaacbbabcaacaabbacabbabcccabaaccbbcacacbaccbcbaaabbbbcbcccaacbabccccccbbbacbbbb";
	printf("%d\n",minLength(s));
	system("pause");
}