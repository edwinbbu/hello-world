void compaction(int id)		//for case2 freespace
{
	process=s2;
	while(process!=NULL)
	{
		if((process->id)==id)
		{
			break;
		}
		process=process->next;
	}
	struct node *newn=(struct node *)malloc(sizeof(struct node));
	newn->start=process->start;
	newn->end=process->end;
	newn->size=process->size;
	if(s1==NULL)	//insertion in empty free space linkedlist 
	{
		s1=newn;
		s1->next=NULL;
	}
	else		//insertion at end of free space
	{
		temp=s1;
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
				
		temp->next=newn;
		newn->next=NULL;
		
	}
	rearrange();
}
