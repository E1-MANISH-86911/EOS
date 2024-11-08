/**/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#include<signal.h>
int main(){
	int pid, pid1;
	int sig, ret;
	printf("Enter signal number: ");
	scanf("%d", &sig);
	printf("Enter process id: ");
	scanf("%d", &pid);
	ret = kill(pid, sig);
	if(ret == -1){
		printf("Kill failed. \n");
		exit(1);
	}
	return 0;
}

