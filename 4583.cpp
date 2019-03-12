#include <stdio.h>
int pos[26] = {0, 'd', 0, 'b', 0, 0, 0, 0, 'i', 0, 0, 'l', 'm', 'n', 'o', 'q', 'p', 0, 0, 't', 'u', 'v', 'w', 'x', 0, 0};

int main(){
	char word[11];
	scanf("%s", word);
	while(word[0] !='#'){
		int strlen;
		for(strlen=0; word[strlen]!='\0'; strlen++);
		int check = 1;
		for(int i=0; i<strlen; i++){
			check *= pos[word[i]-'a'];
		}
		if(check){
			for(int i=0; i<strlen; i++){
				printf("%c", pos[word[strlen-1-i]-'a']);
			}
		}
		else
			printf("INVALID");
		printf("\n");
		scanf("%s", word);
	}
}
