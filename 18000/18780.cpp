//# Author : nuclear852 ========================#
//# Solution : 24491556 ========================#
//# Time Stamp : 2020-12-20 22:34:31 ===========#
//# Problem Title : Timeline ===============#
//# Language : C++17 ===========================#

#include <stdio.h>
#include <queue>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> p;


int arr[100001];
long long ans[100001];
int indeg[100001];
bool visited[100001];
vector< vector<p> > adj;
int N, M, C;

int main() {
    scanf("%d%d%d", &N, &M, &C);
    adj.resize(N+1);
    queue<int> pq;
    for(int i=1; i<=N; i++) {
        scanf("%d", &arr[i]);
    }
    for(int i=1; i<=C; i++) {
        int a, b, x;
        scanf("%d%d%d", &a, &b, &x);
        adj[a].push_back({b, x});
        indeg[b]++;
    }
    for(int i=1; i<=N; i++) {
        ans[i] = (ll)arr[i];
        if(!indeg[i]) {
            visited[i] = true;
            pq.push(i);
        }
    }
    while(!pq.empty()) {
        int cur = pq.front(); pq.pop();
        for(auto info: adj[cur]) {
            int next = (int)info.first; ll p_day = info.second;
            ans[next] = max(ans[next], ans[cur] + info.second);
            indeg[next]--;
            if(!indeg[next] && !visited[next]) {
                pq.push(next);
                visited[next] = true;
            }
        }
    }
    for(int i=1; i<=N; i++) {
        printf("%lld\n", ans[i]);
    }
}