//# Author : nuclear852 ========================#
//# Solution : 21874739 ========================#
//# Time Stamp : 2020-08-19 22:43:55 ===========#
//# Problem Title : 공항 =====================#
//# Language : C++14 ===========================#

#include <stdio.h>

using namespace std;
int G, P;
int arr[100001];
int p[100001];

int parent(int x) {
	if(p[x] == x) {
		return x;
	}
	return p[x] = parent(p[x]);
}

void addTree(int x, int y) {
	int pX = parent(x);
	int pY = parent(y);
	if (pX < pY) {
		p[pY] = pX;
	}
	else {
		p[pX] = pY;
	}
}

int main() {
	scanf("%d%d",&G,&P);
	int ap;
	int ans = 0;
	for(int i=0; i<= 100000; i++) {
		p[i] = i;
	}
	for(int i=1; i<=P; i++) {
		scanf("%d", &ap);
		if(parent(ap) == 0) {
			break;
		}
		addTree(p[ap], p[ap]-1);
		ans++;
	}
	printf("%d", ans);
}