//# Author : nuclear852 ========================#
//# Solution : 25648398 ========================#
//# Time Stamp : 2021-01-25 15:02:38 ===========#
//# Problem Title : 타워 디펜스 =================#
//# Language : C++17 ===========================#

#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>
#include <stack>
using namespace std;
int N, M;
char tmp[105][105];
char map[105][105];
int garo[105][105];
int sero[105][105];
int map_g[105][105][2];
int map_s[105][105][2];

int g_idx = 0, s_idx = 0;
vector<int> adj[20005];
int scc[20005];
int cnt = 0, s_cnt = 0;
bool inS[20005];
stack<int> S;
int num[20005], gNum[20005];
void dfs(int cur) {
    S.push(cur);
    inS[cur] = true;
    num[cur] = ++cnt;
    gNum[cur] = cnt;

    for(auto next: adj[cur]) {
        if(!num[next]) {
            dfs(next);
            gNum[cur] = min(gNum[cur], gNum[next]);
        }
        else if(inS[next]) {
            gNum[cur] = min(gNum[cur], num[next]);
        }
    }

    if(num[cur] == gNum[cur]) {
        s_cnt++;
        while(!S.empty()) {
            int s_cur = S.top(); S.pop();
            scc[s_cur] = s_cnt;
            inS[s_cur] = false;
            if(cur == s_cur) break;
        }
    }
}
int isNot(int num) {
    if(num <= 0) return num;
    if(num > 10000) {
        return num - 10000;
    }
    return num + 10000;
}

void addOneEdge(int a) {
    adj[isNot(a)].push_back(a);
}

void addTwoEdge(int a, int b) {
    adj[isNot(b)].push_back(a);
    adj[isNot(a)].push_back(b);
}

int g_dfs(int x, int y, int dir) {
    if(y > M + 1  || y < 0) return ++g_idx;
    if(garo[x][y] != -1) return garo[x][y];
    if(map[x][y] == 'T') return garo[x][y] = -2;
    else if(map[x][y] == '#') return ++g_idx;
    else {
        garo[x][y] = g_dfs(x, y + dir, dir);
    }
    return garo[x][y];
}

int s_dfs(int x, int y, int dir) {
    if(x > N + 1 || x < 0) return ++s_idx;
    if(sero[x][y] != -1) return sero[x][y];
    if(map[x][y] == 'T') return sero[x][y] = -2;
    else if(map[x][y] == '#') return ++s_idx;
    else {
        sero[x][y] = s_dfs(x + dir, y, dir);
    }
    return sero[x][y];
}

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> N >> M;
    for(int i=0; i<N; i++) cin >> tmp[i];
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            map[i+1][j+1] = tmp[i][j];
        }
    }
    for(int i=0; i<=N+1; i++) {
        for(int j=0; j<=M+1; j++) {
            sero[i][j] = garo[i][j] = -1;
        }
    }
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=M; j++) {
            if(map[i][j] == 'T') {
                garo[i][j] = -2; sero[i][j] = -2;
                int a = s_dfs(i-1, j, -1);
                int b = s_dfs(i+1, j, 1);
                int c = g_dfs(i, j-1, -1);
                int d = g_dfs(i, j+1, 1);

                if(a <= 0 && b > 0) addOneEdge(b + 5000);
                else if(b <= 0 && a > 0) addOneEdge(a + 5000);
                else if(a > 0 && b > 0){
                    addTwoEdge(a + 5000, b + 5000);
                    addTwoEdge(isNot(a + 5000), isNot(b + 5000));
                }
                if(c <= 0 && d > 0) addOneEdge(d);
                else if(d <= 0 && c > 0) addOneEdge(c);
                else if(c > 0 && d > 0){
                    addTwoEdge(c, d);
                    addTwoEdge(isNot(c), isNot(d));
                }

                map_s[i][j][0] = a;
                map_s[i][j][1] = b;
                map_g[i][j][0] = c;
                map_g[i][j][1] = d;

            }
        }
    }

    for(int i=1; i<=N; i++) {
        for(int j=1; j<=M; j++) {
            if(map[i][j] == 'n') {
                int a, b;
                a = garo[i][j];
                b = sero[i][j];
                if(a > 0 && b <= 0) addOneEdge(a);
                else if(b > 0 && a <= 0) addOneEdge(b + 5000);
                else if(a > 0 && b > 0) addTwoEdge(a, b + 5000);
            }
        }
    }

    for(int i=0; i<20005; i++) {
        if(!num[i]) dfs(i);
    }

    for(int i=1; i<=N; i++) {
        for(int j=1; j<=M; j++) {
            if(map[i][j] == 'T') {
                bool g, s;
                int a, b, c, d;
                a = map_s[i][j][0];
                b = map_s[i][j][1];
                if(a < 0 && b > 0) s = true;
                else if(a > 0 && b < 0) s = false;
                else if(a > 0 && b > 0) {
                    s = scc[a+5000] < scc[b+5000] ? false : true;
                }
                c = map_g[i][j][0];
                d = map_g[i][j][1];
                if(c < 0 && d > 0) g = true;
                else if(c > 0 && d < 0) g = false;
                else if(c > 0 && d > 0) {
                    g = scc[c] < scc[d] ? false : true;
                }

                if(!g && s) {
                    tmp[i-1][j-1] = '1';
                }
                else if(s && g) {
                    tmp[i-1][j-1] = '2';
                }
                else if(g && !s) {
                    tmp[i-1][j-1] = '3';
                }
                else {
                    tmp[i-1][j-1] = '4';
                }
            }
            
        }
    }

    // for(int i=0; i<=N+1; i++) {
    //     for(int j=0; j<=M+1; j++) {
    //         printf("%2d ", garo[i][j]);
    //     }
    //     printf("\n");
    // }
    // printf("========\n");
    // for(int i=0; i<=N+1; i++) {
    //     for(int j=0; j<=M+1; j++) {
    //         printf("%4d ", sero[i][j] > 0 ? sero[i][j] + 5000 : sero[i][j]);
    //     }
    //     printf("\n");
    // }

    // for(int i=0; i<20005; i++) {
    //     if(adj[i].size()) {
    //         printf("%d : ", i);
    //         for(auto next: adj[i]) {
    //             printf("%d ", next);
    //         }
    //         printf("\n");
    //     }
    // }
    // printf("%d %d\n", s_idx, g_idx);

    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) printf("%c", tmp[i][j]);
        printf("\n");
    }

    
}