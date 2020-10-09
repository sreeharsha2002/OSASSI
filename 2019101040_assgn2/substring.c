#include"headers.h"
int max(int num1, int num2)
{
	return (num1 > num2) ? num1 : num2;
}
char *substring(char *destination, const char *source, int beg, int n)
{
	// extracts n characters from source string starting from beg index
	// and copy them into the destination string
	while (n > 0)
	{
		*destination = *(source + beg);

		destination++;
		source++;
		n--;
	}

	// null terminate destination string
	*destination = '\0';

	// return the destination string
	return destination;
}
void gototilde(char *str)
{
	char c[1024];
	getcwd(c, sizeof(c));
	c[strlen(c)] = '\0';
	// printf("%sbefore~\n",c);
	if (strcmp(str, c) == 0)
	{

	}
	else
	{
		char temp[strlen(str)+5];
		for (int i = 0; i < max(strlen(str), strlen(c)); i++)
		{
			if (str[i] != c[i])
			{
				int wcn=0;
				if(strlen(c)>strlen(str))
				{
					wcn=1;
				}
				for (int j=i;j<strlen(c);j++)
				{
					if(c[j]=='/')
					{

						wcn++;

					}
				}
				while(wcn--)
				{
					chdir("..");
				}
				getcwd(c, sizeof(c));
				c[strlen(c)] = '\0';
				// printf("%safr\n",c);
				substring(temp,str,strlen(c)+1,strlen(str)-strlen(c));
				// printf("%s\n",temp);
				chdir(temp);

				break;
			}
		}
	}
}
void gotocd(char *toke, char *str)
{
	//printf("%s,%d\n",toke,strlen(toke));
	if(toke[0]=='~')
	{
		gototilde(str);
		char atoke[strlen(toke) + 2];
		if(strlen(toke)>2)
		{
			substring(atoke, toke, 2, strlen(toke) - 2);
			if (chdir(atoke) < 0)
			{
				perror("program");
			}
		}
	}
	else
	{
		if (chdir(toke) < 0)
		{
			perror("program");
		}
	}




}
void gotopwd()
{
	char c[1000];
	getcwd(c,sizeof(c));
	c[strlen(c)]='\0';
	printf("%s\n",c);
}
