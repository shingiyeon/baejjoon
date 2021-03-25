//# Author : nuclear852 ========================#
//# Solution : 24242897 ========================#
//# Time Stamp : 2020-12-06 23:39:24 ===========#
//# Problem Title : 임계경로 ===================#
//# Language : C++17 ===========================#

#include <stdio.h>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
typedef pair<int, int> p;
vector< pair<int,int> > adj[10001];
vector<int> parent[10001];
int max_time[10001];
int indeg[10001];
int indeg2[10001];
bool visited[10001];

int n, m;

int main() {
    scanf("%d%d", &n, &m);
    for(int i=1; i<=m; i++) {
        int a, b, c; scanf("%d%d%d", &a, &b, &c);
        adj[a].push_back({b, c});
        indeg[b]++;
    }
    int s, e; scanf("%d%d", &s, &e);
    priority_queue<p, vector<p>, less<p> > q;
    q.push({0, s});
    int answer = 0;
    int MAX_time = 0;
    while(!q.empty()) {
        int cur = q.top().second; int time = q.top().first;
        MAX_time = max(MAX_time, time);
        q.pop();
        for(auto inf: adj[cur]) {
            int next = inf.first; int dist = inf.second;
            indeg[next]--;
            if(time + dist > max_time[next]) {
                max_time[next] = time+dist;
                parent[next].clear();
                parent[next].push_back(cur);
                indeg2[cur] = 1;
            }
            else if(time + dist == max_time[next]) {
                parent[next].push_back(cur);
                indeg2[cur]++;
            }
            if(indeg[next] == 0) {
                q.push({max_time[next], next});
            }
        }
    }
    int ans = 0;
    queue<int> tq;
    tq.push(e);
    visited[e] = 1;
    while(!tq.empty()) {
        int cur = tq.front(); tq.pop(); 
        parent[cur].erase(unique(parent[cur].begin(), parent[cur].end()), parent[cur].end());
        for(auto next: parent[cur]) {
            ans++;
            if(!visited[next]) {
                tq.push(next);
                visited[next] = 1;
            }
        }
    }

    printf("%d\n%d", MAX_time, ans);

}