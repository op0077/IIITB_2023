#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
int main()
{
    char m[10];
    read(STDOUT_FILENO,m,10);
    write(STDIN_FILENO,m,10);
    return 0;

}