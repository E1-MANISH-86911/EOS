/*1. Create a thread to sort given array of 10 integers using selection sort. Main thread should 
print the result after sorting is completed.
Hint: Pass array to thread function (via arg4 of pthread_create()).
void* thread_func(void *param) {
int *arr = (int*)param;
// ... code to sort the array
return NULL;
}*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
struct input{
	int n;
	int arr[100];
};
void *selection_sort(void *param){
	struct input *ip = (struct input*)param;
	for(int i=0; i<ip->n-1; i++){
		int min_idx=i;
		for(int j= i+1; j<ip->n; j++){
			if(ip->arr[j]<ip->arr[min_idx]){
				min_idx=j;
			}
		}
		int temp = ip->arr[i];
		ip->arr[i] = ip->arr[min_idx];
		ip->arr[min_idx] = temp;
	}
	return NULL;
}
int main(){
	pthread_t th;
	struct input in;
	printf("Enter the size of array: ");
	scanf("%d", &in.n);
	printf("Enter array elements: ");
	for(int i=0; i<in.n; i++){
		scanf("%d", &in.arr[i]);
	}
	pthread_create(&th, NULL, selection_sort, &in);
	pthread_join(th, NULL);
	printf("Array after sorting: ");
	for(int i=0; i<in.n; i++){
		printf("%d ", in.arr[i]);
	}
	printf("\n");
	return 0;
}
