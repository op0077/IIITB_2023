/*
============================================================================
Name : 24.c
Author : Harshilkumar Buha
Description : Write a program to create an orphan process.
Date: 8th sep, 2023.
============================================================================
*/
#include<stdio.h>
#include<unistd.h>
#include <unistd.h>
#include <fcntl.h>
#include<stdlib.h>
int main()
{
    pid_t child_pid=fork();

    if(child_pid==0)
    {
        sleep(5); //child goes to sleep and in the meanwhile parent terminates
        printf("\nChild process id %d\n",getpid());
        printf("Parent process id %d\n",getppid());
        printf("child process is adopted by init process\n");
        exit(0);
    }
    else
    {
        printf("\nparent process id %d\n",getpid());
        printf("child pid %d\n",child_pid);
    }
    return 0;
} 
/*compile and run*/