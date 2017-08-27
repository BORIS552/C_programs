#include <stdio.h>
#include <stdlib.h>

int main() {
char sentence[70];
char words[3][25];
int a = 0;
int i = 0;
int index = 0;
gets(sentence);
while (sentence[a] != '\0') 
{
      if (sentence[a] == ' ') 
      { words[index][i] = '\0'; 
  		i=0;
  		a++; 
  		index++; 
      } // SPACE detected
 
      words[index][i++] = sentence[a++];
}
      words[index][i] = '\0';

	return 0;
}
