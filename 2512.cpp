#include <stdio.h>
int M;
int arr[10000];
int N;
int MAX = 0;
int maxv = 0;
int min(int a, int b){return a < b? a : b;}
int max(int a, int b){return a > b? a : b;}

void search(int s, int e){
	int mid = (s+e)/2;
	if(s>e) return;		
	int sum = 0;
	for(int i=0; i<N; i++)	
		sum += min(arr[i], mid);
	if(sum<=M){
		MAX = max(MAX, mid);
		search(mid+1, e);
	}
	else
		search(s, mid-1);
	return;
}
int main(){
	scanf("%d", &N);
	for(int i=0; i<N; i++) {scanf("%d", &arr[i]); maxv = max(maxv, arr[i]);}
	scanf("%d", &M);
	search(0, 1000000000);
	printf("%d", MAX > maxv? maxv : MAX);
}
