#include <stdio.h>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;
short d[15000][1500];
char map[15000][1500];
int N, M;
int MAX = 0;
int max(int a, int b){return a>b?a:b;}

int calculate(int x){
	int temp_MAX = 0;
	vector<int> v;
	for(int i=0; i<M; i++){
		v.push_back(d[x][i]);
	}
	sort(v.begin(), v.end());
	int idx = 1;
	for(int i=v.size()-1; i>=0; i--){
		temp_MAX = max(temp_MAX, v[i]*idx++);
	}
	return temp_MAX;
}

int main(){
	scanf("%d%d", &N, &M);
	for(int i=0; i<N; i++){
		scanf("%s", map[i]);
	}
	for(int i=0; i<M; i++){
		for(int j=N-1; j>=0; j--){
			if(j==N-1) d[j][i] = map[j][i]-'0';
			else if(map[j][i] == '0') d[j][i] = 0;
			else d[j][i] = d[j+1][i] + 1;
		}
	}
	for(int i=0; i<N; i++){
		MAX = max(MAX, calculate(i));
	}
	printf("%d", MAX);
}
