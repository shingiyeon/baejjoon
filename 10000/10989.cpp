#include <stdio.h>
int arr[10001];
int main(){
	int N; scanf("%d",&N);
	while(N--){
		int temp;
		scanf("%d", &temp);
		arr[temp]++;
	}
	for(int i=1; i<=10000; i++){
		for(int j=1; j<=arr[i]; j++){
			printf("%d\n",i);
		}
	}
}
