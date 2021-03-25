//# Author : nuclear852 ========================#
//# Solution : 25378020 ========================#
//# Time Stamp : 2021-01-17 23:20:50 ===========#
//# Problem Title : 악당 로봇 ==================#
//# Language : C++17 ===========================#

#include <stdio.h>
#include <string>
#include <queue>
#include <algorithm>
#include <tuple>
#include <iostream>
using namespace std;

int d[1001][1000];
int N, K; 
int to_num(char c) {
    return c - 'A';
}

class AhoCorasick {
    private:
        int trie[1000][3];
        int fail[1000];
        int term[1000];
        int idx;

    public:
        AhoCorasick() {
            for(int i=0; i<1000; i++) {
                for(int j=0; j<1000; j++) {
                    trie[i][j] = 0;
                }
                fail[i] = term[i] = 0;
            }
            idx = 0;
        }
        
        void insert(string str) {
            int cur = 0;
            for(int i=0; i<str.size(); i++) {
                int path = to_num(str[i]);
                if(!trie[cur][path]) {
                    trie[cur][path] = ++idx;
                }
                cur = trie[cur][path];
            }
            term[cur] = 1;
        }

        void make_failFunc() {
            queue<int> q; q.push(0);
            while(!q.empty()) {
                int cur = q.front(); q.pop();
                for(int path=0; path<3; path++) {
                    if(!trie[cur][path]) continue;
                    int next = trie[cur][path];
                    if(cur == 0) {
                        fail[next] = 0;
                    }
                    else {
                        int f = fail[cur];
                        while(f && !trie[f][path]) f = fail[f];
                        if(trie[f][path]) f = trie[f][path];
                        fail[next] = f;
                    }
                    if(term[fail[next]]) term[next] = term[next] + term[fail[next]];
                    q.push(next);
                }
            }
        }

        void init_solve() {
            queue<tuple<int, int, int> > q; q.push(make_tuple(0, 0, 0));
            while(!q.empty()) {
                auto info = q.front(); q.pop();
                int cur = get<0>(info);
                int lv = get<1>(info);
                int sum = get<2>(info);
                d[lv][cur] = max(d[lv][cur], term[cur]);
                sum += term[cur];
                for(int i=0; i<3; i++) {
                    if(!trie[cur][i]) continue;
                    q.push(make_tuple(trie[cur][i], lv + 1, sum));
                }
            }
        }

        int solve() {
            int ans = 0;
            for(int i=0; i<K; i++) {
                for(int j=0; j<=idx; j++) {
                    if(!d[i][j]) continue;
                    for(int k=0; k<3; k++) {
                        int cur = j;
                        while(cur && !trie[cur][k]) cur = fail[cur];
                        if(trie[cur][k]) cur = trie[cur][k];
                        d[i+1][cur] = max(d[i+1][cur], d[i][j] + term[cur]);
                    }
                }
            }
            for(int i=0; i<=idx; i++) {
                ans = max(ans, d[K][i]);
            }
            return ans;
        }
};

AhoCorasick *ac = new AhoCorasick();

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> N >> K;
    for(int i=0; i<N; i++) {
        string s; cin >> s;
        ac->insert(s);
    }
    ac->make_failFunc();
    ac->init_solve();
    printf("%d", ac->solve());
    delete ac;

}