//# Author : nuclear852 ========================#
//# Solution : 21847346 ========================#
//# Time Stamp : 2020-08-18 22:21:19 ===========#
//# Problem Title : 여행 가자 ==================#
//# Language : C++14 ===========================#

#include <stdio.h>
using namespace std;
int size[205];
int p[205];
int city[1000];

int parent(int x) {
	if (p[x] == x) return p[x];
	return p[x] = parent(p[x]);
}

bool hasSameParent(int a, int b){
	return parent(a) == parent(b);
}

void addTree(int a, int b) {
	int pA = parent(a);
	int pB = parent(b);
	if (pA == pB) return;
	if (size[pA] >= size[pB]) {
		p[pB] = pA;
		size[pA] += size[pB];
	}
	else {
		p[pA] = pB;
		size[pB] += size[pA];
	}
}

int main() {
	int N, M;
	int c;
	scanf("%d%d",&N,&M);
	for(int i=1; i<=N; i++) {
		p[i] = i;
		size[i] = 1;
	}
	for(int i=1; i<=N; i++) {
		for(int j=1; j<=N; j++) {
			scanf("%d", &c);
			if(c) {
				addTree(i, j);
			}
		}
	}
	for(int i=0; i<M; i++) {
		scanf("%d", &city[i]);
	}
	bool flag = true;
	for(int i=1; i<M; i++) {
		if(!hasSameParent(city[0], city[i])) {
			flag = false;
			break;
		}
	}
	if(flag)
		printf("YES");
	else
		printf("NO");
}