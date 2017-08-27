#include <stdio.h>
#include <stdlib.h>
#define SIZE 20
int values[SIZE];


int hashCode(int val) {
	return val%SIZE;
}
void removeDuplicates(int arr[],int len) {
	int key; 
	for(int i = 0 ; i < len; i++) {
		key = hashCode(arr[i]);
	if(values[key] == -9999)
	   values[key] = arr[i];
}
}
void initialise() {
	for(int i = 0; i < SIZE; i++ )
		values[i] = -9999;
}
void display() {
	for(int i = 0; i < SIZE; i++)
		if(values[i] == -9999)
			continue;
		else
			printf("%d ",values[i]);
}
int main() {
	int arr[100], len = 0, c, bytesread;
	char input[100];
	fgets(input, sizeof(input), stdin);
	char* input1 = input;
	/* converting string of numbers with spaces into integer array.*/
	
	while(sscanf(input1,"%d%n", &c, &bytesread) > 0) {
			arr[len++] = c;
			input1 = input1 + bytesread;
	}
	initialise();
	//for(int i = 0; i < len; i++)
		removeDuplicates(arr,len);

	display();
	return 0;
}