#include <stddef.h>
typedef struct TreeNode
{
	int e;
	struct TreeNode *l,*r;
}tTree;

tTree *rand_create()
{
	tTree *e1=malloc(sizeof(tTree));
	tTree *e2=malloc(sizeof(tTree));
	tTree *e3=malloc(sizeof(tTree));
	tTree *e4=malloc(sizeof(tTree));
	tTree *e5=malloc(sizeof(tTree));
	tTree *e6=malloc(sizeof(tTree));
	tTree *e7=malloc(sizeof(tTree));
	tTree *e8=malloc(sizeof(tTree));
	e1->e=1;
	e1->l=e1->r=NULL;
	e2->e=2;
	e2->l=e2->r=NULL;
	e3->e=3;
	e3->l=e3->r=NULL;
	e4->e=4;
	e4->l=e4->r=NULL;
	e5->e=5;
	e5->l=e5->r=NULL;
	e6->e=6;
	e6->l=e6->r=NULL;
	e7->e=7;
	e7->l=e7->r=NULL;
	e8->e=8;
	e8->l=e8->r=NULL;

	e4->l=e2;
	e4->r=e6;
	e2->l=e1;
	e2->r=e3;
	e6->l=e5;
	e6->r=e7;
	e7->r=e8;
	return e4;
}

void convert_link(tTree *t,tTree **h,tTree **p)
{
	if(t->l)
		convert_link(t->l,h,p);
	if(*h==NULL || *p==NULL)
		*h=*p=t;
	else
	{
		t->l=*p;
		(*p)->r=t;
		*p=t;
	}
	if(t->r)
		convert_link(t->r,h,p);
}

tTree *get_link(tTree *t)
{	
	tTree *h,*p;
	h=p=NULL;
	convert_link(t,&h,&p);
	return h;
}