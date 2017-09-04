#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

struct Node {
	int disc;
	int low;
	int parent;
	int index;
	int adj[SIZE];
};

struct Node vertex[SIZE];
int visited[SIZE];




int min (int a, int b) {
	return (a < b ? a : b);
}

void bridgeUtility(int u) {
	static int time = 0;
	int v;
	visited[u] = 1;

	vertex[u].disc = vertex[u].low = ++time;
	int j = 0;
	while( j < vertex[u].index) {
		v = vertex[u].adj[j];

		if(visited[v] == 0) {
			vertex[v].parent = u;
			bridgeUtility(v);

			vertex[u].low = min(vertex[u].low, vertex[v].low);
			if(vertex[v].low > vertex[u].disc) {
				printf("%d %d ",u,v);
				printf("\n");
			}
		}else if(v != vertex[u].parent)
				vertex[u].low = min(vertex[u].low, vertex[v].disc); 

		j++;
	}
}

void findBridge(int n) {
int i;

	for(i = 0; i < n; i++) {
		if(visited[i] == 0)
			bridgeUtility(i);
	}

}


void initializeNode(int n) {
	for(int i = 0; i < n; i++ ) {
		vertex[i].disc = 0;
		vertex[i].low = 0;
		vertex[i].index = 0;
		vertex[i].parent = 0;
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

		 vertex[b].adj[vertex[b].index] = a;
		 vertex[b].index = vertex[b].index + 1;
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

	findBridge(n);
	return 0;
}