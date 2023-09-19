/*
============================================================================
Name : 25.c
Author : Harshilkumar Buha
Description : Write a program to create three child processes. The parent should wait for a particular child (use
waitpid system call).
Date: 8th sep, 2023.
============================================================================
*/
#include<stdio.h>
#include<unistd.h>
#include <fcntl.h>
#include<stdlib.h>
#include<sys/wait.h>

int main()
{
  int wstatus;
  pid_t ch_pid1;
  ch_pid1=fork();
  
  if(ch_pid1==0)
  {
   printf("First Child pid:%d\n",getpid());
   printf("first Child Parent pid:%d\n",getppid());
  }
  else
  {
    waitpid(-1, &wstatus, 0);
    pid_t ch_pid2=fork();
    if(ch_pid2==0)
    {
      printf("second Child pid:%d\n",getpid());
      printf("second Child Parent pid:%d\n",getppid());
    }
    else
    {
      waitpid(-1, &wstatus, 0);
      pid_t ch_pid3=fork();
      if(ch_pid3==0)
      {
        printf("third Child pid:%d\n",getpid());
        printf("third Child Parent pid:%d\n",getppid());
      }
      else
      {
        waitpid(-1, &wstatus, 0);
        printf("parent of all is:%d\n",getpid());
      }
    }
  }
}
/*compile and run*/