#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

  
void forkexample()
{
    int i;
	for(i=0;i<5;i++)
	{
		int pid = fork();
		if(pid<0)
		{
			printf("fork failed");
		}
		else if(pid==0)
		{
			execlp("anyString","is",NULL);
		}
		else {
			printf("processs called %d\n",getpid());
			wait(NULL);
		return ;
		}
	}
}

int main()
{
	forkexample();
  	return 0;
}