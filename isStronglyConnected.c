#include <stdio.h>
#include <stdlib.h>

#define ROW 20

int visited[ROW];


int STACK[ROW];
int top = -1;

void push(int i) {
	top++;
	STACK[top] = i;
}

void pop() {
top--;
}



void dfs(int arr[][ROW],int source,int n) {
	int i,j,k,vertex;

	push(source);
	visited[source] = 1;
	while(top != -1) {
		vertex = STACK[top];
		printf("\n %d \n",vertex );
		pop();
		for(j = 0; j < n; j++) {
				if(arr[vertex][j] == 1) {
					if(visited[j] == 0){
						push(j);
						visited[j] = 1;
					}
				}
		}
	}

}



int checkVisited(int n) {

	for(int i = 0; i < n; i++) {
		printf("%d ",visited[i] );
		if(visited[i] == 0)
			return 0;
	}
	
	return 1;
}


int IsStronglyConnected(int n, int arr[][ROW]) {
	int i,j,k;
	int flag ;
	int transpose[20][20];
	for(i = 0; i < n; i++) 
		visited[i] = 0;
	dfs(arr,0,n);

	if(checkVisited(n) == 1)
		flag = 1;
	else
		return 0;

	for(i = 0; i < n; i++) 
		visited[i] = 0;

	for(i = 0; i < n; i++)
		for(j = 0; j < n; j++)
			transpose[j][i] = arr[i][j];
	dfs(transpose,0,n);

	if(checkVisited(n) == 1)
		flag = 1;
	else
		flag = 0;

	return flag;
}



int main() {

int temp[20][20], len = 0, c, bytesread,i,j,a,b;
	int arr[20][20];
	int flag = 0;
	char ch[1];
	char ch2[1];
	int n;
	int e;
	gets(ch);
	n = atoi(ch);
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
		 j = 0;
		 a = temp[i][0];
		 b = temp[i][1];
		 arr[a][b] = 1;
	}


	flag = IsStronglyConnected(n,arr);

	if(flag == 1)
		printf("\ntrue");
	else
		printf("\nfalse");
	return 0;

}