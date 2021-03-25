//# Author : nuclear852 ========================#
//# Solution : 15465789 ========================#
//# Time Stamp : 2019-10-02 23:07:39 ===========#
//# Problem Title : 학교 가지마! ================#
//# Language : C++14 ===========================#

#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
#include <map>
using namespace std;

char cmap[105][105];
int nmap[105][105];

vector<int> adj[20005];
map< pair<int, int>, int > c;
map< pair<int, int>, int > f;

bool pos[20005];


int dx[4] = {-1, 0, 0 , 1};
int dy[4] = {0, -1, 1, 0};
int sx, sy, sn;
int ex, ey, en;
int N, M;
int S , E;
int idx = 1;

short lv[20005];

void bfs(){
	queue<int> q;
	for(int i=2; i<idx*2; i++) lv[i] = -5;
	lv[S] = 0;
	q.push(S);
	
	while(!q.empty()){
		int x = q.front(); q.pop();
		for(auto p : adj[x]){
			if(lv[p] == -5 && c[make_pair(x,p)] > f[make_pair(x,p)]){
				lv[p] = lv[x] + 1;
				q.push(p);
			}
		}
		
	}
}

int dfs(int p, int mn){
	if(p == E) return mn;
	if(!pos[p]) return pos[p];
	
	int flow = 0;
	for(auto x : adj[p]){
		if(lv[x] == lv[p]+1 && c[make_pair(p,x)] > f[make_pair(p,x)]){
			flow = dfs(x, min(mn, c[make_pair(p,x)] - f[make_pair(p,x)]) );
			if(flow){
				f[make_pair(p,x)] += flow;
				f[make_pair(x,p)] -= flow;
				return flow;
			}
		}
	}
	
	return pos[p] = 0;
}

int main(){
	scanf("%d%d", &N, &M);
	for(int i=0; i<N; i++) scanf("%s", cmap[i]);
	
	
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			if(cmap[i][j] == '.') nmap[i][j] = idx++;
			else if(cmap[i][j] == 'K') {
				sn = idx;
				sx = i; sy = j;
				nmap[i][j] = idx++;
			}
			else if(cmap[i][j] == 'H') {
				en = idx;
				ex = i; ey = j;
				nmap[i][j] = idx++;
			}
		}
	}
	
	//Check case -1
	if(M==1 && N==1){
		printf("-1");
		return 0;
	}
	if(sn==0 || en==0){
		printf("-1");
		return 0;
	}
	
	for(int i = 0; i < 4; i++){
		if(sx + dx[i] < 0 || sx + dx[i] >= N ) continue;
		if(sy + dy[i] < 0 || sy + dy[i] >= M ) continue;
		if(sx + dx[i] == ex && sy + dy[i] == ey){
			printf("-1");
			return 0;
		}
	}
	
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++) {
			if(cmap[i][j] == '#') continue;
			for(int k=0; k<4; k++) {
				int cx = i + dx[k];
				int cy = j + dy[k];
				if(cx < 0 || cx >= N || cy < 0 || cy >= M) continue;
				if(cmap[cx][cy] == '#') continue;
				
				c[make_pair(nmap[i][j]*2 + 1, nmap[cx][cy] * 2)] = 987654321;
				c[make_pair(nmap[cx][cy] * 2, nmap[i][j]*2 + 1)] = 0;
				c[make_pair(nmap[cx][cy] * 2 + 1, nmap[i][j] * 2)] = 987654321;
				c[make_pair(nmap[i][j] * 2, nmap[cx][cy] * 2 + 1)] = 0;
				adj[nmap[i][j]*2 + 1].push_back(nmap[cx][cy] * 2);
				adj[nmap[cx][cy]*2].push_back(nmap[i][j] * 2 + 1);
				adj[nmap[cx][cy] * 2 + 1].push_back(nmap[i][j] * 2);
				adj[nmap[i][j] * 2].push_back(nmap[cx][cy] * 2 + 1);
				
			}
		}
	}
	
	S = sn*2+1, E = en*2;
	for(int i=1; i<idx; i++){
		c[make_pair(i*2, i*2+1)] = 1;
		c[make_pair(i*2+1, i*2)] = 0;
		adj[2*i].push_back(2*i+1);
		adj[2*i+1].push_back(2*i);
	}
	
	int ans = 0;
	while(1){
		bfs();
		for(int i=2; i<idx*2; i++) pos[i] = 1;
		bool flow = dfs(S, 1);
		if(!flow) break;
		ans += (int)flow;
	}
	printf("%d", ans);
}