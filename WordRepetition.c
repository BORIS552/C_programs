#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define SIZE 100
int min = 999;
struct DataItem {
	char key[20];
	int position;
};

struct DataItem* hashArray[SIZE];
struct DataItem* item = NULL;
void initialize() {
	for(int i = 0; i < SIZE ;i++)
		hashArray[i] = NULL;
}

//hashfunction.
/*
* multiplying each ascii value of character in word by a prime number.
* here int this case prime number is 31.
* (USED BY JAVA):http://docs.oracle.com/javase/6/docs/api/java/lang/String.html#hashCode%28%29
* More likely to produce 
* unique numbers. 
* using pow() for making the value unique so that "stop" and "pots"
* do not return the same value.
*/

long long  hashCodeIndex(char str[]) {

	long long index = 0LL;
	int prime = 3;
	int len = strlen(str);
	for(int i = 0; i <len; i++){
		index = index + ((int)str[i]*pow(31,len-i)) ;
	}
	return index;
}

void insert(char key[],int pos) {

	
	int dist;
	long long hashIndex = hashCodeIndex(key);
	printf("%llu \n",hashIndex );
	

	while( hashIndex > 100) {
		hashIndex %= SIZE;
		printf("%llu :index in while\n",hashIndex);
	}
	//printf("%dindexOutofWhile\n", hashIndex);
	//printf("\n %d \n",SIZE);

	
	if(hashArray[hashIndex] == NULL)
		{

		item = (struct DataItem*)malloc(sizeof(struct DataItem));
		strncpy(item->key,key,strlen(key));
		hashArray[hashIndex] = item;
		item->position = pos;
		printf("%d :pos\n",pos);
		}
		else{
			dist = pos - hashArray[hashIndex]->position;
			if(dist < min)
				min = dist;
			printf("%d :pos\n", pos);
			printf("%d :dist\n",dist);
			printf("%d :min\n", min);
			hashArray[hashIndex]->position = pos;

		} 
	
}


int main() {
	char str[20];
	char ch[2];
	gets(ch);
	int n = atoi(ch);
	initialize();
	for(int i = 0; i < n; i++){
	gets(str);
	insert(str,i);
	}
	printf("%d \n",min);
	return 0;
}

