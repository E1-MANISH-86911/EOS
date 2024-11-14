//*1. Thread sum of integers in given range (start number and end number). Print result in main().

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
struct input{
	int start;
	int end;
};
struct output{
	int out;
};
void* sum(void *param){
	struct input *ip = (struct input *)param;
	struct output *op = (struct output *)malloc(sizeof(struct output));
	op->out=0;
	for(int i=ip->start; i<=ip->end; i++){
		op->out+=i;
	}
	return op;
}

int main(){
	pthread_t th;
	struct input in;
	struct output *op;
	printf("Enter start number: ");
	scanf("%d", &in.start);
	printf("Enter end number: ");
	scanf("%d", &in.end);
	pthread_create(&th, NULL, sum, &in);
	pthread_join(th, (void**)&op);
	printf("Result=%d\n", op->out);
	return 0;
}
