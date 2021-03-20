#include <stdio.h>
int arr[50];
int min(int a, int b){
	return a < b? a : b;
}
void swap(int i, int j){
	int temp = arr[j];
	for(int k = j-1; k >=i; k--){
		arr[k+1] = arr[k];
	}
	arr[i] = temp;
}

int main(){
	int S; int N;
	scanf("%d",&N);
	for(int i=0; i<N; i++) scanf("%d",&arr[i]);
	scanf("%d",&S);
	
	for(int i=0; i<N; i++){
		int index = i; int max_value = arr[i];
		for(int j=i+1; j<=min(S+i,N-1); j++){
			if(max_value < arr[j]){
				index = j;
				max_value = arr[j];
			}
		}
		//printf("index max_value %d %d\n", index, max_value);
		if(index != i){
			swap(i, index);
			S = S - (index-i);
		}
		//for(int j=0; j<N; j++) printf("%d ", arr[j]);
		//printf("\nS %d\n\n", S);
	}
	
	for(int i=0; i<N; i++){
		printf("%d ", arr[i]);
	}
}
