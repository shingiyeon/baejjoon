#include <stdio.h>
#include <queue>
#include <vector>
#include <utility>
using namespace std;
int p[52];

int c[52][52];
int f[52][52];

int convert(char ch){
	if('a'<=ch && ch<='z')
		return 26+ch-'a';
	return ch-'A';
}
int min(int a, int b){return a<b?a:b;}
int edmond_karp(int source, int sink){
	int flow = 0;
	while(1){
		for(int i=0; i<52; i++) p[i] = -1;
		queue<int> q;
		q.push(source);
		p[source] = source;
		while(!q.empty() && p[sink] == -1){
			int s = q.front(); q.pop();
			for(int e = 0; e < 52; e++){
				if(c[s][e] - f[s][e] > 0 && p[e] == -1){
					p[e] = s;
					q.push(e);
				}
			}
		}
		if(p[sink] == -1) break;
		
		int minv = 1000000000;
		for(int i=sink; i!=source; i=p[i])
			minv = min(c[p[i]][i]-f[p[i]][i], minv);
		for(int i=sink; i!=source; i=p[i]){
			f[p[i]][i] += minv;
			f[i][p[i]] -= minv;
		}
		flow += minv;
	}
	return flow;
}

int main(){
	int N, t; char a, b;
	scanf("%d", &N);
	while(N--){
		scanf(" %c %c%d",&a,&b,&t);
		c[convert(a)][convert(b)] += t;
		c[convert(b)][convert(a)] += t;
	}
	printf("%d", edmond_karp(0, 25));
}
