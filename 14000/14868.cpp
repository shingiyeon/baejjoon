//# Author : nuclear852 ========================#
//# Solution : 26284956 ========================#
//# Time Stamp : 2021-02-11 22:57:41 ===========#
//# Problem Title : 문명 =====================#
//# Language : C++17 ===========================#

#include <iostream>
#include <queue>
#include <algorithm>
#include <utility>
using namespace std;

int p[100001];
int sz[100001];
int map[2002][2002];
int N, K;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int parent(int cur) {
    if(p[cur] == cur) return p[cur];
    return p[cur] = parent(p[cur]);
}

void hap(int x, int y) {
    int pX = parent(x);
    int pY = parent(y);
    if(pX == pY) return;
    if(sz[pX] < sz[pY]) {
        p[pX] = pY;
        sz[pY] += sz[pX];
    }
    else {
        p[pY] = pX;
        sz[pX] += sz[pY];
    }
}

int main() {
    int ans = 0;
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> N >> K;
    for(int i=1; i<=K; i++) {
        p[i] = i;
        sz[i] = 1;
    }

    for(int i=1; i<=K; i++) {
        int x, y;
        cin >> x >> y;
        map[x][y] = i;
    }
    queue< pair<int, pair<int, int> > > q;

    for(int i=1; i<=N; i++) {
        for(int j=1; j<=N; j++) {
            if(map[i][j] == 0) continue;
            if(map[i-1][j] != 0) {
                if(parent(map[i][j]) != parent(map[i-1][j])) {
                    hap(map[i][j], map[i-1][j]); K--;
                }
            }
            if(map[i][j-1] != 0) {
                if(parent(map[i][j]) != parent(map[i][j-1])) {
                    hap(map[i][j], map[i][j-1]); K--;
                }
            }
        }
    }

    for(int i=1; i<=N; i++) {
        for(int j=1; j<=N; j++) {
            if(map[i][j] != 0) {
                q.push({parent(map[i][j]),{i, j}});
            }
        }
    }

    while(K > 1) {
        vector<pair<int, pair<int, int> > > v;
        while(!q.empty()) {
            auto info = q.front(); q.pop();
            int pi = info.first; int x = info.second.first; int y= info.second.second;
            for(int i=0; i<4; i++) {
                if(x + dx[i] < 1 || x + dx[i] > N || y + dy[i] < 1 || y + dy[i] > N) continue;
                if(map[x+dx[i]][y+dy[i]] == 0) {
                    map[x+dx[i]][y+dy[i]] = parent(pi);
                    v.push_back({parent(pi), {x+dx[i], y+dy[i]}});
                }
                else {
                    if(parent(map[x+dx[i]][y+dy[i]]) != parent(pi)) {
                        hap(map[x+dx[i]][y+dy[i]], parent(pi)); K--; 
                    }
                } 
            }
        }

        for(auto info: v) {
            int pi = info.first; int x = info.second.first; int y = info.second.second;
            for(int i=0; i<4; i++) {
                if(x + dx[i] < 1 || x + dx[i] > N || y + dy[i] < 1 || y + dy[i] > N) continue;
                if(map[x+dx[i]][y+dy[i]] != 0) {
                    if(parent(map[x+dx[i]][y+dy[i]]) != parent(pi)) {
                        hap(map[x+dx[i]][y+dy[i]], parent(pi)); K--;
                    }
                }
            }
            q.push(info);
        }
        ans++;
    }
    cout << ans;
}