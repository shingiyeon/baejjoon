//# Author : nuclear852 ========================#
//# Solution : 15036661 ========================#
//# Time Stamp : 2019-09-08 17:01:10 ===========#
//# Problem Title : 사전 =====================#
//# Language : C++98 ===========================#

#include <stdio.h>
#include <vector>

using namespace std;

int dp[201][201];
vector<int> v;

int combi(int a, int b){
	if(b<=-1) return 0;
	if(dp[a][b] != -1) return dp[a][b];
	if(b==0) return dp[a][b] = 1;
	if(a==b) return dp[a][b] = 1;
	return dp[a][b] = (combi(a-1, b-1) + combi(a-1, b) > 1e9 ? 1e9 : combi(a-1, b-1) + combi(a-1, b)); 
}

int main(){
	int N, M, K;
	scanf("%d%d%d", &N,&M,&K);
	int sum = N+M;
	for(int i=0; i<=200; i++){
		for(int j=0; j<=200; j++){
			dp[i][j] = -1;
		}
	}
	
	if(K > combi(M+N, N)){
		printf("-1");
		return 0;
	}
	
	while(K != 0){
		if(N==0 || M==0){
			break;
		}
		else if(K <= combi(N+M-1, N-1)){
			v.push_back(0);
			N--;
		}
		else{
			v.push_back(1);
			K -= combi(N+M-1, N-1);
			M--;
		}
	}
	
	for(int i=0; i<M; i++) v.push_back(1);
	for(int i=0; i<N; i++) v.push_back(0);
	
	for(int i=0; i<v.size(); i++)
		printf("%c", 'a'+('z'-'a')*v[i]);
}