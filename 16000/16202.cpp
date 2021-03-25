//# Author : nuclear852 ========================#
//# Solution : 21966978 ========================#
//# Time Stamp : 2020-08-23 22:54:32 ===========#
//# Problem Title : MST 게임 =================#
//# Language : C++14 ===========================#

#include <stdio.h>
#include <utility>
#include <algorithm>
using namespace std;

pair<int, int> edge[100001];


int N, M, K;

int p[10001];
int size[10001];

int parent(int x){
	if(p[x] == x) {
		return x;
	}
	return p[x] = parent(p[x]);
}

void addTree(int x, int y){
	int px = parent(x);
	int py = parent(y);
	if(px == py) return;
	if(size[px] >= size[py]) {
		p[py] = px;
		size[px] += size[py];
	}
	else {
		p[px] = py;
		size[py] += size[px];
	}
}



int main() {
	scanf("%d%d%d", &N,&M,&K);
	for(int i=1; i<=M; i++) {
		scanf("%d%d", &edge[i].first, &edge[i].second);
	}
	
	for(int j=0; j<K; j++) {
		for(int i=0; i<=M; i++) {
			p[i] = i;
			size[i] = 1;
		}
		int cost = 0;
		int edgeCnt = 0;
		for(int i=j+1; i<=M; i++) {
			if( parent(edge[i].first) != parent(edge[i].second)) {
				cost += i;
				addTree(edge[i].first, edge[i].second);
				edgeCnt++;
			}
			
			if(edgeCnt == N-1) {
				break;
			}
		}
		if(edgeCnt!=N-1) {
			for(int k=j; k<K; k++) {
				printf("0 ");
			}
			break;
		}
		
		printf("%d ", cost);
	
	}
}