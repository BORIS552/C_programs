#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 10

typedef struct affinity {
	char page[10];
	int index;
	char *user[10];
};

typedef struct pair {
	char first[10];
	char second[10];
};

affinity *hashArray[SIZE];
affinity *item;


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
		index = index + ((int)str[i]*pow(31,len-1)) ;
	}
	return index;
}

void insert(char page[],char user[]) {
	long long hashIndex = hashCodeIndex(page);

	while( hashIndex > SIZE) {
		hashIndex %= SIZE;
	}

	
	if(hashArray[hashIndex] == NULL)
		{
			item = (affinity*)malloc(sizeof(affinity));
			strncpy(item->page,page,strlen(page));
			hashArray[hashIndex] = item;
			hashArray[hashIndex]->index = 0;
			strncpy(hashArray[hashIndex]->user[index],user,strlen(user));
			hashArray[hashIndex]->index = hashArray[hashIndex]->index+1;
		
		}
		else{
				strncpy(hashArray[hashIndex]->user[hashArray[hashIndex]->index],user,strlen(user));
				hashArray[hashIndex]->index = hashArray[hashIndex]->index+1;

		} 

}

void splitWords(char str[]) {
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

    	insert(splitStrings[0],splitStrings[1]);

}

/*
pair * getAffinityPair() {
	pair *node = NULL;
	char setA[50],setB[50],setC[50];
	for(int i = 0; i < SIZE; i++) {
		if(hashArray[i] == NULL)
			continue;
		hashArray[i]->
	}
	return node;
}
*/
void printData(){
	for(int i = 0;i<SIZE;i++) {
		printf("%s\n",hashArray[i]->page);
		for(int j = 0; j < hashArray[i]->index ; j++) 
			printf("%s\n",hashArray[i]->user[j]);
	}
}

void initialize() {
	for(int i = 0; i < SIZE ;i++)
		hashArray[i] = NULL;
}

int main() {
	char log[20];
	char ch[2];
	gets(ch);
	int n = atoi(ch);
	initialize();
	for(int i =0; i < n; i++) {
		gets(log);
		splitWords(log);
	}
	printData();
	return 0;
}
