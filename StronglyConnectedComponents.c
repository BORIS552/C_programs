#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

struct Node {
	int disc;
	int low;
	int index;
	int adj[SIZE];
};

struct Node vertex[SIZE];
int visited[SIZE];

int stack[SIZE];
int top;

void push(int v) {
++top;
stack[top] = v;
}

void pop() {
	top--;

}


int min (int a, int b) {
	return (a < b ? a : b);
}

void SCCUtility(int u) {
	static int time = 0;
	int v;
	push(u);
	visited[u] = 1;

	vertex[u].disc = vertex[u].low = ++time;
	for(int j = 0; j < vertex[u].index; j++) {

		v = vertex[u].adj[j];

		if(vertex[v].disc == -1) {
			SCCUtility(v);

			vertex[u].low = min(vertex[u].low, vertex[v].low);

		}else if(visited[v] == 1)
				vertex[u].low = min(vertex[u].low, vertex[v].disc); 

	}

	int w = 0;
	if(vertex[u].low == vertex[u].disc) {
		while(stack[top] != u) {
			w = stack[top];
			printf("%d ",w);
			visited[w] = 0;
			pop();
		}
		w = stack[top];
		printf("%d \n",w);
		visited[w] = 0;
		pop();
	}
}

void findSCC(int n) {
int i;

	for(i = 0; i < n; i++) {
		if(vertex[i].disc == -1)
			SCCUtility(i);
	}

}


void initializeNode(int n) {
	top = -1;
	for(int i = 0; i < n; i++ ) {
		vertex[i].disc = -1;
		vertex[i].low = 0;
		vertex[i].index = 0;
		visited[i] = 0;
	}
}

int main() {
	

	int temp[20][20], len = 0, c, bytesread,i,j,a,b;
	int flag = 0;
	//int arr[20][20];
	char ch[1];
	char ch2[1];
	int n;
	int e;
	gets(ch);
	n = atoi(ch);
	initializeNode(n);
	gets(ch2);
	e = atoi(ch2);

	char input[10];
	

	/* converting string of numbers with spaces into integer 2d array.*/
	for(i = 0; i < e; i++){
		len = 0;
		char* input1 = NULL;
		fgets(input, sizeof(input), stdin);
		input1 = input;
		while(sscanf(input1,"%d%n", &c, &bytesread) > 0) {
				temp[i][len++] = c;
				input1 = input1 + bytesread;
		}
	}

	for(i = 0; i < e; i++) {
		 a = temp[i][0];
		 b = temp[i][1];
		 vertex[a].adj[vertex[a].index] = b;
		 vertex[a].index = vertex[a].index + 1;

	}

	for (int i = 0; i < n; i++)
	{
		int j = 0;
		printf("%d: ", i);
		while( j < vertex[i].index) {
			
			printf("%d ",vertex[i].adj[j] );

			j++;
		}
		printf("\n");
	}

	findSCC(n);
	return 0;
}