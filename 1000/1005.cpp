#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;
int dp[1001];
vector<int> build[1001];
int time[1001];

int dy(int pos){
	if (dp[pos] != -1)
		return dp[pos];
	if (build[pos].size() == 0)
		return dp[pos] = time[pos];
	int temp = 0;
	for(int i=0; i<build[pos].size(); i++){
		temp = temp > dy(build[pos][i]) + time[pos] ? temp : dp[build[pos][i]] + time[pos];
	}
	return dp[pos] = temp;
}

int main(){
	int testcase; scanf("%d",&testcase);
	while(testcase--){
		int a,b;
		memset(dp, -1, sizeof(dp));
		for(int i=0;i<1001;i++) build[i].clear();
		memset(time, 0, sizeof(time));
		int N, K; scanf("%d%d",&N,&K);
		for(int i=1;i<=N;i++) scanf("%d",&time[i]);
		while(K--){scanf("%d%d",&a,&b);build[b].push_back(a);}
		int W; scanf("%d",&W);
		printf("%d\n",dy(W));
	}
}
