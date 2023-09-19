/*
============================================================================
Name : 13.c
Author : Harshilkumar Buha
Description : Write a program to wait for a STDIN for 10 seconds using select. Write a proper print statement to
verify whether the data is available within 10 seconds or not (check in $man 2 select)
Date: 29th aug, 2023.
============================================================================
*/
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/select.h>
#include<fcntl.h>
#include<stdio.h>
#include<unistd.h>

int main()
{
    int retval;
    fd_set rfds;
    //fds = file descriptor size 
    struct timeval tv;
    
    FD_ZERO(&rfds);
    FD_SET(0,&rfds);
    
    tv.tv_sec =10;
    printf("enter input before 10sec\n");
    retval = select(2, &rfds, NULL, NULL, &tv);
    if (retval == -1)
         perror("select()");
    else if (retval)
         printf("Done\n");
    else
         printf("time is over\n");
   return 0;

}
/*compile and run*/