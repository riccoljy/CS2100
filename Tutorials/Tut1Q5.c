#include <stdio.h>
#define MAX 10

int readArray(int [], int);
void printArray(int [], int);
void reverseArray(int [], int);
void reverseArrRec(int[], int);

int main(void) {
	int array[MAX], numElements;

	numElements = readArray(array, MAX);
	reverseArrRec(array, numElements);
	printArray(array, numElements);

	return 0;
}

int readArray(int arr[], int limit) {
	printf("Enter up to %d integers, terminating with a negative integer.\n", limit);
	int count = 0;
	int input;
	while (count < limit)	{
		scanf("%d", &input);
		if (input < 0) break;
		arr[count++] = input;
	}
	return count;
}

void reverseArray(int arr[], int size) {
	for (int i = 0;i < size/2; i++){
	int temp = arr[i];
	arr[i] = arr[size-1-i];
	arr[size-1-i] = temp;
}
}

void reverseArrRec(int arr[], int size){
	if (size <= 1) return;
	int temp = arr[0];
	arr[0] = arr[size-1];
	arr[size-1] = temp;

	reverseArrRec(&arr[1], size-2);
}

void printArray(int arr[], int size) {
	int i;

	for (i=0; i<size; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

