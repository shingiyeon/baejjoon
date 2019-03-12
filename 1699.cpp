#include <stdio.h>
int dy[100001];
int main(){
	for(int i=1; i<=100000; i++)
		dy[i] = 100001;
	for(int i=1; i*i<=100000; i++)
		dy[i*i] = 1;
	for(int i=1; i<=100000; i++){
		for(int j=1; j*j<=i; j++){
			int tmp = dy[j*j] + dy[i-(j*j)];
			if(tmp<dy[i]) dy[i] = tmp;
		}
	}
	int temp;
	scanf("%d",&temp);
	printf("%d",dy[temp]);
		
}
