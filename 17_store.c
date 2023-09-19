/*
============================================================================
Name : 17_store.c
Author : Harshilkumar Buha
Description : Write a program to simulate online ticket reservation. Implement write lock
Write a program to open a file, store a ticket number and exit. Write a separate program, to
open the file, implement write lock, read the ticket number, increment the number and print
the new ticket number then close the file.
Date: 29th aug, 2023.
============================================================================
*/
#include<fcntl.h>
#include<stdio.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<unistd.h>
int main()
{
    struct{
        int ticket_no;
    }ticket;
    int fd = open("ticket.txt",O_RDWR);
    int t;
    printf("Enter the ticket no. ");
    scanf("%d",&t);
    ticket.ticket_no=t;
    write(fd,&ticket,sizeof(ticket));
    int w = close(fd);
    if(w==-1)
        printf("file is not closed yet");
    return 0;
}
/*copile and run*/