//# Author : nuclear852 ========================#
//# Solution : 25012030 ========================#
//# Time Stamp : 2021-01-07 15:52:06 ===========#
//# Problem Title : 룩 배치하기 =================#
//# Language : C++17 ===========================#

#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

int N;
char map[101][101];
int row = 0, col = 0;
int rowM[101][101];
int colM[101][101];

int aMatched[5050], bMatched[5050];
int checked[5050];
int level[5050];
vector<int> adj[5050];

void bfs() {
    queue<int> q;

    for(int i=1; i<=row; i++) {
        if(aMatched[i] == -1) {
            q.push(i);
            level[i] = 0;
        }
        else {
            level[i] = -5;
        }
    }

    while(!q.empty()) {
        int cur = q.front(); q.pop();
        for(auto next: adj[cur]) {
            if(bMatched[next] != -1 && level[bMatched[next]] == -5) {
                level[bMatched[next]] = level[cur] + 1;
                q.push(bMatched[next]);
            }
        }
    }
}

bool dfs(int cur) {
    for(int &i = checked[cur]; i<adj[cur].size(); i++) {
        int next = adj[cur][i];
        if(bMatched[next] == -1) {
            aMatched[cur] = next;
            bMatched[next] = cur;
            return 1;
        }
        if(level[bMatched[next]] == level[cur] + 1) {
            if(dfs(bMatched[next])) {
                aMatched[cur] = next;
                bMatched[next] = cur;
                return 1;
            }
        }
    }
    return 0;
}

int main() {
    scanf("%d", &N);
    for(int i=0; i<N; i++) {
        scanf("%s", map[i]);
    }

    for(int i=0; i<N; i++) {
        bool cont = false;
        for(int j=0; j<N; j++) {
            if(map[i][j]=='.' && !cont) {
                rowM[i][j] = ++row;
                cont = true;
            }
            else if(map[i][j]=='.' && cont) {
                rowM[i][j] = row;
            }
            else {
                cont = false;
            }
        }
    }

    for(int j=0; j<N; j++) {
        bool cont = false;
        for(int i=0; i<N; i++) {
            if(map[i][j]=='.' && !cont) {
                colM[i][j] = ++col;
                cont = true;
            }
            else if(map[i][j]=='.' && cont) {
                colM[i][j] = col;
            }
            else {
                cont = false;
            }
        }
    }

    for(int i=1; i<=row; i++) {
        aMatched[i] = -1;
    }
    for(int i=1; i<=col; i++) {
        bMatched[i] = -1;
    }

    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            if(map[i][j] == '.') {
                adj[rowM[i][j]].push_back(colM[i][j]);

            }
        }
    }

    int ans = 0;
    while(true) {
        int flow = 0;
        bfs();
        for(int i=1; i<=row; i++) checked[i] = 0;
        for(int i=1; i<=row; i++) {
            if(aMatched[i] == -1 && dfs(i)) flow++;
        }
        if(!flow) break;
        ans += flow;
    }
    printf("%d", ans);

}