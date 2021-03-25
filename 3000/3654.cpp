//# Author : nuclear852 ========================#
//# Solution : 25531163 ========================#
//# Time Stamp : 2021-01-21 23:27:30 ===========#
//# Problem Title : L퍼즐 ====================#
//# Language : C++17 ===========================#

#include <stdio.h>
#include <queue>
#include <iostream>

using namespace std;

int T;
int n, m;

char map[501][501];
int imap[501][501];

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

class HopcroftKarp {
    private:
        int lv[250010];
        int aMatched[250010], bMatched[250010];
        int checked[250010];
        vector<int> adj[250010];
        int N;
    
    public:
        HopcroftKarp() {
            for(int i=0; i<250010; i++) {
                lv[i] = -1;
                aMatched[i] = bMatched[i] = -1;
                checked[i] = 0;
            }
        }

        void insert(int a, int b) {
            adj[a].push_back(b);
        }

        void sizing(int _N) {
            N = _N;
        } 

        void bfs() {
            queue<int> q;


            for(int i=1; i<=N; i++) {
                if(aMatched[i] == -1) {
                    lv[i] = 0;
                    q.push(i);
                }
                else {
                    lv[i] = -5;
                }
            }
            while(!q.empty()) {
                int cur = q.front(); q.pop();
                for(auto next: adj[cur]) {
                    if(bMatched[next] != -1 && lv[bMatched[next]] == -5) {
                        lv[bMatched[next]] = lv[cur] + 1;
                        q.push(bMatched[next]);
                    }
                }
            }
        }
        
        bool dfs(int cur) {
            for(int &i = checked[cur]; i < adj[cur].size(); i++) {
                int next = adj[cur][i];

                if(bMatched[next] == -1) {
                    bMatched[next] = cur;
                    aMatched[cur] = next;
                    return true;
                }
                else if(lv[bMatched[next]] == lv[cur] + 1 && dfs(bMatched[next])) {
                    aMatched[cur] = next;
                    bMatched[next] = cur;
                    return true;
                }
            }
            return false;
        }

        int solve() {
            int ans = 0;
            while(true) {
                int tmp_ans = 0;
                for(int i=1; i<=N; i++) {
                    checked[i] = 0;
                }
                bfs();
                for(int i=1; i<=N; i++) {
                    if(aMatched[i] == -1 && dfs(i)) tmp_ans++;
                }
                if(!tmp_ans) break;
                ans += tmp_ans;
            }
            return ans;
        }
};

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> T;
    while(T--) {
        cin >> n >> m;
        int B = 0;
        int W_even = 0, W_odd = 0;

        HopcroftKarp *h1 = new HopcroftKarp();
        HopcroftKarp *h2 = new HopcroftKarp();
        for(int i=0; i<n; i++) {
            cin >> map[i];
        }

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(map[i][j] == 'B') {
                    imap[i][j] = ++B;
                }
                else if(map[i][j] == 'W') {
                    if(i%2) {
                        imap[i][j] = ++W_odd;
                    }
                    else {
                        imap[i][j] = ++W_even;
                    }
                }
            }
        }

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(map[i][j] == 'B') {
                    for(int k=0; k<4; k++) {
                        if(i+dx[k] < 0 || i+dx[k] >= n || j+dy[k] < 0 || j+dy[k] >=m) continue;
                        if(map[i+dx[k]][j+dy[k]] == 'W') {
                            if( (i+dx[k])%2 ) {
                                h1->insert(imap[i][j], imap[i+dx[k]][j+dy[k]]);
                            }
                            else {
                                h2->insert(imap[i][j], imap[i+dx[k]][j+dy[k]]);
                            }
                        }
                    }
                }
            }
        }
        h1->sizing(B);
        h2->sizing(B);

        if(2*B == W_odd + W_even) {
            if(h1->solve() == h2->solve()) {
                cout << "YES\n"; 
            }
            else {
                cout << "NO\n";
            }
        }
        else {
            cout << "NO\n";
        }

        delete h1;
        delete h2;
    }
}