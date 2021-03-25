//# Author : nuclear852 ========================#
//# Solution : 25529245 ========================#
//# Time Stamp : 2021-01-21 22:46:38 ===========#
//# Problem Title : Separate String ========#
//# Language : C++17 ===========================#

#include <stdio.h>
#include <string>
#include <queue>
#include <vector>
#include <iostream>
#define MOD 1000000007LL
typedef long long ll;
using namespace std;


long long dy[100050];
int N;
class AhoCorasick {
    private:
        int trie[200005][26];
        int fail[200005];
        vector<int> v[200005];
        int idx;

    public:
        AhoCorasick() {
            for(int i=0; i<200005; i++) {
                for(int j=0; j<26; j++) trie[i][j] = 0;
                fail[i] = 0;
                idx = 0;
            }
        }

        static int to_num(char c) {
            return c - 'a';
        }

        void insert(string str) {
            int cur = 0;
            for(int i = 0; i < str.size(); i++) {
                int path = to_num(str[i]);
                if(!trie[cur][path]) trie[cur][path] = ++idx;
                cur = trie[cur][path];
            }
            v[cur].push_back(str.size());
            return;
        }

        void make_failFunc() {
            queue<int> q; q.push(0);
            while(!q.empty()) {
                int cur = q.front(); q.pop();
                for(int path=0; path<26; path++) {
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
                    if(v[fail[next]].size()) {
                        for(auto val: v[fail[next]]) v[next].push_back(val);
                    }
                    q.push(next);
                }
            }
        }

        void solve(string str) {
            dy[0] = 1;
            int cur = 0;
            for(int i=0; i<str.size(); i++) {
                int path = to_num(str[i]);
                while(cur && !trie[cur][path]) cur = fail[cur];
                if(trie[cur][path]) cur = trie[cur][path];
                if(v[cur].size()) {
                    for(auto val: v[cur]) {
                        dy[i+1] = (dy[i+1] + dy[i+1-val]) % MOD;
                    }
                }
            }
            return;
        }
};

AhoCorasick *ac = new AhoCorasick();
int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);

    string str;
    cin >> N;
    while(N--) {
        cin >> str;
        ac->insert(str);
    }
    ac->make_failFunc();
    cin >> str;
    ac->solve(str);
    printf("%lld", dy[str.size()]);
}