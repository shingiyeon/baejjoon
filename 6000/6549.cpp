#include <stdio.h>
#include <vector>
#define MAX 1000000000
using namespace std;

int min(int a, int b){
	return a < b? a : b;
}
int min2(int a, int b, int c, int d){
	return a < b? c : d;
}

int a[100001];
int tree[262144][2];

int init(int node, int start, int end){
	if (start == end) {
		tree[node][1] = start;
		return tree[node][0] = a[start];
	}
	else{
		int L = init(node*2, start, (start+end)/2);
		int R = init(node*2+1, (start+end)/2+1, end);
		if(L<R){
			tree[node][1] = tree[node*2][1];
			return tree[node][0] = L;
		}
		else{
			tree[node][1] = tree[node*2+1][1];
			return tree[node][0] = R;
		}
	}	
}

int mintree(int node, int start, int end, int left, int right){
	if(left > end || right < start) return MAX;
	if(left<=start && end <= right) return tree[node][0];
	return min( mintree(node*2, start, (start+end)/2, left, right), mintree(node*2+1, (start+end)/2+1, end, left, right));
}
int min2tree(int node, int start, int end, int left, int right){
//	printf("min2tree node: %d, start %d, end: %d, left: %d, right: %d\n", node, start, end, left, right);
//	getchar();
	if(left<=start && end<=right) return tree[node][1];
	if( mintree(node*2, start, (start+end)/2, left, right) > mintree(node*2+1, (start+end)/2+1, end, left, right) )
		return min2tree(node*2+1, (start+end)/2+1, end, left, right);
	else
		return min2tree(node*2, start, (start+end)/2, left, right);
}


int search_maxarea(int node, int start, int end, int left, int right){
//	printf("node: %d, start: %d, end: %d, left: %d, right: %d\n", node, start, end, left, right);
//	getchar();
	if(left > right) return 0;
	else if(left == right) return a[left];
	int max = (right-left+1) * mintree(1, start, end, left, right);
	int maxv = node;
//	printf("max:%d maxv: %d\n", max, maxv);
	if (maxv == left) { int temp = search_maxarea(min2tree(1, start,end,left+1, right), start, end, left+1, right); max = temp > max ? temp : max;}
	else if(maxv == right) { int temp = search_maxarea(min2tree(1, start,end,left, right-1),start, end, left, right-1); max = temp > max ? temp : max;}
	else{
		//printf("LEFT\n");
		int temp = search_maxarea(min2tree(1, start,end,left, maxv-1), start, end, left, maxv-1);
		//printf("area: %d\n", temp);
		max = temp > max ? temp : max;
		//printf("RIGHT\n");
		temp = search_maxarea(min2tree(1, start,end, maxv+1, right), start, end, maxv+1, right);
		max = temp > max? temp : max;
	}
	return max;
}

int main(){
	int N;
	while(1){
		scanf("%d", &N);
		if(!N) return 0;
		for(int i=1; i<=N; i++) scanf("%d", &a[i]);
		init(1, 1, N);
		for(int i=1; i<=20; i++){
	//		printf("i: %d tree[i][0]: %d tree[i][1]: %d\n ",i, tree[i][0],tree[i][1]);
		}
		printf("%d\n", search_maxarea(tree[1][1], 1, N, 1, N));
	}	
}
