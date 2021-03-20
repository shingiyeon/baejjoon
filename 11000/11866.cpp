#include <stdio.h>
#include <queue>
using namespace std;
int main(){
	queue<int> q;
	int N, M; scanf("%d%d",&N,&M);
	for(int i=1; i<=N; i++)
		q.push(i);
	printf("<");
	while(!q.empty()){
		for(int i=0; i<M-1; i++){
			q.push(q.front());
			q.pop();
		}
		if(q.size()!=1)
			printf("%d, ",q.front());
		else
			printf("%d>", q.front());
		q.pop();
	}
}
