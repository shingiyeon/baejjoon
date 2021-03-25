//# Author : nuclear852 ========================#
//# Solution : 11940536 ========================#
//# Time Stamp : 2019-02-26 19:58:16 ===========#
//# Problem Title : 등산 =====================#
//# Language : C++98 ===========================#

#include <stdio.h>
#include <vector>
#include <queue>
#include <utility>
#define MAX 100000000000LL
using namespace std;

typedef long long ll;
typedef pair<int, ll> p;


struct cmp{
	bool operator()(p t, p u){
		return t.second > u.second;
	}
};

int N, M, D, E;
ll start[100001];
ll end[100001];
int height[100001];
vector< vector<pair<int, ll> > > s(100001);
bool visited[100001];

void dijkstra(int point, ll m[], int sign){
	for(ll i=1; i<=N; i++){
		visited[i] = 0;
		m[i] = MAX;
	}
	priority_queue<p, vector<p>, cmp> q;
	m[point] = 0;
	q.push( p(point,0) );
	while(!q.empty()){
		p tp = q.top(); q.pop();
		ll tpoint = tp.first; ll tvalue = tp.second;
		if(visited[tpoint]) continue;
		visited[tpoint] = 1;
		
		for(int i=0; i<s[tpoint].size(); i++){
			if( visited[s[tpoint][i].first] ) continue;
			if( s[tpoint][i].second * sign < 0) continue;
			if( height[tpoint] >= height[s[tpoint][i].first] ) continue;
			if( m[s[tpoint][i].first] > s[tpoint][i].second * sign + tvalue){
				m[s[tpoint][i].first] = s[tpoint][i].second * sign + tvalue;
				q.push( p(s[tpoint][i].first,m[s[tpoint][i].first]) );
			}
		}
	}
	return ;
	
}

int main(){
	int x, y; ll d;
	scanf("%d%d%d%d",&N,&M,&D,&E);
	for(int i=1; i<=N; i++)
		scanf("%d", &height[i]);
	for(int i=1; i<=M; i++){
		scanf("%d%d%lld",&x,&y,&d);
		if(height[x]>height[y]){
			s[y].push_back(p(x, d));
			s[x].push_back(p(y, -d));
		}
		else{
			s[y].push_back(p(x, -d));
			s[x].push_back(p(y, d));
		}
	}
	dijkstra(1, start, 1);
	dijkstra(N, end, 1);
	ll MAXV = -99999999999999;
	for(int i=1; i<=N; i++){
		if(start[i]==MAX || end[i]==MAX) continue;
		if(height[i] * E - (start[i]+end[i])*D > MAXV) MAXV = height[i] * E - (start[i]+end[i])*D;
	}
	
	if(MAXV == -99999999999999){
		printf("Impossible");
		return 0;
	}
	
	printf("%lld", MAXV);
	
	
}