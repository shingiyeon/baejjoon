#include <stdio.h>
int main(){
	int testcase; scanf("%d",&testcase);
	while(testcase--){
		int N; char str[21]; scanf("%d",&N); scanf("%s",str);
		for(int i=0; str[i]!='\0'; i++){
			for(int j=0; j<N; j++) printf("%c",str[i]);
		}
		printf("\n");
	}
}
