/*2. From a parent process (A) create a child process (B). The child (B) in turn creates new child process (C) and it (C) in turn create new child (D). All these
processes should run concurrently for 5 seconds and cleaned up properly upon termination.*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>


int main() { 
	int ret_b = 0, ret_c = 0, ret_d = 0;
	ret_b = fork(); 
	if(ret_b == 0) { 
		ret_c = fork();
	if(ret_c == 0) {   
		ret_d = fork(); 
		if(ret_d == 0) 
		{
			for(int i=1; i<=5; i++)
			{
				printf("Process D: %d\n", i);
				sleep(1);
			}
			_exit(7);  
		}
		else { 
			for(int i=1; i<=5; i++) {
					printf("Process C: %d\n", i);
					sleep(1);
				}
			int n_d;
			waitpid(ret_d, &n_d, 0);  
			printf("Exit status from process D: %d\n", WEXITSTATUS(n_d));
			exit(6); 
		}
	} 
	else {
		for(int i=1; i<=5; i++) {
			printf("Process B: %d\n", i);
			sleep(1);
		}
			int n_c;
			waitpid(ret_c, &n_c, 0); 
			printf("Exit status from process C: %d\n", WEXITSTATUS(n_c));
			_exit(5); 
		}
	}  
	else {  
		for(int i=1; i<=5; i++){
			printf("Process A: %d\n", i);
			sleep(1);
		}
		int n_b;
		waitpid(ret_b,&n_b, 0);
		printf("Exit status from process B: %d\n", WEXITSTATUS(n_b));
	}
	return 0;
}  
