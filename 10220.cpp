#include <stdio.h>
int main(){
	int T; scanf("%d", &T);
	while(T--){
		int N; scanf("%d", &N);
		if(N==0||N==1||N==2||N==3||N==6) printf("0\n");
		else if(N==4) printf("2\n");
		else printf("1\n");
	}
}
