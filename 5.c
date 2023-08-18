#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
int main(void)
{
    int f1,f2,f3,f4,f5;
    f1 = open("f1",O_RDWR);
    f2 = open("f2",O_RDWR);
    f3 = open("f3",O_RDWR);
    f4 = open("f4",O_RDWR);
    f5 = open("f5",O_RDWR);
    getchar();
}