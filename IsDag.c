#include <stdio.h>
#include <stdlib.h>

#define ROW 20
int STACK[ROW];
int top = -1;

void push(int i) {
	printf("Top Now:%d\n",top );
	top++;
	STACK[top] = i;
	printf("%dTop, %d \n",top,STACK[top]);
}

void pop() {
	printf("%dTop, %d \n",top,STACK[top]);
top--;
printf("Top Now:%d\n",top );
}

int checkStack() {
	for(int i = 0; i < top; i++)
		for(int j = i+1; j < top; j++) {
			if(STACK[i] == STACK[j])
				return 1;
		}

	return 0;		
}

int IsDag(int n, int arr[][ROW]) {
	int i,j,k,vertex,visited[n];
	int flag = 0;
	for(i = 0; i < n; i++)
		visited[i] = 0;

	push(0);
	visited[0] = 1;
	while(top != -1) {
		vertex = STACK[top];
		printf("%d\n",vertex );
		pop();
		for(j = 0; j < n; j++) {
				if(arr[vertex][j] == 1) {
					if(visited[j] == 0){
						push(j);
						visited[j] = 1;
					}else{
						return 0;
					}
				}
		}
	}

return 1;

}


int main() {
	int temp[20][20], len = 0, c, bytesread,i,j,a,b;
	int flag = 0;
	int arr[20][20];
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

	for(i = 0; i < n; i++) {
		for(j = 0; j < n; j++)
			printf("%d ",arr[i][j]);
		printf("\n");
	}


	flag = IsDag(n,arr);

	if(flag == 1)
		printf("true");
	else
		printf("false");
	return 0;
}