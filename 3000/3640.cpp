//# Author : nuclear852 ========================#
//# Solution : 21588841 ========================#
//# Time Stamp : 2020-08-08 23:18:57 ===========#
//# Problem Title : 제독 =====================#
//# Language : C++14 ===========================#

#include <stdio.h>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
#include <map>
#define INF 999999999
using namespace std;
 
map< pair<int, int> , int > c;
map< pair<int, int> , int > f;
map< pair<int, int> , int > d;
 
int dist[2020];
int p[2020];
bool inQ[2020];
 
vector<int> adj[2020];
 
int v, e;
 
int S = 0, E = 2010;
 
pair<int, int> SPFA(){
    int flow = 0;
    int cost = 0;
    
    while(1) {
        for(int i=0; i<2020; i++) {
            dist[i] = INF;
            p[i] = -1;
            inQ[i] = 0;
        }
        queue<int> q;
        q.push(S);
        dist[0] = 0;
        while(!q.empty()) {
            int cur = q.front(); q.pop();
            inQ[cur] = 0;
            for(auto next : adj[cur]) {
                if(c[{cur,next}] > f[{cur,next}] && dist[next] > dist[cur]+d[{cur,next}]){
                    dist[next] = dist[cur] + d[{cur, next}];
                    p[next] = cur;
                    if(!inQ[next]){
                        q.push(next);
                        inQ[next] = 1;
                    }
                }
            }
        }
        
        if(p[E] == -1) break;
 
        int cur_flow = 999999999;
        
        for(int i = E; i != S; i = p[i]){
            cur_flow = min(cur_flow, c[{p[i], i}] - f[{p[i], i}]);
        }
        
        flow += cur_flow;
 
        for(int i = E; i != S; i = p[i]){
            //printf("cur: %d\n", i);
            //printf("(%d, %d) d: %d\n", p[i]/2, i/2, d[{p[i], i}]);
            cost += d[{p[i], i}] * cur_flow;
            f[{p[i], i}] += cur_flow;
            f[{i, p[i]}] -= cur_flow;
        }
    }
    return {cost, flow};
}
 
int main(){
    while(scanf("%d %d", &v, &e) != EOF){
        c.clear();
        f.clear();
        d.clear();
        for(int i=0; i<2020; i++) adj[i].clear();
        
        int a, b, V;
        for(int i=0; i<e; i++){
            scanf("%d%d%d", &a, &b, &V);
            adj[2*a+1].push_back(2*b);
            adj[2*b].push_back(2*a+1);
            adj[2*b+1].push_back(2*a);
            adj[2*a].push_back(2*b+1);
            c[{2*a+1, 2*b}] = 1;
            d[{2*a+1, 2*b}] = V;
            d[{2*b, 2*a+1}] = -V;
        }
        
        for(int i=1; i<=v; i++){
            adj[2*i].push_back(2*i+1);
            adj[2*i+1].push_back(2*i);
            c[{2*i, 2*i+1}] = 1;
        }
        c[{2, 3}] = 2;
        c[{2*v, 2*v+1}] = 2;
        
        c[{S, 2}] = 2;
        c[{2*v+1, E}] = 2;
        
        adj[0].push_back(2);
        adj[2*v+1].push_back(E);
        
        pair<int, int> p = SPFA();
        printf("%d\n", p.first);
    }
}