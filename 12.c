#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
int main()
{
    int fd = open("emp.txt",O_WRONLY);
    int a = fcntl(fd,F_GETFL);
    a=a&O_ACCMODE;
    if(a==0)
    {
        printf("Read Only Mode\n");
    }
    else if(a==1)
    {
        printf("Write Only Mode\n");
    }   
    else
    {
        printf("Read And Write Mode\ns");
    }
    return 0;
}