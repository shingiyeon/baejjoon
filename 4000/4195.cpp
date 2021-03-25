//# Author : nuclear852 ========================#
//# Solution : 23897425 ========================#
//# Time Stamp : 2020-11-17 10:44:09 ===========#
//# Problem Title : 친구 네트워크 ================#
//# Language : C++14 ===========================#

#include <stdio.h>
#include <iostream>
#include <string>
#include <map>

using namespace std;

int size[200001];
int p[200001];

int parent(int x) {
	if(p[x] == x) {
		return x;
	}
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
	int T; int F;
	scanf("%d", &T);
	while(T--) {
		map<string, int> m;
		string a(100, '\0'), b(100, '\0');
		int aKey, bKey;
		for(int i=0; i<=200000; i++) {
			p[i] = i;
			size[i] = 1;
		}
		scanf("%d", &F); 
		int idx = 1;
		for(int i=0; i<F; i++) {
			scanf("%s%s",a.c_str(), b.c_str());
			if(m[a] != 0) {
				aKey = m[a];
			}
			else {
				m[a] = idx++;
				aKey = m[a];
			}
			if(m[b] != 0) {
				bKey = m[b];
			}
			else {
				m[b] = idx++;
				bKey = m[b];
			}
			addTree(aKey, bKey);
			printf("%d\n", size[parent(aKey)]);
		}
		
	}
}