#include<stdio.h>
#include<stdlib.h> 				

void alteration();
void allocation();
void allocatedspace(int,int,int);
void singlenode(int,int);
void allocateprocess(int,int);
void displayfreespace();
void displayallocatedspace();
void deallocation();
void removeprocess(int);
void compaction(int);
void rearrange();

struct node
{
	int start,end;
	int id,size;
	struct node *next;
}*s1=NULL,*temp=NULL,*s2=NULL,*process=NULL;   
//temp -pointer for s1 linked list-free space linked list
//process -pointer for s2 linked list-process linked list


void main()
{
	int sta,eda,n,i;
	int id,st,ed,ch;
	printf("First Fit\n");
	printf("Enter the starting address of memory location:");
	scanf("%d",&sta);
	printf("Enter the ending address of memory location:");
	scanf("%d",&eda);
	singlenode(sta,eda);
	printf("Enter the number of process:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("Enter the id of the process:");
		scanf("%d",&id);
		printf("Enter the starting address of p%d:",id);
		scanf("%d",&st);
		printf("Enter the ending address of p%d:",id);
		scanf("%d",&ed);
		allocatedspace(id,st,ed);
		alteration();
	}
	do
	{
		displayfreespace();
		displayallocatedspace();
		printf("\nMENU\n1.ALLOCATION\n2.DEALLOCATION\n3.EXIT\n");
		printf("Enter your choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:	
				allocation();							//allocation
				break;
			case 2:								//deallocation
				deallocation();
				break;
			case 3:
				return;
				break;
			default:
				printf("Invalid Choice\n");	
		}
	}while(ch!=3);
}

void alteration() //before MENU
{	
	int buffer;
	temp=s1;
	while(temp->next!=NULL)
		{
			temp=temp->next;
		}
	process=s2;
	while(process->next!=NULL)
	{
		process=process->next;
	}
	if(temp->start==process->start)
	{
		temp->start=(process->end)+1;
		temp->size=(temp->end)-(temp->start)+1;
	}
	else if(temp->end==process->end)
	{
		temp->end=(process->start)-1;
		temp->size=(temp->end)-(temp->start)+1;
	}
	else
	{
		buffer=temp->end;
		temp->end=(process->start)-1;
		temp->size=(temp->end)-(temp->start)+1;
		struct node *newn;
		newn=(struct node *)malloc(sizeof(struct node));
		temp->next=newn;
		newn->next=NULL;
		newn->start=(process->end)+1;
		newn->end=buffer;
		newn->size=(newn->end)-(newn->start)+1;
	}
}

void allocation()  //function for menu
{		int id,size;
		printf("Enter the id of the process:");
		scanf("%d",&id);
		printf("Enter the size of p%d:",id);
		scanf("%d",&size);
		allocateprocess(id,size);
}

void deallocation() //funtion for menu
{
	int id;
	printf("Enter the id of the process you want to deallocate:");
	scanf("%d",&id);
	process=s2;
	while(process!=NULL)
	{
		if((process->id)==id)
		{
			compaction(id);
			removeprocess(id);
			return;
		}
		process=process->next;
	}
	printf("No such process found!\n");
	
}

void removeprocess(int id)  //case 2
{
	struct node *prev;
	process=s2;
	while(process!=NULL)
	{
	
		if((process->id)==id) 
		{
			if(process==s2)  //deletion at the begining
			{
				if((s2->next)==NULL)   //single element
				{
					process=s2;
					s2=NULL;
					printf("Process p%d deallocated.......\n",process->id);
					free(process);
					return;
				}
			else				//multiple elements in case of deletion at the begining
				{
					process=s2;
					s2=s2->next;
					printf("Process p%d deallocated.......\n",process->id);
					free(process);
					return;
				}
			}
			else if((process->next)==NULL) //deletion at the end
			{
				prev->next=NULL;
				printf("Process p%d deallocated.......\n",process->id);
				free(process);
				return;
			}
			else
			{
				prev->next=process->next;
				printf("Process p%d deallocated.......\n",process->id);
				free(process);
				return;
			}
		}
		prev=process;
		process=process->next;
	}
}

