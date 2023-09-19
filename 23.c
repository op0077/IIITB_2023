/*
============================================================================
Name : 23.c
Author : Harshilkumar Buha
Description : Write a program to create a Zombie state of the running program.
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
    pid_t child_pid = fork();
    // pid_t child_pid1 = fork();
    if(child_pid > 0)
    {
      printf("child process id:%d\n",getpid());
    }
    else  
    {      
      sleep(5);
      printf("parent process id:%d\n",getpid());
      exit(0);
    }
    return 0;
}
/*compile and run*/