/*
============================================================================
Name : 7.c
Author : Harshilkumar Buha
Description : Write a program to copy file1 into file2 ($cp file1 file2).
Date: 28th aug, 2023.
============================================================================
*/
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
int main(int argc,char* argv[])
{
    if(argc!=3)
    {
        printf("not working");
        return -1;
    }
    int fd_read = open(argv[1],O_RDONLY);
    int fd_write = open(argv[2],O_WRONLY | O_CREAT);
    if(fd_read==-1 || fd_write == -1)
    {
        printf("useless");
        return -1;
    }
    while(1)
    {
        char buf;
        int char_read = read(fd_read,&buf,1);
        // 1 indicates size of bytes to be read
        if(char_read==0)
            break;
        int char_write = write(fd_write,&buf,1);
    }
    int fdr_close =  close(fd_read);
    int fdw_close =  close(fd_write);
    if(fdr_close == -1 || fdw_close == -1)
    {
        printf("bad luck!");
        return -1;
    }
    return 0;
}
/*compile */
/* run and give names of file1 and file2
ex "./a.out <arg1(file from which we need to copy) <arg2(file in which we need to paste)>"*/