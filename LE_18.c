#include<stdio.h>
#include<conio.h>
#include<alloc.h>
#include<string.h>
typedef struct node
{
	char *line;
	struct node *next;
}NODE;

NODE *head=NULL, *last, *temp;
char cmd[80];
int i;

NODE* loadfile(char[]);
void append();
void print();
void move();
void save();

void main(int argc, char *argv[])
{
      if(argc==2)
      {
		head = loadfile(argv[1]);
      }
      else
      {
		head=NULL;
      }
      while(1)
      {
		printf("\n $ ");
		gets(cmd);
		switch (cmd[0])
		{
			case 'p' : print();
				break ;
			case 'a' : append();
				break;
			case 's' : save();
				break;
			case 'm' : move();
				break;
			case 'e' : exit(0);
		}
      }
}

NODE* loadfile(char fname[])
{
	FILE *fp;
	head = NULL;
	fp = fopen(fname,"r");
	if(fp==NULL)
	{
		printf("\n File not found");
		return(head);
	}
	while(!feof(fp))
	{
		fgets(cmd,80,fp);
		temp = (NODE*)malloc(sizeof(NODE));
		temp->line = (char*)malloc(strlen(cmd));
		strcpy(temp->line,cmd);
		if(head==NULL)
		{
			head = temp;
		}
		else
		{
			last->next = temp;
		}
		last = temp;
	}
	temp->next = NULL;
	return (head);
}

void print()
{
	for(temp=head;temp!=NULL;temp=temp->next)
	{
		printf("%s",temp->line);
	}
}

void append()
{
	NODE* atop=NULL;
	char t,t1,str[80];
	sscanf(cmd,"%c%c%s",&t,&t1,&str);
	strcat(str,"\n");
	atop=(NODE*)malloc(sizeof(NODE));
	atop->line=(char*)malloc(strlen(str));
	strcpy(atop->line,str);
	for(temp=head;temp->next!=NULL;temp=temp->next);
	temp->next=atop;
	atop->next=NULL;
}

void save()
{
	FILE *fp=NULL;
	char fname[80];
	printf("\n Enter File name : ");
	gets(fname);
	fp = fopen(fname,"w");
	temp=head;
	while(temp!=NULL)
	{
		fputs(temp->line,fp);
		temp=temp->next;
	}
	fclose(fp);
	printf("\n File saved successfully");
}

void move()
{
  NODE *temp1,*temp2;
  char t1,str[80];
  int n1,n2;
 sscanf(cmd,"%c %d %d ",&t1,&n1,&n2);
 temp1=head;
 for(i=1;i<n1;i++)
 {
	temp1=temp1->next;
 }
 temp2=head;
 for(i=1;i<n2;i++)
 {
	temp2=temp2->next;
 }
 strcpy(str,temp1->line);
 strcpy(temp1->line,temp2->line);
 strcpy(temp2->line,str);
}





