#include "prompt.h"
#include "headers.h"
#include "fn.h"
#include "comm.h"
#include "history.h"
int N=2024;
int main()
{
	char cwd_1[N];
	getcwd(cwd_1,sizeof(cwd_1));
	
	while (1)
	{

		prompt(cwd_1);
		char sp=' ';
		int i=0;
		char inp[N],dinp[N];
		while(sp!='\n')
		{
			scanf("%c",&sp);
			if(i==0)
			{
				if(sp!=' ' && sp!='\n' && sp!='\t')
				{
					inp[i]=sp;
					i++;
				}
			}
			else if(sp!='\n')
			{
				inp[i]=sp;
				i++;
			}

		}
		inp[i]='\0';
		//printf("%s,%d\n",inp,i);
		//printf("%c\n",inp[9]);
		if(strlen(inp)>0)
		{
			gotohistory(inp,cwd_1);
		strcpy(dinp,inp);
		char delim[] = ";";
		char arr[N][N];
		i=0;
		char *ptr = strtok(dinp, delim);
		//printf("IN mainA %sl\n", ptr);
		while (ptr != NULL)
		{
			strcpy(arr[i],ptr);
			i++;
			ptr = strtok(NULL, delim);	
		}
		for(int j=0;j<i;j++)
		{
			comm(arr[j],cwd_1);
		}


		}
		
	}
}
