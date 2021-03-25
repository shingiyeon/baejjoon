//# Author : nuclear852 ========================#
//# Solution : 15101704 ========================#
//# Time Stamp : 2019-09-12 16:46:03 ===========#
//# Problem Title : 교수님은 기다리지 않는다 ==========#
//# Language : C++14 ===========================#

#include <stdio.h>
#include <vector>
using namespace std;

int p[100001];
long long wp[100001];
int size[100001];
int N, M;

void initParent(){
	for(int i=1; i<=N; i++){
		p[i] = i;
		wp[i] = 0;
		size[i] = 1;
	}
	return;
}

pair<int, long long> find(int x, int dist){
	if(x == p[x]) return make_pair(x, dist);
	return find(p[x], dist + wp[x]);
}

void setParent(int a, int b, int c){
	auto x = find(a, 0);
	auto y = find(b, 0);
	if(x.first == y.first) return;
	
	if(size[x.first] > size[y.first]){
		wp[y.first] = x.second - y.second + c;
		p[y.first] = x.first;
		size[x.first] += size[y.first];
	}
	
	else{
		wp[x.first] = y.second - x.second - c;
		p[x.first] = y.first;
		size[y.first] += size[x.first];
	
	}
	return;
}

int main(){
	char c;
	int a, b;
	int w;
	scanf("%d %d", &N, &M);
	while(N!=0 && M!=0){
		initParent();
		for(int temp = 0; temp < M; temp++){
			scanf(" %c%d%d", &c, &a, &b);
			if(c=='!'){
				scanf("%d", &w);
				setParent(a, b, w);
			}
			else{
				auto aa = find(a, 0);
				auto bb = find(b, 0);
				if(aa.first == bb.first){
					printf("%lld\n", bb.second - aa.second);
				}
				else{
					printf("UNKNOWN\n");
				}
			}
		}
		scanf("%d %d", &N, &M);
	}
}