#include <sys/types.h> 
#include <sys/stat.h>  
#include <stdio.h> 
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include<errno.h>
extern int errno;
int N=1e6;

int main(int a,char** arg)
{
	if(a!=2)
		write(1,"Invalid Input\n",strlen("Invalid Input\n"));
	else
	{


		int fd = open(arg[1],O_RDONLY);
		if(fd==-1)
		{
			perror("Program");
			//write(1,"\rInput File not exist\n",strlen("\rInput File not exist\n") );
		}
		else 
		{
		int check =mkdir("Assignment",0777);
		char *c1;
		char *p;
		c1=strtok(arg[1],"/");
		while(c1!=NULL)
		{
			// printf("%s\n",c);
			p=c1;
			c1 = strtok (NULL, "/");

		}
		char ss[200];
		sprintf(ss,"./Assignment/%s",p);
		int ff=open(ss,O_WRONLY);
		int fdr = open(ss, O_WRONLY| O_CREAT | O_TRUNC, 0644);
		


			if(errno!=13)
			{
			if(ff!=-1)
			{
				write(1,"\rOutput File already exists\n",strlen("\rOutput File already exists\n") );
			}
			else
			{
				write(1,"\rOutput File should be created\n",strlen("\rOutput File should be created\n") );

			}
		}
			//char sll[8];
			if(fdr==-1)
			{
				if(errno==13)
				{
					write(1,"\rOutput File already exists\n",strlen("\rOutput File already exists\n") );
				}
				else
				{
						write(1,"\rOutput File should be created\n",strlen("\rOutput File should be created\n") );
				}

				/*sprintf(sll,"%d\n",errno);
				write(1,sll,strlen(sll));*/
				perror("program");

				return 0;
			}

			char c[N],d[N];
			int of;
			of=lseek(fd,0,SEEK_END);
			int rem=of%N;
			int qo=of/N;
			lseek(fd,-rem,SEEK_END);
			int rv,summ=0;
			long double perc;
			char str[100];
			while(qo>-1)
			{
				rv=read(fd,c,N);
				int j=0;
				for(int i=rv-1;i>=0;i--)
				{
					d[j]=c[i];
					j++;
				}
				write(fdr,d,rv);
				summ+=rv;
				perc=((long double)summ/of)*100;
				sprintf(str,"\rpercentage of reversing the file :%0.4Lf%%",perc);
				write(1,str,strlen(str));
				lseek(fd,-rv-N,SEEK_CUR);
				qo--;
			}

			write(1,"\n",1);
			close(ff);
		close(fdr);
		}
		close(fd);
		
	}

}
