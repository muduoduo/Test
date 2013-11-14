#include "lib.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>



int f(int n)
{
	return n==1?1:n+f(n-1);
}

main()
{
	printf("%d\n",f(10));
	system("pause");
}