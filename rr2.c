#include<stdio.h>
#define max 10

void push(int);
int pop();
void display();

struct process
{
int at,bt,wt,tt,ch,id,rt,et,nat;
char name[5];
}rq[max],p[max],temp,tp;
int i,s=1,k;
int front=-1;
int rear=-1;

void main()
{
	int n,min,mat,maxx,ts;
	int flag=0,mark=0;
	float wt=0.00,tt=0.00;
	int time=0;t2;
	printf("Enter the time slice:");
	scanf("%d",&ts);
	printf("Enter the number of process");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("Enter the name of process%d:",i);
		scanf("%s",p[i].name);
		printf("Enter the arrival time of %s:",p[i].name);
		scanf("%d",&p[i].at);
		printf("Enter the burst time of %s:",p[i].name);
		scanf("%d",&p[i].bt);
		p[i].id=i;
		printf("\n");
	}	
	for(i=0;i<n;i++)
	{
		p[i].ch=0;
		p[i].et=0;
		p[i].nat=0;
		p[i].rt=p[i].bt;
	}	
}
