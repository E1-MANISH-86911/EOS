/*2. Create a thread to sort given array of "n" integers using bubble sort. Main thread should print the result after 
sorting is completed.
Hint: struct array { int *arr; int size; }
Pass struct address to thread function (via arg4 of pthread_create()).*/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
struct array{
	int *arr;
	int size;
};
void *bubble_sort(void *param){
	struct array *a = (struct array*)param;
	for(int i=0; i<a->size-1; i++){
		for(int j=0; j<a->size-i-1; j++){
			if(a->arr[j]>a->arr[j+1]){
				int temp = a->arr[j];
				a->arr[j] = a->arr[j+1];
				a->arr[j+1] = temp;
			}
		}
	}
	return NULL;
}
int main(){
	pthread_t th;
	struct array a;
	printf("Enter the size of array: ");
	scanf("%d", &a.size);
	printf("Enter array elements: ");
	for(int i=0; i<a.size; i++){
		scanf("%d", &a.arr[i]);
	}
	pthread_create(&th, NULL, bubble_sort, &a);
	pthread_join(th, NULL);
	printf("Array after sorting: ");
	for(int i=0; i<a.size; i++){
		printf("%d ", a.arr[i]);
	}
	printf("\n");
	return 0;
}
