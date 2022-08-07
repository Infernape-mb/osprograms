//emulate ls command in c
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<dirent.h>

  void main(int argc,char *argv[])
  {
   if(argc<2){
    printf("you haven't entered the directory name\n");
    exit(0);
  }
  DIR *dp;
  struct dirent *dirp;
  if((dp=opendir(argv[1]))==NULL)
  {
   printf("Directory don't exist\n");
   exit(0);
  }
  while((dirp=readdir(dp))!=NULL)
   printf("%s\n",dirp->d_name);
   closedir(dp);
   }
   
   
   
