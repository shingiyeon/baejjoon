#include <stdio.h>
int main(){
	char word[101];
	scanf("%s", word);
	printf("%s", word);
}
/*
      i  0 1 2 3 4 5 6 7 8  9 10 ... 100
word[i]  b a e k j o o n \0

       i 0  1   2   3   4 ........... 25
alpha[i] 1  0  -1   -1  2 


word[1]-'a'





word[8] == '\0'
8 --> 단어의 길이 
*/
