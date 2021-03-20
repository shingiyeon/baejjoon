#include <stdio.h>
#include <vector>
using namespace std;
vector<int> v(9,0);
int visited[9];
int N;
void permutation(int n){
	if(n>N){
		for(int i=1; i<=N; i++) printf("%d ", v[i]);
		printf("\n");
		return;
	}
	
	for(int i=1; i<=N; i++){
		if(visited[i]==0){
			visited[i] = 1;
			v[n] = i;
			permutation(n+1);
			visited[i] = 0;
		}
	}
}
int main(){
	scanf("%d" ,&N);
	permutation(1);
}
