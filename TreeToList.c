#include <stdio.h>
#include <stdlib.h>


struct Node{
	int data;
	struct Node *next;
};
struct Node *head = NULL;

void push(int data) {
	struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = data;
	newNode->next = head;
	head = newNode;
}

void treeToList(int arr[],int start, int end) {
	if(start > end)
		return;
	treeToList(arr,start*2 + 1, end);
	push(arr[start]);
	treeToList(arr,start*2 + 2,end);
}

void printList() {
	while(head != NULL) {
		printf("%d ",head->data );
		head = head->next;
	}
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

	treeToList(arr,0,len-1);
	printList();	


}