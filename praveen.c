#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc,char *argv[])
{
	if(argc!=3)
	{
		printf("Usage: ./grep word file \n");
		return 0;
	}
	FILE *fp=fopen(argv[2],"r");
	if(fp==NULL)
	{
		printf("%s:no such file \n",argv[2]);
		return 0;
	}
	char ch;
	int count=0,line_length=0;
	while((ch=fgetc(fp))!=-1)
	{
		count++;
		if(ch=='\n');
		{
			if(line_length<count)
			line_length=count;
			count=0;
		}
	}
	rewind(fp);
	char *buf=(char *)malloc(line_length*sizeof(char));
	while(fgets(buf,line_length,fp)!=NULL)
	{
		if(strstr(buf,argv[1])!=NULL)
		{
			printf("%s\n",buf);
		}
	}
}
