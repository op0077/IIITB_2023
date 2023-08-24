#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<fcntl.h>
#include<string.h>
#include<iostream>
using namespace std;
int main(){
	int f;
    char b[15] = "dart_op_IGB_07";
	f=open("10_linux.txt" , O_RDWR | O_CREAT);
	if(f<0)
	{
		perror("Error");
	}
	write(f, b , strlen(b));
	int fd=lseek(f,10,SEEK_CUR);
	cout<<"current pointer position = "<<fd<<endl;
	char b1[15] = "OP_IGB_DART_07";
	write(f, b1 , strlen(b1));
    return 0;
}