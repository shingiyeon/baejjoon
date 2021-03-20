#include <stdio.h>
int main(){
	int T; scanf("%d", &T);
	while(T--){
		int a = 0, b = 0;
		int t; scanf("%d", &t);
		while(t--){
			char A, B; scanf(" %c %c",&A,&B);
			if(A==B) continue;
			if(A=='R'){
				if(B=='P') b++;
				else a++; 
			}
			if(A=='P'){
				if(B=='S') b++;
				else a++; 
			}
			if(A=='S'){
				if(B=='R') b++;
				else a++; 
			}
		}
		if(a==b) printf("TIE\n");
		else{
			printf("Player %d", a>b? 1:2);
		}
	}
}
