#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <functional>
#include <queue>
#include <stack>
#include <string>
using namespace std;

vector<int> adj[100001];
bool visited[100001];

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int N; cin >> N;
    for(int i=0; i<N-1; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    queue<int> q;
    visited[1] = true;
    q.push(1);
    int ans = N-1;
    while(!q.empty()) {
        int cur = q.front(); q.pop();
        int sz = 1;
        for(auto next: adj[cur]) {
            if(!visited[next]) sz++;
        }
        ans += ceil(log2(sz));
        for(auto next: adj[cur]) {
            if(!visited[next]) {
                visited[next] = true;
                q.push(next);
            }
        }
    }
    cout << ans << "\n";
}