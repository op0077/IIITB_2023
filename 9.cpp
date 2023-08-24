#include<stdio.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdlib.h>
#include<sys/sysmacros.h>
#include<time.h>
#include<iostream>
using namespace std;
int main(){
    struct stat sfile;
    stat("f1.txt", &sfile);
    cout<<"\ninode number:"<<sfile.st_ino;
    cout<<"\nsize of the file:"<<sfile.st_size;
    cout<<"\ntotal number of hard link:%lu", sfile.st_nlink;
    cout<<"\nuserid:"<< sfile.st_uid;
    cout<<"\nblock size:"<< sfile.st_blksize;
    cout<<"\ngroup id:"<< sfile.st_gid;
    cout<<"\ntotal number of blocks:"<< sfile.st_blocks;
    cout<<"\ntime of last access:"<< sfile.st_atime;
    cout<<"\ntime of recent modification:"<< sfile.st_mtime;
    cout<<"\ntime of last change:"<<sfile.st_ctime;
    return 0;
}