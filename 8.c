/*
============================================================================
Name : 8.c
Author : Harshilkumar Buha
Description : Write a program to open a file in read only mode, read line by line and display each line as it is read.
Close the file when end of file is reached.
Date: 29th aug 2023.
============================================================================
*/
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
int main(int argc,char* argv[])
{
    int f1 = open("f1",O_RDONLY);
    if(f1==-1)
    {
        printf("file is not opened");
        return 0;
    }
    while(1)
    {
        char buf;
        int char_read = read(f1,&buf,1);
        if(char_read==0)
            break;
        printf("%s",&buf);
    }
    int f1_close = close(f1);
    if(f1_close==-1)
    {
        printf("file is not closed yet");
    }
    printf("\nfile copied\n");
    return 0;
}
/*compile and run*/