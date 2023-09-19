/*
============================================================================
Name : 11.c
Author : Harshilkumar Buha
Description : Write a program to open a file, duplicate the file descriptor and append the file with both the
descriptors and check whether the file is updated properly or not.
a. use dup
b. use dup2
c. use fcntl
Date: 29th oct, 2023.
============================================================================
*/
#include<stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include<string.h>
int main()
{
	int fd = open("dup.txt", O_RDWR);
	if(fd < 0)
	{
		printf("File is missing\n");
		return -1;
	}
	char buf[3];
	read(fd,&buf,3);
	lseek(fd,0L,SEEK_SET);
	printf("current fd : %s\n",buf);

	//dup
	int copy_fd = dup(fd);
	char buf1[3];
	read(copy_fd,&buf1,3);
	lseek(copy_fd,0L,SEEK_SET);
	printf("\nafter using dup\n");
	printf("current copy_fd : %s\n",buf1);
	

	
	//new fd1 for using dup2
	int fd1 = open("dup2.txt",O_RDWR);
	char buf2[3];
	read(fd1,&buf2,3);
	lseek(fd1,0L,SEEK_SET);
	printf("\ncurrent fd1 : %s\n",buf2);


	//dup2
    dup2(fd1, fd); 
	printf("\nafter using dup2\n");
	char buf3[3];
	char buf4[3];
	read(fd,&buf3,3);
	printf("current fd : %s",buf3);
	// now both fd1 and fd are the file descriptor of the same file(dup2.txt)


	//fcntl
	printf("\n\nafter using fcntl");
	fd=open("dup3.txt",O_RDWR|O_APPEND|O_CREAT,0644);
	int fcntl_fd = fcntl(fd, F_DUPFD,10);
	char buf5[3];
	read(fcntl_fd,&buf5,3);
	printf("\ncurrent fcntl_fd:  %s",buf5);
    printf("\nDone\n");
	return 0;
}
/*compile and run*/