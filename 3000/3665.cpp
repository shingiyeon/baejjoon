//# Author : nuclear852 ========================#
//# Solution : 24241764 ========================#
//# Time Stamp : 2020-12-06 22:42:47 ===========#
//# Problem Title : 최종 순위 ==================#
//# Language : C++17 ===========================#

#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int, pair<int, int> > p;

int T, n, m;

int arr[501];
int adj[501][501];
bool visited[501];
vector<int> answer;
int indeg[501];
int lv[501];

int main() {
    scanf("%d", &T);
    while(T--) {
        answer.clear();
        for(int i=1; i<=500; i++) {
            for(int j=1; j<=500; j++) {
                adj[i][j] = 0;
            }
            visited[i] = 0;
            indeg[i] = 0; lv[i] = 0;
        }
        scanf("%d", &n);
        for(int i=1; i<=n; i++) {
            scanf("%d", &arr[i]);
            lv[arr[i]] = i;
        }
        for(int i=1; i<=n; i++) {
            for(int j=i+1; j<=n; j++) {
                adj[arr[i]][arr[j]] = 1;
                indeg[arr[j]]++;
            }
        }
        scanf("%d", &m);
        for(int i=1; i<=m; i++) {
            int a, b; scanf("%d%d", &a, &b);
            if(lv[a] < lv[b]) {
                adj[a][b] = 0; adj[b][a] = 1;
                indeg[b]--; indeg[a]++;
            }
            else {
                adj[b][a] = 0; adj[a][b] = 1;
                indeg[a]--; indeg[b]++;
            }
        }
        queue<int> q;
        for(int i=1; i<=n; i++) {
            if(!indeg[i]) {
                visited[i] = 1;
                q.push(i);
            }
        }
        bool pos = 1;
        while(!q.empty()) {
            if(q.size() > 1) {
                pos = 0;
                break;
            }
            int cur = q.front(); q.pop();
            answer.push_back(cur);
            for(int i=1; i<=n; i++) {
                if(adj[cur][i] && !visited[i]) {
                    indeg[i]--;
                    if(indeg[i] == 0) {
                        visited[i] = 1;
                        q.push(i);
                    }
                }
            }
        }
        if(pos == 0) {
            printf("?\n");
        }   
        else if(answer.size() != n) {
            printf("IMPOSSIBLE\n");
        }     
        else {
            for(auto val: answer) {
                printf("%d ", val);
            }
            printf("\n");
        }
        
    }
}