#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 256
struct DataItem {
	char ch;
	int count;
};

struct DataItem* hashArray[SIZE];
struct DataItem* item;

int hashCode(int key) {
	return (key % SIZE);
}

void insert(char ch){


	int hashIndex = hashCode((int)ch);
	if(hashArray[hashIndex] == NULL)
	{
		item = (struct DataItem*)malloc(sizeof(struct DataItem));
		hashArray[hashIndex] = item;
		item->count = 1;

	}else {
		hashArray[hashIndex]->count = hashArray[hashIndex]->count + 1;
	}

}

int ifCharsAvailable(char ch) {
	int hashIndex = hashCode((int)ch);
	if(hashArray[hashIndex]->count == 0){
		return 0;
	}
	else {
		hashArray[hashIndex]->count = hashArray[hashIndex]->count - 1;
		return 1;
	}
	return 0;
}

int isLetterPossible(char letter[], char magazine[]) {

	int i,flag = 0;

	for(i = 0; i < strlen(magazine); i++){
		insert(magazine[i]);
	}

	for(i = 0; i < strlen(letter); i++) {
		flag = ifCharsAvailable(letter[i]);
		if(flag == 0)
			return 0;
	}
return flag;		
}

void initialise() {
	for(int i = 0; i < SIZE; i++)
		hashArray[i] = NULL;
}

int main() {
	char letter[200];
	char magazine[200];
	int flag = 0;
	gets(letter);
	gets(magazine);
	initialise();
	flag = isLetterPossible(letter,magazine);
	if(flag == 1)
		printf("true");
	else
		printf("false");
	return 0;
}