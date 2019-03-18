#include <stdio.h>
int rank[1000001];
int idx = -1;
int a(int c, int num){
	printf("%d %d\n", c, idx);
	if(c<0) return 0;
	
	int num = 1;
	for(int i=0; i<c; i++) num *= 10;
	for(int i=0; i<num; i++){
		int temp = i * num + a(c-1, i);
		rank[idx++] = temp;
		if(idx == 1000000) return 0;
	}
	return 0;
}
int main(){
	a(0);
	int N; scanf("%d", &N);
	printf("%d", rank[N]);
}
