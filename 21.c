/*
============================================================================
Name : 21.c
Author : Harshilkumar Buha
Description : Write a program, call fork and print the parent and child process id.
Date: 2nd sep, 2023.
============================================================================
*/
#include<fcntl.h>
#include<stdio.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/resource.h>
int main()
{
    pid_t child_pid=fork();
    if(child_pid<0)
    {
        perror("fork failed");
        return -1;
    }
    if(child_pid==0)
    {
        printf("child process : %d\n",getpid());
        return 0;
    }
    else
    {
        printf("parent process : %d\n",getpid());
        return -1;
    }
    return 0;
}
/*compile and run*/