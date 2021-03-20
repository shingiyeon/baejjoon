#include <stdio.h>
#include <algorithm>
using namespace std;

int arr[51];
int sortedarr[51];
bool visited[51];
int main(){
	int N;
	scanf("%d",&N);
	for(int i=0; i<N; i++){
		scanf("%d", &arr[i]);
		sortedarr[i] = arr[i];
	}
	sort(sortedarr, sortedarr+N);
	for(int i=0; i<N; i++)
		printf("%d ", sortedarr[i]);
	printf("\n");
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			if( (!visited[j])&& (sortedarr[j] == arr[i]) ){
				printf("%d ", j);
				visited[j] = 1;
				break; 
			}
		}	
	}
}
