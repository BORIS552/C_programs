#include <stdio.h>
#include <stdlib.h>

#define ROW 20


int IsDag(int n,int arr[][ROW]) {

	int indeg[n],flag[n],i,j,k,count = 0;
	int check = 0;

	for(i = 0; i < n; i++) {
		indeg[i] = 0;
		flag[i] = 0;
	}		
	for(i = 0; i < n; i++){
		for(j = 0; j < n ;j++)
			indeg[i] = indeg[i] + arr[j][i];
	}

	while(count < n){
		check = 0;
		for(k = 0; k < n; k++) {
			if(indeg[k] == 0 && flag[k] == 0){
					//printf("%d ",k);
				flag[k] = 1;	
				check = 1;	
				for(int l = 0; l< n; l++)
					arr[k][l] = 0;
					break;		
			}
		}

		for(i = 0; i < n; i++)
			indeg[i] = 0;

		for(i = 0; i < n; i++){
		for(j = 0; j < n ;j++)
			indeg[i] = indeg[i] + arr[j][i];
		}

		count++;
	}

	if(check == 0)
		return 0;
	else 
		return 1;

	return 0;
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


	flag =IsDag(n,arr);

	if(flag == 1)
		printf("\ntrue");
	else
		printf("\nfalse");
	return 0;
}