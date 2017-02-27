#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <iostream>
using namespace std;
void doSomeWork(char* name){
   const int NUM_TIMES = 1;
   for (int i = 0; i < NUM_TIMES; i++){
      sleep(rand() % 4);
      printf("Done pass %d for %s\n", i,name);
   }
}
int main(int argc, char* argv[]){
   printf("I am: %d\n", (int) getpid());
 
   pid_t pid = fork();
   srand((int) pid);
   printf("Fork returned: %d\n", (int) pid);
   
   if(pid < 0){
      perror("fork failed");
   }
   if(pid == 0){
      printf("I am the child with pid%d\n", (int) getpid());
      doSomeWork("child");
      exit(42);

   }
   
   // We must be the parent
   printf("I am the parent, waiting for child to end\n");
   sleep(10);
   // doSomeWork("Parent");
   
   int status = 0;
   
   pid_t childpid = wait(&status);
   
   printf("parent knows child %d finished with status %d\n", (int)childpid, status);
   int childReturnValue = WEXITSTATUS(status);
   printf("     return vaule was %d\n", childReturnValue);
   sleep(50);
   
   
   // text here lmao
   return 0;
}
