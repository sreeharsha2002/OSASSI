#include "headers.h"
#include "ls.h"
#include "fn.h"
#include "prompt.h"
#include "fgbg.h"
typedef struct node
{
    struct node *next;
    struct node *pr;
    int pid;
    char *command;
} node;
node *head = NULL;
char cw[1024];
void myhand(int signum)
{
    int status;
    //printf("sdvsdv");
    node *cur = head;
    node *pr = cur;
    while (cur != NULL)
    {

        if (waitpid(cur->pid, &status, WNOHANG) == cur->pid)
        {
            if (WIFEXITED(status))
            {
                fflush(stdout);
                fflush(stderr);
                fprintf(stderr, "\n%s with %d exited normally\n ", cur->command, cur->pid);
               // prompt(cw);
                if (cur == head)
                {
                    node *temp = head;
                    head = head->next;
                    cur = head;
                    free(temp);
                }
                else
                {
                    pr->next = cur->next;
                    node *temp = cur;
                    cur = cur->next;
                    free(temp);
                }
            }
            else if (WIFSIGNALED(status))
            {
                fflush(stdout);
                fflush(stderr);
                fprintf(stderr, "\n%s with %d exited abnormally\n ", cur->command, cur->pid);
              //  prompt(cw);
                if (cur == head)
                {
                    node *temp = head;
                    head = head->next;
                    cur = head;
                    free(temp);
                }
                else
                {
                    pr->next = cur->next;
                    node *temp = cur;
                    cur = cur->next;
                    free(temp);
                }
            }
        }
        else
        {
            pr = cur;
            cur = cur->next;
        }
    }
}

void gotobg(char *str)
{
    char *argv[1024];
    char delim[] = "\t ";
    char *token = strtok(str, delim);
    int i = 0;
    while (token != NULL)
    {
        argv[i] = (char *)malloc(sizeof(token) * sizeof(char));
        strcpy(argv[i], token);
        i++;
        token = strtok(NULL, delim);
    }
    argv[i]=NULL;
    int pid,status;
    if ((pid = fork()) < 0)
    {
        perror("program");
        exit(-1);
    }
    else if (pid == 0)
    {
        setpgid(0, 0);
        //printf("%s\n", argv[0]);
        if (execvp(argv[0], argv) < 0)
        {

            perror("command");
            exit(-1);
        }
    }
    else
    {
        setpgid(pid, pid);
        printf("\n[+] %d\n",pid);
        node *cur = (node *)malloc(sizeof(node));
        cur->pid = pid;
        cur->command = (char *)malloc(sizeof(1024));
        strcpy(cur->command, argv[0]);
        cur->next = head;
        head = cur;
        

        signal(SIGCHLD, myhand);
    }

}


void gotofg(char *str)
{
    char *argv[1024];
    char delim[] = "\t ";
    char *token = strtok(str, delim);
    int i = 0;
    while (token != NULL)
    {
        argv[i] = (char *)malloc(sizeof(token) * sizeof(char));
        strcpy(argv[i], token);
        i++;
        token = strtok(NULL, delim);
    }
    argv[i] = NULL;
    int pid;
    int status;

    if ((pid = fork()) < 0)
    {
        perror("program");
        exit(-1);
    }
    else if (pid == 0)
    {
        setpgid(0, 0);
        if (execvp(argv[0], argv) < 0)
        {
            perror("command");
            exit(-1);
        }
    }
    else
    {
        setpgid(pid, pid);
        signal(SIGTTIN, SIG_IGN);
        signal(SIGTTOU, SIG_IGN);
        tcsetpgrp(STDIN_FILENO, pid);
        waitpid(pid, &status, WUNTRACED);
        tcsetpgrp(STDIN_FILENO, getpgrp());
        signal(SIGTTIN, SIG_DFL);
        signal(SIGTTOU, SIG_DFL);
    }
}


void gotofgbg(char *str,int nofa,char*cwd_1)
{
    char delim[]="&";
    char amp[1024][1024];
    char *ptr=strtok(str,delim);
    int i=0;
    strcpy(cw,cwd_1);
    while(ptr!=NULL)
    {
        strcpy(amp[i],ptr);
        i++;
        ptr=strtok(NULL,delim);
    }
    for(int j=0;j<nofa;j++)
    {
        gotobg(amp[j]);
    }
    for(int j=nofa;j<i;j++)
    {
        gotofg(amp[j]);
    }
}