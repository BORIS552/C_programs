#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define SIZE 100

struct DataItem
{
	char anagram[10][10];
	int index;
};

struct DataItem* hashArray[SIZE];
struct DataItem* item = NULL;

void initialize() {
	for(int i = 0; i < SIZE ;i++)
		hashArray[i] = NULL;
}


long long  hashCodeIndex(char str[]) {

	long long index = 0LL;
	int prime = 3;
	int len = strlen(str);
	for(int i = 0; i <len; i++){
		index = index + ((int)str[i]*pow(31,len-1)) ;
	}
	return index;
}


void insert(char key[]) {

	long long hashIndex = hashCodeIndex(key);
	int index;
	while( hashIndex > 100) {
		hashIndex %= SIZE;
	}

	
	if(hashArray[hashIndex] == NULL)
		{
		 //code for NULL case
			item = (struct DataItem*)malloc(sizeof(struct DataItem));
			hashArray[hashIndex] = item;
			hashArray[hashIndex]->index = 0;
			strncpy(hashArray[hashIndex]->anagram[0],key,strlen(key));
			hashArray[hashIndex]->index = 1;

		}
		else{
			//code for not NULL case
			index = hashArray[hashIndex]->index;
			strncpy(hashArray[hashIndex]->anagram[index],key,strlen(key));
			hashArray[hashIndex]->index = ++index;

		} 
	
}


void sort(int index,int n) {
	char temp[8];
	int i,j;
    for (i = 0; i < n - 1 ; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (strcmp(hashArray[index]->anagram[i], hashArray[index]->anagram[j]) > 0)
            {
                strncpy(temp, hashArray[index]->anagram[i],strlen(hashArray[index]->anagram[i]));
                strncpy(hashArray[index]->anagram[i], hashArray[index]->anagram[j],strlen(hashArray[index]->anagram[j]));
                strncpy(hashArray[index]->anagram[j], temp,strlen(temp));
            }
        }
    }

     for (i = 0; i < n; i++)
    {
        printf("%s ", hashArray[index]->anagram[i]);
    }

}



void getAnagrams() {
	int max = 0,pos = 0;
	int anagramUnsorted[10][10];
	for(int i = 0; i < SIZE; i++) {
		if(hashArray[i] == NULL)
			continue;
		if(max < hashArray[i]->index){
			max = hashArray[i]->index;
			pos = i;
		}
		//printf("index size: %d\n",hashArray[i]->index);
	}

	/*
	for(int j = 0; j < max;j++)
		printf("%s ",hashArray[pos]->anagram[j] );
		*/
	sort(pos,max);
}


int main() {
	char ch[2];
	char words[10];
	gets(ch);
	int n = atoi(ch);
	initialize();
	for(int i = 0; i < n;i++ ) {
		gets(words);
		insert(words);
	}
	getAnagrams();
	return 0;
}