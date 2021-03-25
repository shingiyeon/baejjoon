//# Author : nuclear852 ========================#
//# Solution : 15087628 ========================#
//# Time Stamp : 2019-09-11 14:07:49 ===========#
//# Problem Title : 모노디지털 표현 ===============#
//# Language : C++14 ===========================#

#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int dp[32001];
vector<int> d[10];
int K;

int main(){
	scanf("%d", &K);
	d[1].push_back(K);
	int temp = K;
	for(int i=2; i<=8; i++){
		for(int j=1; j<i; j++){
			for(int k=i-j; k>0; k--){
				
				for(auto x : d[j]){
					for(auto y : d[k]){
						d[i].push_back(x+y);
						d[i].push_back(x-y);
						d[i].push_back(x*y);
						if(y) d[i].push_back(x/y);
					}
				}
				
				
			}
		}
		temp = temp*10 + K;
		d[i].push_back(temp);
		sort(d[i].begin(), d[i].end());
		d[i].erase(unique(d[i].begin(), d[i].end()), d[i].end());
	}
	
	for(int i=0; i<=32000; i++) dp[i] = -1;
	
	for(int i=1; i<=8; i++){
		for(int j=0; j<d[i].size(); j++){
			if(d[i][j] >= 1 && d[i][j] <= 32000){
				if( dp[d[i][j]] == -1) dp[ d[i][j] ] = i;
			}
		}
	}
	
	
	int N; scanf("%d", &N);
	
	while(N--){
		int num; scanf("%d", &num);
		if(dp[num]==-1) printf("NO\n");
		else printf("%d\n", dp[num]);
	}	
}