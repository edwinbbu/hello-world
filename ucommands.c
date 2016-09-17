#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void grep();
void cat();
void more();

void main()
{
int ch;
do
{
printf("\nMENU\n1.GREP\n2.CAT\n3.MORE\n4.EXIT\n");
printf("Enter your choice:");
scanf("%d",&ch);
switch(ch)
	{
	case 1: grep();
		break;
	case 2: cat();
		break;
	case 3: more();
		break;
	case 4: return;
		break;
	default: printf("Invalid Choice.Try again!\n");
	}
}while(ch!=4);
}

void grep()
{
FILE *fp;
char file[30];
int i,j;
printf("Enter the name of the file:");
scanf("%s",file);
fp=fopen(file,"r");
if(fp==NULL)
	{
	printf("Error opening file\n");
	}
char pattern[20];
printf("Enter the pattern:");
scanf("%s",pattern);
char line[500];
char ch;
printf("GREP OUTPUT\n");
i=0;
char *ret;
while((ch=fgetc(fp))!=EOF)
	{
	//ch=fgetc(fp);
	line[i]=ch;
	i++;
	if((ch=='\n')||(ch==EOF))
		{
		i--;
		line[i]='\0';
		ret=strstr(line,pattern);
		if(ret!=NULL)
			printf("%s\n",line);
		i=0;
		}
	}	
fclose(fp);
}

void cat()
{
FILE *fp,*fp2;
char file[30],file2[30];
int i,j,choice;
printf("Enter number of input files:");
scanf("%d",&choice);
printf("Enter the name of first file:");
scanf("%s",file);
if(choice==2)
	{
	printf("Enter the name of second file:");
	scanf("%s",file2);
	}
fp=fopen(file,"r");
if(fp==NULL)
	{
	printf("Error opening file\n");
	}
char ch;
while((ch=fgetc(fp))!=EOF)
	{
	printf("%c",ch);
	}
fclose(fp);
if(choice==2)
	{	
	fp2=fopen(file2,"r");
	if(fp2==NULL)
		{
		printf("Error opening file\n"); 
		}
	while((ch=fgetc(fp2))!=EOF)
		{
		printf("%c",ch);
		}
	fclose(fp2);
	}
}

void more()
{
FILE *fp;
char file[30];
int i,j;
printf("Enter the name of the file:");
scanf("%s",file);
fp=fopen(file,"r");
if(fp==NULL)
	{
	printf("Error opening file\n");
	}
char ch;
char line[1000];
i=0;
int count=0;
while((ch=fgetc(fp))!=EOF)
	{
	line[i]=ch;
	i++;
	if(ch=='\n')
		{
		i--;
		line[i]='\0';
		printf("%s\n",line);
		i=0;
		count++;
		if(count>=39)
			{
			//printf("--More--");
			scanf("%c",&ch);
			if(ch=='q')
				break;
			if(ch==NULL)
				{
				continue;
				}
			}
		}
	}
fclose(fp);
}

