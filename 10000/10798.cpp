#include <stdio.h>
int main(){
	char str[5][16];
	int strlen[5];
	for(int i=0; i<5; i++) scanf("%s", str[i]);
	
	for(int i=0; i<5; i++){
		int j;
		for(j=0; str[i][j]!='\0'; j++);
		strlen[i] = j;
	}
	for(int i=0; i<15; i++){
		for(int j=0; j<5; j++){
			if(i >= strlen[j]) continue;
			printf("%c", str[j][i]);
		}
	}
}
