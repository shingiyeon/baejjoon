#include <stdio.h>

int main(){
	int N; scanf("%d", &N);
	int j;
	int x;
	for(j=2; j<=N-2; j++){
		x = N % j;
		if(x==0){
			printf("�Ҽ��� �ƴմϴ�\n");
			break;
		}
	}
	if(x>=1)
		printf("�Ҽ��Դϴ�.\n");
}
