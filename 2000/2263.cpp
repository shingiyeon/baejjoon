#include <stdio.h>
int N;
int inorder[100001];
int postorder[100001];

void print(int il, int ir, int pl, int pr){
	
	if(pl==pr||il==ir){
		printf("%d ", postorder[pl]);
		return;
	}
	else if(pl>pr || il>ir) return;
	printf("%d ", postorder[pr]);
	int i = il;
	for(i=il;i<=ir;i++)
		if(postorder[pr] == inorder[i]) break;
	 print(il , i-1, pl, pl+i-il-1);
	 print(i+1, ir, pr-ir+i, pr-1);
	 return;
}

int main(){
	scanf("%d", &N);
	for(int i=0; i<N; i++) scanf("%d", &inorder[i]);
	for(int i=0; i<N; i++) scanf("%d", &postorder[i]);
	print(0,N-1,0,N-1);
	
}