void compaction(int id)		//for case2 freespace
{
	struct node *prev;
	int mark=0;
	process=s2;
	while(process!=NULL)
	{
		if((process->id)==id)
		{
			break;
		}
		process=process->next;
	}
	
	temp=s1;
	while(temp!=NULL)
	{
		if((temp->end+1)==(process->start))
		{
			temp->end=process->end;
			(temp->size)=(temp->size)+process->size;
			mark=1;
			break;
		}
		if((process->end+1)==(temp->start))
		{
			temp->start=process->start;
			(temp->size)=(temp->size)+process->size;
			mark=1;
			break;
		}
		temp=temp->next;
	}
	
	if(mark==0)
	{
		struct node *newn=(struct node *)malloc(sizeof(struct node));
		newn->start=process->start;
		newn->end=process->end;
		newn->size=process->size;
		if(s1==NULL)	//insertion in empty free space linkedlist 
		{
			s1=newn;
			s1->next=NULL;
		}
		else		//insertion
		{
				temp=s1;
				prev=s1;
				while(temp!=NULL)
				{	
					if((process->end<temp->start)&&(temp==s1))
					{	
						newn->next=s1;
						s1=newn;
						temp=s1;
						break;	
					}
					if((process->start>temp->end)&&(temp->next==NULL))
					{
						temp->next=newn;
						newn->next=NULL;
						break;
					}
					if((process->start>prev->end)&&(process->end<temp->start))
					{
						prev->next=newn;
						newn->next=temp;
						break;
					}
					prev=temp;
					temp=temp->next;
				}
		}
	}
	rearrange();
}

void rearrange()		//actual compaction takes place here
{	
	struct node *tp,*tk,*prev;
	tk=s1;
	while(tk!=NULL)
	{
		
		tp=s1;
		while(tp!=NULL)
		{
			
			if((tk->end+1)==(tp->start))
			{
				
				tk->end=tp->end;
				(tk->size)=(tk->size)+(tp->size);
				if((tp->next)==NULL)
				{
					prev->next=NULL;
					free(tp);
					rearrange();
					return;
				}
				else
				{
					prev->next=tp->next;
					free(tp);
					rearrange();
					return;
				}
			}
			if((tk->start-1)==(tp->end))
			{	
				tk->start=tp->start;
				(tk->size)=(tk->size)+(tp->size);
				if((tp->next)==NULL)
				{
					prev->next=NULL;
					free(tp);
					rearrange();
					return;
				}
				else
				{
					prev->next=tp->next;
					free(tp);
					rearrange();
					return;
				}
			}
			prev=tp;
			tp=tp->next;
		}
		tk=tk->next;
	}
}

void singlenode(int sta,int eda)
{
	struct node *newn;
	newn=(struct node *)malloc(sizeof(struct node));
	newn->start=sta;
	newn->end=eda;
	newn->size=eda-sta+1;
	s1=newn;
	newn->next=NULL;
	
}

void allocatedspace(int id,int st,int ed)         //process linkedlist
{
	struct node *newn;
	newn=(struct node *)malloc(sizeof(struct node));
	newn->id=id;
	newn->start=st;
	newn->size=ed-st+1;
	newn->end=ed;
	if(s2==NULL)			//empty linkedlist
	{
		s2=newn;
		s2->next=NULL;
	}
	else		//multiple elements
	{
		process=s2;
		while(process->next!=NULL)
		{
			process=process->next;
		}
		process->next=newn;
		newn->next=NULL;
	}
}

void allocateprocess(int id,int size)    //allocationing new process 
{
	int st,ed;
	temp=s1;
	struct node *prev=s1;
	while(temp!=NULL)
	{
		
		if((temp->size)>size)
		{
			st=temp->start;
			ed=temp->start+size-1;
			temp->start=(temp->start)+size;
			temp->size=(temp->end)-(temp->start)+1;
			allocatedspace(id,st,ed);
			return;
		}
		
		if((temp->size)==size)
		{
			st=temp->start;
			ed=temp->end;
			allocatedspace(id,st,ed);
			if(temp->size==s1->size)  //deletion at the begining
			{	
				if((s1->next)==NULL)   //single element
				{
					temp=s1;
					s1=NULL;
					free(temp);
					return;
				}
				
				else				//multiple elements in case of deletion at the begining
				{	
					temp=s1;
					s1=s1->next;
					free(temp);
					return;
				}
			}
			else if((temp->next)==NULL) //deletion at the end
			{
				prev->next=NULL;
				free(temp);
				return;
			}
			else			//deletion in between
			{
				prev->next=temp->next;
				free(temp);
				return;
			}
		}
					
	prev=temp;	
	temp=temp->next;	
	}	
	printf("Process cannot be allocated!\n");	
}
void displayfreespace()
{
	if(s1==NULL)
	{
		printf("\nNo free space remaining...\n");
	}
	else
	{
		printf("\nFree Space\n");
		temp=s1;
		while(temp!=NULL)
		{
			printf("  %d-%d\t\tsize:%d\n",temp->start,temp->end,temp->size);
			temp=temp->next;
		}
	}
}

void displayallocatedspace()
{
	if(s2==NULL)
	{
		printf("\nNo process is allocated...\n");
	}
	else
	{
		printf("\nAllocated Space\n");
		temp=s2;
		while(temp!=NULL)
		{
			printf("p%d:%d-%d\t\tsize:%d\n",temp->id,temp->start,temp->end,temp->size);
			temp=temp->next;
		}
	}
}

