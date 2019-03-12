#include <stdio.h>
int main(){
	int T; scanf("%d",&T);
	while(T--){
		char temp[81]; scanf("%s",temp);
		int num = 1;
		int sum = 0;
		for(int i=0; temp[i]!='\0'; i++){
			temp[i]=='O'? sum+=num++ : num=1;
		}
		printf("%d\n",sum);
	}
}
