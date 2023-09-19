/*
============================================================================
Name : 10.c
Author : Harshilkumar Buha
Description : Write a program to open a file with read write mode, write 10 bytes, move the file pointer by 10
bytes (use lseek) and write again 10 bytes.
a. check the return value of lseek
b. open the file with od and check the empty spaces in between the data.
Date: 29th aug, 2023.
============================================================================
*/
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<fcntl.h>
#include<string.h>
int main(){
	int f;
    char b[14] = "dart_op IGB_07";
	f=open("10_linux.txt" , O_RDWR | O_CREAT);
	if(f==-1)
	{
		perror("Error");
		return -1;
	}
	write(f, b , strlen(b));
	int fd=lseek(f,10,SEEK_CUR);
	printf("current pointer position = %d\n",fd);
	char b1[14] = "OP_IGB_DART_07";
	write(f, b1 , strlen(b1));
    return 0;
}
/*a) compile and run*/
/*b) write "od -a 10_linux.txt" in terminal*/