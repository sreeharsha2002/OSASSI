#include <sys/types.h> 
#include <sys/stat.h>  
#include <stdio.h> 
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
int N=1e6;
int main(int a,char**arg)
{
	if(a!=4)
		write(1,"Invalid Input\n",strlen("Invalid Input\n"));
	else
	{


		struct stat stats;
		int flag=0;
		if(stat(arg[3],&stats)==0)
		{
			write(1,"Directory is created: ",strlen("Directory is created: "));
			if(stats.st_mode & S_IFDIR)
			{
				write(1,"yes\n",strlen("yes\n"));
			}
			else
			{
				write(1,"No\n",strlen("No\n"));
				flag=1;
			}

		}
		else
		{
			write(1,"Directory is created: No\n",strlen("Directory is created: N0\n"));
		}
		int flago=0,flagn=0;
		if(stat(arg[1],&stats)==0)
		{
			if(stats.st_mode & S_IFDIR)
			{
				write(1,"The Newfile Inputed is Directory\n",strlen("The Newfile Inputed is Directory\n"));
				flagn=1;
			}
		}
		if(stat(arg[2],&stats)==0)
		{
			if(stats.st_mode & S_IFDIR)
			{
				write(1,"The Oldfile Inputed is Directory\n",strlen("The Oldfile Inputed is Directory\n"));
				flago=1;
			}
		}

		int fd=open(arg[2],O_RDONLY);
		int fdr=open(arg[1],O_RDONLY);
		int flagf=0;
		if(fdr==-1)
		{
			perror("Newfile");
			//write(1,"Newfile not exist or read permission denied\n",strlen("Newfile not exist or read permission denied\n"));
			flagf=1;
		}

		if(fd==-1)
		{
			perror("Oldfile");
			//write(1,"Oldfile not exist or read permission denied\n",strlen("Oldfile not exist or read permission denied\n"));
			flagf=1;
		}
		if(flagf==0 && flago==0 && flagn==0)
		{
			char c[N],d[N];
			int of;
			of=lseek(fd,0,SEEK_END);
			int rem=of%N;
			int qo=of/N;
			lseek(fd,-rem,SEEK_END);
			int rv,summ=0;
			float perc;
			char str[100];
			while(qo>-1)
			{
				rv=read(fd,c,N);
				read(fdr,d,rv);
				for(int i=rv-1;i>=0;i--)
				{
					if(c[i]!=d[rv-1-i])
					{
						summ=1;
					}

				}
				if(summ!=0)
				{
					break;
				}
				lseek(fd,-rv-N,SEEK_CUR);
				qo--;
			}
			int lof=lseek(fdr,0,SEEK_END);
			if(lof!=of)
				summ=1;
			write(1,"Whether file contents are reversed in newfile: ",strlen("Whether file contents are reversed in newfile: "));
			if(summ==0)
			{
				write(1,"Yes\n",strlen("yes\n"));
			}
			else
			{
				write(1,"No\n",strlen("No\n"));
			}
		}






























































		if(flag==0)
		{
			if(stat(arg[3],&stats)==0)
			{
				write(1,"User has read permissions on directory: ",strlen("User has read permissions on directory: "));
				if (stats.st_mode & S_IRUSR)
				{
					write(1,"Yes\n",strlen("Yes\n"));
				}
				else
				{
					write(1,"No\n",strlen("No\n"));
				}
				write(1,"User has write permissions on directory: ",strlen("User has write permissions on directory: "));
				if (stats.st_mode & S_IWUSR)
					write(1,"Yes\n",strlen("Yes\n"));
				else
				{
					write(1,"No\n",strlen("No\n"));
				}
				write(1,"User has execute permissions on directory: ",strlen("User has execute permissions on directory: "));
				if (stats.st_mode & S_IXUSR)
					write(1,"Yes\n",strlen("Yes\n"));
				else
				{
					write(1,"No\n",strlen("No\n"));
				}



				write(1,"Group has read permissions on directory: ",strlen("Group has read permissions on directory: "));
				if (stats.st_mode & S_IRGRP)
				{
					write(1,"Yes\n",strlen("Yes\n"));
				}
				else
				{
					write(1,"No\n",strlen("No\n"));
				}
				write(1,"Group has write permissions on directory: ",strlen("Group has write permissions on directory: "));
				if (stats.st_mode & S_IWGRP)
					write(1,"Yes\n",strlen("Yes\n"));
				else
				{
					write(1,"No\n",strlen("No\n"));
				}
				write(1,"Group has execute permissions on directory: ",strlen("Group has execute permissions on directory: "));
				if (stats.st_mode & S_IXGRP)
					write(1,"Yes\n",strlen("Yes\n"));
				else
				{
					write(1,"No\n",strlen("No\n"));
				}


				write(1,"Others has read permissions on directory: ",strlen("Others has read permissions on directory: "));
				if (stats.st_mode & S_IROTH)
				{
					write(1,"Yes\n",strlen("Yes\n"));
				}
				else
				{
					write(1,"No\n",strlen("No\n"));
				}
				write(1,"Others has write permissions on directory: ",strlen("Others has write permissions on directory: "));
				if (stats.st_mode & S_IWOTH)
					write(1,"Yes\n",strlen("Yes\n"));
				else
				{
					write(1,"No\n",strlen("No\n"));
				}
				write(1,"Others has execute permissions on directory: ",strlen("Others has execute permissions on directory: "));
				if (stats.st_mode & S_IXOTH)
					write(1,"Yes\n",strlen("Yes\n"));
				else
				{
					write(1,"No\n",strlen("No\n"));
				}
			}
		}

		//-------------//------------------------
		if(stat(arg[1],&stats)==0 && flagn==0)
		{
			write(1,"User has read permissions on newfile: ",strlen("User has read permissions on newfile: "));
			if (stats.st_mode & S_IRUSR)
			{
				write(1,"Yes\n",strlen("Yes\n"));
			}
			else
			{
				write(1,"No\n",strlen("No\n"));
			}
			write(1,"User has write permissions on newfile: ",strlen("User has write permissions on newfile: "));
			if (stats.st_mode & S_IWUSR)
				write(1,"Yes\n",strlen("Yes\n"));
			else
			{
				write(1,"No\n",strlen("No\n"));
			}
			write(1,"User has execute permissions on newfile: ",strlen("User has execute permissions on newfile: "));
			if (stats.st_mode & S_IXUSR)
				write(1,"Yes\n",strlen("Yes\n"));
			else
			{
				write(1,"No\n",strlen("No\n"));
			}



			write(1,"Group has read permissions on newfile: ",strlen("Group has read permissions on newfile: "));
			if (stats.st_mode & S_IRGRP)
			{
				write(1,"Yes\n",strlen("Yes\n"));
			}
			else
			{
				write(1,"No\n",strlen("No\n"));
			}
			write(1,"Group has write permissions on newfile: ",strlen("Group has write permissions on newfile: "));
			if (stats.st_mode & S_IWGRP)
				write(1,"Yes\n",strlen("Yes\n"));
			else
			{
				write(1,"No\n",strlen("No\n"));
			}
			write(1,"Group has execute permissions on newfile: ",strlen("Group has execute permissions on newfile: "));
			if (stats.st_mode & S_IXGRP)
				write(1,"Yes\n",strlen("Yes\n"));
			else
			{
				write(1,"No\n",strlen("No\n"));
			}


			write(1,"Others has read permissions on newfile: ",strlen("Others has read permissions on newfile: "));
			if (stats.st_mode & S_IROTH)
			{
				write(1,"Yes\n",strlen("Yes\n"));
			}
			else
			{
				write(1,"No\n",strlen("No\n"));
			}
			write(1,"Others has write permissions on newfile: ",strlen("Others has write permissions on newfile: "));
			if (stats.st_mode & S_IWOTH)
				write(1,"Yes\n",strlen("Yes\n"));
			else
			{
				write(1,"No\n",strlen("No\n"));
			}
			write(1,"Others has execute permissions on newfile: ",strlen("Others has execute permissions on newfile: "));
			if (stats.st_mode & S_IXOTH)
				write(1,"Yes\n",strlen("Yes\n"));
			else
			{
				write(1,"No\n",strlen("No\n"));
			}
		}
		//------------------------------------------------------------//

		//----------------------------**
		if(stat(arg[2],&stats)==0 && flago==0)
		{
			write(1,"User has read permissions on oldfile: ",strlen("User has read permissions on oldfile: "));
			if (stats.st_mode & S_IRUSR)
			{
				write(1,"Yes\n",strlen("Yes\n"));
			}
			else
			{
				write(1,"No\n",strlen("No\n"));
			}
			write(1,"User has write permissions on oldfile: ",strlen("User has write permissions on oldfile: "));
			if (stats.st_mode & S_IWUSR)
				write(1,"Yes\n",strlen("Yes\n"));
			else
			{
				write(1,"No\n",strlen("No\n"));
			}
			write(1,"User has execute permissions on oldfile: ",strlen("User has execute permissions on oldfile: "));
			if (stats.st_mode & S_IXUSR)
				write(1,"Yes\n",strlen("Yes\n"));
			else
			{
				write(1,"No\n",strlen("No\n"));
			}



			write(1,"Group has read permissions on oldfile: ",strlen("Group has read permissions on oldfile: "));
			if (stats.st_mode & S_IRGRP)
			{
				write(1,"Yes\n",strlen("Yes\n"));
			}
			else
			{
				write(1,"No\n",strlen("No\n"));
			}
			write(1,"Group has write permissions on oldfile: ",strlen("Group has write permissions on oldfile: "));
			if (stats.st_mode & S_IWGRP)
				write(1,"Yes\n",strlen("Yes\n"));
			else
			{
				write(1,"No\n",strlen("No\n"));
			}
			write(1,"Group has execute permissions on oldfile: ",strlen("Group has execute permissions on oldfile: "));
			if (stats.st_mode & S_IXGRP)
				write(1,"Yes\n",strlen("Yes\n"));
			else
			{
				write(1,"No\n",strlen("No\n"));
			}


			write(1,"Others has read permissions on oldfile: ",strlen("Others has read permissions on oldfile: "));
			if (stats.st_mode & S_IROTH)
			{
				write(1,"Yes\n",strlen("Yes\n"));
			}
			else
			{
				write(1,"No\n",strlen("No\n"));
			}
			write(1,"Others has write permissions on oldfile: ",strlen("Others has write permissions on oldfile: "));
			if (stats.st_mode & S_IWOTH)
				write(1,"Yes\n",strlen("Yes\n"));
			else
			{
				write(1,"No\n",strlen("No\n"));
			}
			write(1,"Others has execute permissions on oldfile: ",strlen("Others has execute permissions on oldfile: "));
			if (stats.st_mode & S_IXOTH)
				write(1,"Yes\n",strlen("Yes\n"));
			else
			{
				write(1,"No\n",strlen("No\n"));
			}
		}
	}
	//-------------------------------//-----------------

}
