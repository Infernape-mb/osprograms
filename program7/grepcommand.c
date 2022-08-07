 //simulation of grep command
 #include<stdio.h>
 #include<stdlib.h>
 #include<string.h>
 
 int main(int argc,char *argv[])
 {
   if(argc<2)
   {
    printf("You have not entered the file name\n");
    exit(0);
   }
   char pat[50],temp[200];//file name and pattern
   printf("Enter the pattern\n");
   scanf("%s",pat);
   FILE *fp;
   fp=fopen(argv[1],"r");
   while(!feof(fp))
   {
    fgets(temp,200,fp);
    if(strstr(temp,pat))
     printf("%s",temp);
    }
    }
   
