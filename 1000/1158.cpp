//# Author : nuclear852 ========================#
//# Solution : 11497888 ========================#
//# Time Stamp : 2019-01-24 00:02:49 ===========#
//# Problem Title : 요세푸스 문제 ================#
//# Language : C++98 ===========================#

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