#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>
#include<stdlib.h>

int main(int argc, char *argv[])
{
         int k = 2, n1, n2, n3;
         void *ptr;
         int shm_fd = shm_open("OS", O_CREAT | O_RDWR, 0666);
         ftruncate(shm_fd, 4096);
         ptr = mmap(0,4096,PROT_WRITE, MAP_SHARED, shm_fd, 0);
         printf("CHILD:\n");
         int i = atoi(argv[1]);
         n1 = 0;
         n2 = 1;
        for(int j = 0; j < i; j++)
        {
            printf("%d ",n1);
            sprintf(ptr,"%d ",n1);
            n3 = n1 + n2;
            n1 = n2;
            n2 = n3;
            ptr += strlen(ptr);
        }
        }
