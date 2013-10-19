#include "lib.h"
#ifdef SUB_SEQUENCE
/*
* 数组子序列
*/

int run(const int *a,int n)
{
	int sub[110]={0},mark[110]={0};
	int i,MOD=1000000007;

	for (i=1;i<n+1;i++)
	{
		sub[i]=(sub[i-1]<<1) % MOD;
		if (mark[a[i-1]]==0)
			sub[i]+=1;
		else
			sub[i]=(sub[i]-sub[mark[a[i-1]]-1]+MOD) % MOD;
		mark[a[i-1]]=i;
	}
	return sub[n];
}

#endif
