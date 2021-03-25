//# Author : nuclear852 ========================#
//# Solution : 24138721 ========================#
//# Time Stamp : 2020-11-30 22:54:24 ===========#
//# Problem Title : 작업 =====================#
//# Language : C++17 ===========================#

#include <stdio.h>
#include <utility>
#include <queue>
#include <functional>
#include <algorithm>
using namespace std;
typedef pair<int, int> p;

int N;
int arr[10001];
int indeg[10001];
int ans[10001];
vector<int> adj[10001];
priority_queue<p, vector<p>, greater<p>> q;
int MAX = 0;
int main() {
    int len, parent;
    scanf("%d", &N);
    for(int i=1; i<=N; i++) {
        scanf("%d", &arr[i]);
        scanf("%d", &len);
        for(int j=1; j<=len; j++) {
            scanf("%d", &parent);
            indeg[i]++;
            adj[parent].push_back(i);
        }
    }
    for(int i=1; i<=N; i++) {
        if(!indeg[i]) {
            q.push({arr[i], i});
            MAX = max(MAX, arr[i]);
        }
    }
    while(!q.empty()) {
        p tmp = q.top(); q.pop();
        int time = tmp.first;
        int cur = tmp.second;
        for(auto next: adj[cur]) {
            indeg[next]--;
            if(!indeg[next]) {
                MAX = max(MAX, time + arr[next]);
                q.push({time+arr[next], next});
            }
        }
    }
    printf("%d", MAX);

}