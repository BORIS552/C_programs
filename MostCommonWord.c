#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define SIZE 100
int max = 0;
int pos;
struct DataItem {
	char key[20];
	int count;
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


void insert(char key[]) {

	//item->count = count;
	long long hashIndex = hashCodeIndex(key);
	//printf("%d\n",hashIndex );
	//checkIndex(hashIndex);

	while( hashIndex > 100) {
		hashIndex %= SIZE;
		//printf("%d:index in while\n",hashIndex);
	}
	//printf("%dindexOutofWhile\n", hashIndex);
	//printf("\n %d \n",SIZE);

	
	if(hashArray[hashIndex] == NULL)
		{

		item = (struct DataItem*)malloc(sizeof(struct DataItem));
		strncpy(item->key,key,strlen(key));
		hashArray[hashIndex] = item;
		item->count = 1;
		}
		else{
			hashArray[hashIndex]->count = hashArray[hashIndex]->count + 1;
		} 
	
}

void createHashTable(char str[]) {
	char splitStrings[20][20]; 
    int i,j,cnt;
    j=0; cnt=0;
    for(i=0;i<=(strlen(str));i++)
    {
       
        if(str[i]==' '||str[i]=='\0')
        {
            splitStrings[cnt][j]='\0';
            cnt++;  
            j=0;   
        }
        else
        {
            splitStrings[cnt][j]=str[i];
            j++;
        }
    }

    for(int k = 0; k < cnt; k++ ) {
    	//printf("%s\n",splitStrings[k]);
    	insert(splitStrings[k]);
    }

}


void findMax(char str[]) {
   int i = 0;
   createHashTable(str);
	
   for(i = 0; i<SIZE; i++) {
	
      if(hashArray[i] != NULL){
         //printf(" (%s,%d)",hashArray[i]->key,hashArray[i]->count);
         if(max < hashArray[i]->count){
         	max = hashArray[i]->count;
         	pos = i;
         }
      }
         //printf(" ~~ ");
   }
	
   //printf("\n");
}



int main() {
	char str[100];
	initialize();
	gets(str);
	findMax(str);
	//printf("\nCount:%d %d: %s\n",max,pos,hashArray[pos]->key);
	printf("%s \n",hashArray[pos]->key);
	return 0;
}

