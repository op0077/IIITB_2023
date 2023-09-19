/*
============================================================================
Name : 3.c
Author : Harshilkumar Buha
Description : Write a program to create a file and print the file descriptor value. Use creat ( ) system call
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
    int file_descriptor = creat("new_file",O_CREAT);
    printf("discriptor value of file%d\n",file_descriptor);
    if(file_descriptor==-1)
    {
        perror("File not created");
        return -1;
    
    }
    int w = close(file_descriptor);
    if (w==-1)
    {
        perror("File is not closed yet");
        return -1;
    }
    return 0;

}
/*compile and run*/