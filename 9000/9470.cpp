//# Author : nuclear852 ========================#
//# Solution : 24366565 ========================#
//# Time Stamp : 2020-12-14 15:26:44 ===========#
//# Problem Title : Strahler 순서 ============#
//# Language : C++17 ===========================#

#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int T, K, M, P;
int indeg[1001];
int Strahler[1001];
vector<int> lv[1001];
vector<int> adj[1001];
int main() {
    scanf("%d", &T);
    while(T--) {
        for(int i=0; i<=1000; i++) {
            indeg[i] = Strahler[i] = 0;
            adj[i].clear();
            lv[i].clear();
        }
        scanf("%d%d%d", &K, &M, &P);
        for(int i=1; i<=P; i++) {
            int a, b; scanf("%d%d", &a, &b);
            adj[a].push_back(b);
            indeg[b]++;
        }
        queue< int > q;
        for(int i=1; i<=M; i++) {
            if(!indeg[i]) {
                q.push(i);
                Strahler[i] = 1;
            }
        }
        while(!q.empty()) {
            int cur = q.front(); q.pop();
            for(auto next: adj[cur]) {
                lv[next].push_back(Strahler[cur]);
                indeg[next]--;
                if(!indeg[next]) {
                    sort(lv[next].begin(), lv[next].end());
                    if(lv[next].size() > 1 && lv[next][lv[next].size()-2] == lv[next][lv[next].size()-1]) {
                        Strahler[next] = lv[next][lv[next].size()-1]+1;
                    }
                    else {
                        Strahler[next] = lv[next][lv[next].size()-1];
                    }
                    q.push(next);
                }
            }
        } 

        printf("%d %d\n", K, Strahler[M]);
    }
}