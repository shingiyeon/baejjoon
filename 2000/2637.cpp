//# Author : nuclear852 ========================#
//# Solution : 24258221 ========================#
//# Time Stamp : 2020-12-07 22:56:45 ===========#
//# Problem Title : 장난감조립 ==================#
//# Language : C++17 ===========================#

#include <stdio.h>
#include <vector>
#include <queue>
#include <utility>
#include <functional>

using namespace std;

int N, M;
vector< pair<int, int>  > adj[101];
int indeg[101];
int t_indeg[101];
bool visited[101];
int deg[101];

int ans[101];
int main() {
    int X, Y, K;
    scanf("%d%d", &N, &M);
    queue< pair<int, int> > q;
    for(int i=1; i<=M; i++) {
        scanf("%d%d%d", &X, &Y, &K);
        indeg[X]++;
        adj[Y].push_back({X, K});
    }

    for(int i=1; i<=N; i++) {
        if(!indeg[i]) {
            for(int j=1; j<=N; j++) {
                t_indeg[j] = 0;
                deg[j] = 0;
                visited[j] = 0;
            }
            queue<int> tq;
            tq.push(i);
            while(!tq.empty()) {
                int cur = tq.front(); tq.pop();
                for(auto inf: adj[cur]) {
                    int next = inf.first; t_indeg[next]++;
                    if(!visited[next]) {
                        visited[next] = 1;
                        tq.push(next);
                    }
                }
            }

            q.push({i, 1});
            while(!q.empty()) {
                int cur = q.front().first; int num = q.front().second; q.pop();
                for(auto inf: adj[cur] ) {
                    int next = inf.first; int k = inf.second;
                    t_indeg[next]--;
                    deg[next] += num*k;
                    if(t_indeg[next] == 0) {
                        q.push({next, deg[next]});
                    }
                }
            }
            ans[i] = deg[N];
        }
    }

    for(int i=1; i<=N; i++) {
        if(!indeg[i]) {
            printf("%d %d\n", i, ans[i]);
        }
    }
}