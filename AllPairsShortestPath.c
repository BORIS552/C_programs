#include <stdio.h>
#include <stdlib.h>
#define ROW 20


void printGraph(int n,int arr[][ROW])
{
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if(arr[i][j] == 999999){
				printf("X ");
			} else {
			printf("%d ",arr[i][j]);
			}
		}
		printf("\n");
	}
}


//floyd-warshall algorithm.
void AllPairsShortestPath(int n, int arr[][ROW])
{
	int dist[n][n],i,j,k;
	for(k = 0; k < n; k++) {
		for(i = 0; i < n; i++) {
			for(j = 0; j < n; j++) {
				if(arr[i][k]+arr[k][j] < arr[i][j])
					arr[i][j] = arr[i][k]+arr[k][j];
			}
		}
	}

	printGraph(n,arr);
}

int main() {


	int arr[20][20], len = 0, c, bytesread;

	char ch[1];
	int n;
	gets(ch);
	n = atoi(ch);
	char input[50];
	

	/* converting string of numbers with spaces into integer 2d array.*/
	for(int i = 0; i < n; i++){
		len = 0;
		char* input1 = NULL;
		fgets(input, sizeof(input), stdin);
		input1 = input;
		while(sscanf(input1,"%d%n", &c, &bytesread) > 0) {
				arr[i][len++] = c;
				input1 = input1 + bytesread;
		}
	}

	AllPairsShortestPath(n,arr);
	return 0;
}