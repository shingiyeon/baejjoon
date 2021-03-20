#include <stdio.h>
int main(){
	char name[5][11];
	int strlen[5];
	for(int i=0; i<5; i++) 	scanf("%s", name[i]);
	int sum = 0;
	for(int i=0; i<5; i++){
		int num = 0;
		for(int j=0; name[i][j] != '\0'; j++){
			if(name[i][j] == 'F') num = 1;
			else if(name[i][j] == 'B' && num == 1) num = 2;
			else if(name[i][j] == 'I' && num == 2){
				printf("%d ", i+1); sum++; break;
			} 
			else num = 0;
		}
	}
	if(!sum) printf("HE GOT AWAY!");
}
