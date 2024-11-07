/*3. Find max number of child processes that can be created on Linux using C program? Hint: use fork() in inﬁnite loop (wisely).*/

#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main(){
	int ret, cnt = 0;
	while(1){
		ret = fork();
		if(ret == -1){
			printf("fork() failed.\n");
			break;
		}
		else if(ret == 0){
			sleep(5);
			_exit(0);
		}
		else{
			cnt++;
			printf("Child count: %d\n", cnt);
		}
	}
	while(wait(NULL) > 0);
	printf("All child processes cleaned up. Total child processes created: %d\n", cnt);
	return 0;
}

