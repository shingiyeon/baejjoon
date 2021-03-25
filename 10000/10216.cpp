//# Author : nuclear852 ========================#
//# Solution : 21902614 ========================#
//# Time Stamp : 2020-08-20 23:27:57 ===========#
//# Problem Title : Count Circle Groups ====#
//# Language : C++14 ===========================#

#include <stdio.h>
using namespace std;
int p[3001];
int size[3001];
 
int x[3001];
int y[3001];
int R[3001];
bool flag[3001];
 
bool sameRange(int x1, int y1, int R1, int x2, int y2, int R2) {
	return (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1) <= (R1 + R2) * (R1 + R2);
}
 
int parent(int x) {
	if(p[x] == x) {
		return x;
	}
	return p[x] = parent(p[x]);
}
 
bool hasSameParent(int x, int y) {
	return parent(x) == parent(y);
}
 
void addTree(int x, int y){
	int pA = parent(x);
	int pB = parent(y);
	if (hasSameParent(x, y)) {
		return;
	}
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
	int T; scanf("%d", &T);
	while(T--) {
		int ans = 0;
		int N; scanf("%d", &N);
		for(int i=0; i<=3000; i++) {
			p[i] = i;
			size[i] = 1;
			flag[i] = 0;
		}
		for(int i=0; i<N; i++) {
			scanf("%d%d%d", &x[i], &y[i], &R[i]);
		}
 
		for(int i=0; i<N-1; i++) {
			for(int j=i+1; j<N; j++ ) {
				if(i==j) continue;
				if(hasSameParent(i, j)) continue;
				if(sameRange(x[i], y[i], R[i], x[j], y[j], R[j])) {
					addTree(i, j);
				}
			}
		}
 
		for(int i=0; i<N; i++) {
			flag[parent(i)] = 1;
		}
		for(int i=0; i<N; i++) {
			if(flag[i]) ans++;
		}
		printf("%d\n", ans);
 
	}
}