#include<stdio.h>
#include<dirent.h>
#include<unistd.h>
#include<sys/types.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>



struct dirent *dir;
char path[30],source[50];
int fd2;
void child();
void main()
{
DIR *d;
pid_t pid;
int id;
id=getpid();
printf("Parent id:%d\n",id);
printf("Enter the path of the directory:");
scanf("%s",path);
strcpy(source,path);
strcat(source,"/");
fd2=open("result.txt",O_RDWR|O_CREAT,S_IRUSR|S_IWUSR);
printf("Files in directory:%s\n",path);
d=opendir(path);
if(!d)
{
	printf("Cannot open directory\n");
}
while((dir=readdir(d))!=NULL)
{	
	if(strcmp(dir->d_name,".")==0||strcmp(dir->d_name,"..")==0)
	{
		continue;
	}
	printf("%s\n",dir->d_name);
}

d=opendir(path);
if(!d)
{
	printf("Cannot open directory\n");
}
while((dir=readdir(d))!=NULL)
{	
	if(strcmp(dir->d_name,".")==0||strcmp(dir->d_name,"..")==0)
	{
		continue;
	}
	pid=fork();
	if(pid==0)
		{
			child();
			exit(0);
		}
	else
		{
			wait(0);
		}
}
close(fd2);
closedir(d);
}

void child()
{
int cid;
int fd,x=1;
int count=0;
char filepath[50],output[50];
cid=getpid();
strcpy(filepath,source);
printf("Child id:%d\n",cid);
printf("%s\n",dir->d_name);
strcat(filepath,dir->d_name);
printf("location of the file:%s\n",filepath);
fd=open(filepath,O_RDWR,S_IRUSR|S_IWUSR);
char c[10];
while(x=(read(fd,c,1))!=0)
{
	if(c[0]==' '||c[0]=='\n')
		count++;	
}
printf("word count:%d\n",count);
sprintf(output,"Filename:%s\twordcount:%d\n",dir->d_name,count);
write(fd2,output,strlen(output));
close(fd);
printf("Child process stopped\n");
} 
