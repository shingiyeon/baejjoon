//# Author : nuclear852 ========================#
//# Solution : 21276780 ========================#
//# Time Stamp : 2020-07-27 23:09:56 ===========#
//# Problem Title : 집합의 표현 =================#
//# Language : C++14 ===========================#

#include <iostream>
#include <stdio.h>
using namespace std;
int n, m;
int p[1000001];
int rn[1000001];

int parent(int x)
{
	if (p[x] == x){
		return p[x];
	}
	return p[x] = parent(p[x]);
}

bool equalParent(int a, int b){
	return parent(a) == parent(b);
}

void addTree(int a, int b) {
	int pA = parent(a);
	int pB = parent(b);
	if (pA == pB) {
		return;
	}
	
	if (rn[pA] >= rn[pB]) {
		p[pB] = pA;
		rn[pA] += rn[pB];
	}
	else {
		p[pA] = pB;
		rn[pB] += rn[pA];
	}
}


int main() {
	int a, x, y;
	scanf("%d%d", &n, &m);
	for(int i=0; i<=n; i++) {
		rn[i] = 1;
		p[i] = i;
	}
	
	while(m--) {
		scanf("%d%d%d", &a, &x, &y);
		if(a) {
			printf("%s", equalParent(x,y) ? "YES\n" : "NO\n");
		}
		else {
			addTree(x, y);
		}
	}
	
	return 0;
}