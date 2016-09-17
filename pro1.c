#include<stdio.h>
#define max 10

void push();
void pop();
void check();

struct process
{
int at,bt,st,wt,tt,ch;
char process[5];
}rq[max],p[max],temp,tp;
int i,s,k;
int front=-1;
int rear=-1;
int choice;
main()
{
		int n,min,mat,maxx;
		int flag=0;
		int idle=0;
		int time=0,t2;
		float wt=0.00,tt=0.00;
do{
	printf("\nMENU\n1.FCFS\n2.SJF\n3.EXIT\n");
	printf("Enter your choice:");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
			flag=0,idle=0,time=0,t2;
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
						push();
					}	
							
				}
				
				
				if(t2==time)
				{
					
					pop();
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
			for(k=0;k<n;k++)
			{	
				printf("Waiting time of %s=%d\n",p[k].process,p[k].wt);
				printf("TurnAround time of %s=%d\n",p[k].process,p[k].tt);
			}
			printf("Average waiting time=%.2f\n",wt);
			printf("Average TurnAround time=%.2f\n",tt);
			break;
		case 2:
			flag=0,idle=0,time=0,t2;
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
						push();
					}	
							
				}
					
				if(t2==time)
				{
					
					pop();
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
			for(k=0;k<n;k++)
			{	
				printf("Waiting time of %s=%d\n",p[k].process,p[k].wt);
				printf("TurnAround time of %s=%d\n",p[k].process,p[k].tt);
			}
			printf("Average waiting time=%.2f\n",wt);
			printf("Average TurnAround time=%.2f\n",tt);
			break;
		case 3:
			return;
		default:
			printf("Invalid Choice\n");
	}
	
}while(choice!=3);

}

void push()
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
	if(choice==2)
	{
		check();
	}	
	
	}
}

void pop()
{	
	if(front==-1 && rear==-1)
	{
	//	printf("Queue Underflow\n");
		s=-2;
	}
	else if(front==rear) //queue single element
	{	
		s=1;
		p[k]=rq[front];
		front=rear=-1;
	}
	else
	{	
		s=1;
		p[k]=rq[front];
		front=front+1;
	}

}
void check()
{
	int m,n;
	for(m=front;m<=rear;m++)
	{
		for(n=front;n<rear;n++)
		{
			if(rq[n].bt>rq[n+1].bt)
			{
				tp=rq[n];
				rq[n]=rq[n+1];
				rq[n+1]=tp;
			}
		}
		
	}
}