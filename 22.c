/*
============================================================================
Name : 22.c
Author : Harshilkumar Buha
Description : Write a program, open a file, call fork, and then write to the file by both the child as well as the
parent processes. Check output of the file.
Date: 3rd sep, 2023.
============================================================================
*/
#include<stdio.h>
#include<unistd.h>
#include<unistd.h>
#include<fcntl.h>
int main()
{
  int fd=open("22_linux.txt",O_WRONLY);
  if(fork()==0)
  {
    printf("child process\n");
    // lseek(fd,0L,SEEK_SET);
    write(fd,"child\n",6);
  }
  else
  {
    printf("parent process\n");
    write(fd,"parent\n",7);
  }
  return 0;
}
/*compile and run*/