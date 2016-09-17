#include<stdio.h>
#define max 10

void push(int);
int pop();
void sort();

struct process
{
int at,bt,wt,tt,ch,id,pt;
char process[5];
}rq[max],p[max],temp,tp;
int i,s,k=0;
int front=-1;
int rear=-1;


main()
{
int n,min,mat,maxx;
int flag=0;
float wt=0.00,tt=0.00;
int time=0,t2;
printf("Enter the number of process:");
scanf("%d",&n);
for(i=0;i<n;i++)
	{
	printf("Enter the name of process%d:",i);
	scanf("%s",p[i].process);
	printf("Enter the arrival time of %s:",p[i].process);
	scanf("%d",&p[i].at);
	printf("Enter the burst time of %s:",p[i].process);
	scanf("%d",&p[i].bt);
	printf("Enter the priority of the %s:",p[i].process);
	scanf("%d",&p[i].pt);
	p[i].id=i;
	printf("\n");
	}

for(i=0;i<n;i++)
{
	p[i].ch=0;
}		
min=p[0].at;

for(i=0;i<n;i++)
{	if(p[i].at<min)
		min=p[i].at;
	
}
maxx=p[0].at;
for(i=0;i<n;i++)
{
	if(p[i].at>maxx)
		maxx=p[i].at;
}
time=min;
t2=time;
printf("Grantt Chart:\n");
if(time>0)
{
	printf("0\tX\t");
}
do
{

	for(i=0;i<n;i++)
	{	
		if(p[i].at==time)
		{
			push(p[i].id);
		}	
				
	}
		
	if(t2==time)
	{
		
		k=pop();
		p[k].ch=1;
		if(s==-2)	//idle time
		{
		printf("%d\tX\t",time);
					//find minimun arrival time of remaining process
		mat=maxx;
		for(i=0;i<n;i++)
			{
				if(p[i].at<mat && p[i].ch==0)
				{
					mat=p[i].at;
					
				}
			}
			t2=mat;
		}
		else
		{
		printf("%d\t%s\t",t2,p[k].process);
		flag++;
		p[k].wt=t2-p[k].at;
		t2=time+p[k].bt;
		p[k].tt=p[k].wt+p[k].bt;
		}
	}
if(flag==n)
{
	printf("%d\t",(t2));
	break;
}

time++;
		
}while(time<100);
printf("\n");
for(k=0;k<n;k++)
{
	wt+=p[k].wt;
	tt+=p[k].tt;
}
wt=(wt/n);
tt=(tt/n);
printf("\nProcess\tWT\tTT\n");
for(k=0;k<n;k++)
	{	
	printf("%s\t%d\t%d\t",p[k].process,p[k].wt,p[k].tt);
	printf("\n");			
	}
printf("Average waiting time=%.2f\n",wt);
printf("Average TurnAround time=%.2f\n",tt);
}

void push(int i)
{
	if(front==max-1)
	{
	//	printf("Queue overflow\n");
	}
	else if(front==-1)	//queue is empty
	{	
	front=0;
	rear=0;
	rq[rear]=p[i];
	}
	else 
	{
	rear=rear+1;
	rq[rear]=p[i];
	sort();
	
	}
}

int pop()
{	
	if(front==-1 && rear==-1)
	{
	//	printf("Queue Underflow\n");
		s=-2;
	}
	else if(front==rear) //queue single element
	{	
		s=1;
		k=rq[front].id;
		front=rear=-1;
		return k;
	}
	else
	{	
		s=1;
		k=rq[front].id;
		front=front+1;
		return k;
	}

}
void sort()
{
	int m,n;
	for(m=front;m<=rear;m++)
	{
		for(n=front;n<rear;n++)
		{
			if(rq[n].pt>rq[n+1].pt)
			{
				tp=rq[n];
				rq[n]=rq[n+1];
				rq[n+1]=tp;
			}
		}
		
	}
}
