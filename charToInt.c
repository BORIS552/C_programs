#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int frequency[26];

//hashFunction for generating index for particular character key.
int hashFunction(char ch)
{
	return ((int)ch % 26);
}
void countFrequency(char s[]) {
	for(int i = 0; i < strlen(s); ++i) {
		if(s[i] == ' ')
			continue;
		int index = hashFunction((char)s[i]);
		frequency[index]++;
	}
}

int displayFrequency(char ch) {
	int index = hashFunction(ch);
	return frequency[index];
}

int main() {
	char s[100];
	char ch;
	int count;
	gets(s);
	for(int i = 0; i < 26; i++)
		frequency[i] = 0;
	countFrequency(s);
	scanf("%c",&ch);
	count = displayFrequency(ch);
	printf("%d",count);
	return 0;
}