#include <stdio.h>

int dy[100001][2];
int arr[100001];
int max(int a, int b){return a > b? a:b;}
int main(){
	int MAX = -100000000;
	int N; scanf("%d", &N);
	for(int i=0; i<N; i++) scanf("%d", &arr[i]);
	dy[0][0] = arr[0];
	dy[0][1] = 0;
	for(int i=1; i<N; i++){
		dy[i][0] = max(dy[i-1][0]+arr[i], arr[i]);
		dy[i][1] = max(dy[i-1][0], dy[i-1][1]+arr[i]);
		MAX = max(MAX, dy[i][0]);
		MAX = max(MAX, dy[i][1]);
	}
	printf("%d", MAX);

}
