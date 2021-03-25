//# Author : nuclear852 ========================#
//# Solution : 25925449 ========================#
//# Time Stamp : 2021-02-01 23:09:50 ===========#
//# Problem Title : 두부장수 장홍준 ===============#
//# Language : C++17 ===========================#

#include <iostream>
#include <stdio.h>
#include <queue>
#include <vector>
#include <utility>
typedef long long ll;
using namespace std;

class SPFA{
    private:
        const int INF = 999999999;
        int N, S, E;
        vector<vector<int> > adj;
        vector<vector<int> > c;
        vector<vector<int> > f;
        vector<vector<int> > d;

        vector<int> parent;
        vector<int> dist;
        vector<int> inQ;

    public:
        SPFA(int _N, int _S, int _E) {
            N = _N; S = _S; E = _E;
            adj.resize(N + 5);
            parent.resize(N + 5);
            dist.resize(N + 5);
            inQ.resize(N + 5);
            c.resize(N+5, vector<int>(N+5));
            f.resize(N+5, vector<int>(N+5));
            d.resize(N+5, vector<int>(N+5));
        }

        void clear() {
            for(int i=0; i<=N; i++) {
                parent[i] = -1;
                dist[i] = INF;
                inQ[i] = 0;
            }
            parent[S] = parent[E] = -1;
            inQ[S] = inQ[E] = false;
            dist[S] = dist[E] = INF;
        }

        void addEdge(int a, int b, int cap, int v) {
            adj[a].push_back(b);
            adj[b].push_back(a);
            d[a][b] = v;
            d[b][a] = -v;
            c[a][b] = cap;
        }

        ll getSPFA() {
            ll ans = 0;
            ll cost = 0, flow = 0;
            while(true) {
                clear();
                queue<int> q; q.push(S);
                dist[S] = 0;
                inQ[S] = true;

                while(!q.empty()) {
                    int cur = q.front(); q.pop();
                    inQ[cur] = false;
                    for(auto next: adj[cur]) {
                        if(c[cur][next] > f[cur][next] && dist[cur] + d[cur][next] < dist[next] ) {
                            dist[next] = dist[cur] + d[cur][next];
                            parent[next] = cur;
                            if(!inQ[next]) {
                                q.push(next);
                                inQ[next] = true;
                            }
                        }
                    }
                }

                if(parent[E] == -1) break;
                flow ++;
                for(int i=E; i!=S; i=parent[i]) {
                    cost += d[parent[i]][i];
                    f[parent[i]][i]++;
                    f[i][parent[i]]--;
                }
                if(ans < cost) break;
                ans = min(ans, cost);
            }
            return ans;
        }
};

int getScore(char a, char b) {
    if(a < b) {
        swap(a, b);
    }

    if(a == b) {
        if(a == 'A') return 10;
        else if(a == 'B') return 6;
        else if(a == 'C') return 3;
        else if(a == 'D') return 2;
        else return 0;
    }
    else if(b == 'A') {
        if(a == 'B') return 8;
        else if(a == 'C') return 7;
        else if(a == 'D') return 5;
        else  return 1;
    }
    else if(b == 'B') {
        if(a == 'C') return 4;
        else if(a == 'D') return 3;
        else return 1;
    }
    else if(b == 'C') {
        if(a == 'D') return 2;
        else return 1;
    }
    return 1;
}

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);
    int N, M;
    char map[55][55];
    cin >> N >> M;
    SPFA *spfa = new SPFA(N*M, N*M+1, N*M+2);
    for(int i=0; i<N; i++) cin >> map[i];

    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            int cur = (i*M) + j ;
            spfa->addEdge(N*M+1, cur, 1, 0);
            if((i+j)%2 == 0) {
                for(int k=0; k<4; k++) {
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    if( nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
                    int next = (nx*M) + ny ;
                    spfa->addEdge(cur, next, 1, -getScore(map[i][j], map[nx][ny]));
                }
            }
            else {
                spfa->addEdge(cur, N*M+2, 1, 0);
            }
        }
    }
    auto val = -spfa->getSPFA();
    if (val == -999999999) cout << 0;
    else cout << val;

}