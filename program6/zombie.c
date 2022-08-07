//Orphan process
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
int main() 
{
  pid_t child_pid, my_pid, parent_pid;
  child_pid = fork();
  if (child_pid < 0) 
  {
  printf("Fork failed. Exiting!\n");
  exit(0);
  }
  if (child_pid == 0) 
  {
  // Child process
  printf("[CHILD] This is the child process.\n");
  my_pid = getpid();
  parent_pid = getppid();
  printf("[CHILD] My pid is %d\n", my_pid);
  printf("[CHILD] My parent's pid is %d\n", parent_pid);
  printf("[CHILD]exiting\n");
  exit(0);
 
  } 
  else 
  {
  // Parent process
  printf("[PARENT] This is the parent process.\n");
  my_pid = getpid();
  parent_pid = getppid();
  printf("[PARENT] My pid is %d\n", my_pid);
  printf("[PARENT] My parent's pid is %d\n", parent_pid);
  printf("[PARENT] Exiting.\n");
  printf("[PARENT] waiting for child to terminate\n");
   sleep(10);
    printf("[CHILD]Child with pid %d has enden but it has entry in process table so it's a zombie process\n",child_pid );
  }
return 0;
}

