/*
============================================================================
Name : 4.c
Author : Harshilkumar Buha
Description : Write a program to open an existing file with read write mode. Try O_EXCL flag also.
Date: 28th aug, 2023.
============================================================================
*/
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
int main()
{
    int fd = open("emp.txt",O_RDWR|O_EXCL);
    if(fd<0)
    {
        perror("File not opened");
        return -1;
    }
    printf("done\n");
    int w = close(fd);
    if(w==-1)
    {
        perror("file is not colsed yet");
        return -1;
    }
    return 1;

}
/*compile and run*/