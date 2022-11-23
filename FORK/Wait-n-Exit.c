//To write the program to implement the system calls wait( ) and exit( )
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, const char * argv[]) {
    pid_t cpid;
    if(fork()==0){//child
        printf("\nChild\nI am Child My ID is:  %d \n", getpid());
        printf("My Parent ID is: %d \n", getppid());
        exit(0);

    }else{//parent
        wait(NULL);
        printf("\nParent\nMy Childs ID is:  %d \n", cpid);
        printf("I am Parent ID is:  %d \n", getppid());
    }
    printf("OUTSIDE\n\n");
    
}
