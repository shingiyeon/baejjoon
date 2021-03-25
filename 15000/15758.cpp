//# Author : nuclear852 ========================#
//# Solution : 24497649 ========================#
//# Time Stamp : 2020-12-21 10:04:39 ===========#
//# Problem Title : Milking Order ==========#
//# Language : C++17 ===========================#

#include <stdio.h>
#include <vector>
#include <queue>
#include <utility>
#include <functional>

using namespace std;

int N, M;
vector< pair<int, int> > edges[50001];
vector< vector<int> > adj;
vector<int> ans;
int indeg[100001];

bool bfs(int cur) {
    vector<int> t_ans;
    priority_queue<int, vector<int>, greater<int> > pq;
    for(int i=1; i<=N; i++) {
        adj[i].clear();
        indeg[i] = 0;
    }

    for(int i=1; i<=cur; i++) {
        for(auto edge : edges[i]) {
            adj[edge.first].push_back(edge.second);
            indeg[edge.second]++;
        }
    }
    for(int i=1; i<=N; i++) {
        if(!indeg[i]) pq.push(i);
    }
    while(!pq.empty()) {
        int cur = pq.top(); pq.pop();
        t_ans.push_back(cur);
        for(auto next: adj[cur]) {
            indeg[next]--;
            if(!indeg[next]) pq.push(next);
        }
    }
    if(t_ans.size() == N) {
        ans = t_ans; return true;
    }
    return false;
}

void bs() {
    int s = 1; int e = M;
    while(s<=e) {
        //printf("%d %d\n", s, e);
        int mid = (s+e) / 2;
        bool pos = bfs(mid);
        if(pos) {
            s = mid + 1;
        }
        else {
            e = mid - 1;
        }
    }
    //printf("%d\n", s);
}

int main() {
    scanf("%d%d", &N, &M);
    adj.resize(N+1);
    for(int i=1; i<=M; i++) {
        int a, b, c; scanf("%d%d", &a, &b);
        for(int j=1; j<a; j++) {
            scanf("%d", &c);
            edges[i].push_back({b, c});
            b = c;
        }
    }
    bs();
    for(auto val: ans) {
        printf("%d ", val);
    }


}