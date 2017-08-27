#include<stdio.h>
#include<stdlib.h>

int main() {
	int arr[100], len = 0, c, bytesread;
	char input[100];
	fgets(input, sizeof(input), stdin);
	char* input1 = input;
	while(sscanf(input1,"%d%n", &c, &bytesread) > 0) {
			arr[len++] = c;
			input1 = input1 + bytesread;
	}
printf("\n");
for(int i = 0; i <= len-1; i++) {
	printf("%d,",arr[i] );
}
return 0;
	
}