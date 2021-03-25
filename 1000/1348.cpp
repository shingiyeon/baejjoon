//# Author : nuclear852 ========================#
//# Solution : 15268781 ========================#
//# Time Stamp : 2019-09-22 23:22:27 ===========#
//# Problem Title : 주차장 ====================#
//# Language : C++14 ===========================#

#include <stdio.h>
#include <queue>
#include <vector>
#include <utility>

using namespace std;

char map[51][51];
int imap[51][51];
bool visited[51][51];

int ans = -1;
int carN = 1;
int parkN = 1;
int A[2501], B[2501], lv[2501];
vector< pair<int, int> > adj[2501];
vector<int> t_adj[2501];

bool pos[2501];

int R, C;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = { 0, 0, -1, 1};


void bfs(){
	queue<int> q;
	for(int i=1; i<carN; i++){
		if(A[i] == -1){
			lv[i] = 0;
			q.push(i);
		}
		else {
			lv[i] = -5;
		}
	}	
	
	while(!q.empty()){
		int idx = q.front(); q.pop();
		
		for(auto x : t_adj[idx]){
			if(B[x] != -1 && lv[B[x]] == -5){
				lv[B[x]] = lv[idx] + 1;
				q.push(B[x]);
			}
		}
	}
}

int dfs(int n){
	if(!pos[n]) return pos[n];
	
	for(auto x : t_adj[n]){
		if(B[x] == -1 || (lv[B[x]] == lv[n] + 1 && dfs(B[x]))){
			A[n] = x;
			B[x] = n;
			return 1;
		}
	}
	return pos[n] = 0;
}

void bs(int s, int e){
	int mid = (s+e) / 2;
	if(s>e) return;
	
	for(int i=0; i<=2500; i++){
		A[i] = -1; B[i] = -1; t_adj[i].clear();
		pos[i] = 1;
	}	
	
	for(int i=1; i<carN; i++){
		for(auto x : adj[i]){
			if(x.second <= mid){
				t_adj[i].push_back(x.first);
			}
		}
	}
	
	
	int match = 0;
	while(1){
		int flow = 0;
		bfs();
		
		for(int i=0; i<=2500; i++) pos[i] = 1;
		for(int i=1; i<carN; i++)
			if(A[i] == -1 && dfs(i)) flow++;
		if(!flow) break;
		match += flow;
	}
	
	if(match == carN - 1){
		ans = mid;
		bs(s, mid-1);
	}
	else
		bs(mid+1, e);
}


int main() {
	scanf("%d%d", &R, &C);
	for(int i=0; i<R; i++) scanf("%s", map[i]);
	queue< pair< int, pair<int, int> > > q; 
	
	for(int i=0; i<R; i++){
		for(int j=0; j<C; j++){
			if(map[i][j] == 'P')
				imap[i][j] = parkN++;
		}
	}
	
	
	for(int i=0; i<R; i++){
		for(int j=0; j<C; j++){
			if(map[i][j] == 'C'){
				imap[i][j] = carN;
				
				for(int a=0; a<=50; a++){
					for(int b=0; b<=50; b++){
						visited[a][b] = 0;
					}
				}
				
				q.push(make_pair(0, make_pair(i, j)));
				visited[i][j] = 1;
				
				while(!q.empty()){
					int time = q.front().first;
					int x = q.front().second.first;
					int y = q.front().second.second; q.pop();
					
					
					for(int i=0; i<4; i++){
						if(x+dx[i] < 0 || x+dx[i] >= R) continue;
						if(y+dy[i] < 0 || y+dy[i] >= C) continue;
						if(map[x+dx[i]][y+dy[i]] == 'X') continue;
						if(visited[x+dx[i]][y+dy[i]]) continue;
						
						visited[x+dx[i]][y+dy[i]] = 1;
						
						if(map[x+dx[i]][y+dy[i]] == 'P'){
							int t_parkN = imap[x+dx[i]][y+dy[i]];
							adj[carN].push_back(make_pair(t_parkN, time+1));
							q.push(make_pair(time+1, make_pair(x+dx[i], y+dy[i])));
							
							
						}
						q.push(make_pair(time+1, make_pair(x+dx[i], y+dy[i])));
						
					}
				}
				carN++;
			}
		}
	}
	
	
	
	bs(0, 10000);
	if(carN == 1) printf("0");
	else if(carN > parkN) printf("-1");
	else printf("%d", ans);
}