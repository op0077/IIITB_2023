/*
============================================================================
Name : 12.c
Author : Harshilkumar Buha
Description : Write a program to find out the opening mode of a file. Use fcntl
Date: 29th aug, 2023.
============================================================================
*/
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
int main()
{
    int fd = open("emp.txt",O_WRONLY);
    int a = fcntl(fd,F_GETFL);
    //Write a program to find out the opening mode of a file. Use fcntl;
    a=a&O_ACCMODE;
    if(a==0)
    {
        printf("file is Read Only\n");
    }
    else if(a==1)
    {
        printf("file is Write Only\n");
    }   
    else
    {
        printf("file is Read And Write\n");
    }
    return 0;
}
/*compile and run*/