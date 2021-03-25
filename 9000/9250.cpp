//# Author : nuclear852 ========================#
//# Solution : 25218606 ========================#
//# Time Stamp : 2021-01-13 09:44:11 ===========#
//# Problem Title : 문자열 집합 판별 ==============#
//# Language : C++17 ===========================#

#include <stdio.h>
#include <string>
#include <queue>
#include <unordered_map>
using namespace std;

class AhoCorasick {
    public:
    int trie[100005][26];
    bool term[100005];
    int fail[100005];
    int idx;

    AhoCorasick() {
        for(int i=0; i<100005; i++) {
            term[i] = fail[i] = 0;
        }
        idx = 0;
    }

    static int to_num(char c) {
        return c-'a';
    }

    void insert(string s) {
        int cur = 0;
        for(int i=0; i<s.size(); i++) {
            int next = to_num(s[i]);
            if(!trie[cur][next]) {
                trie[cur][next] = ++idx;
            }
            cur = trie[cur][next];
        }
        term[cur] = true;
    }

    void make_failFunc() {
        queue<int> q; q.push(0);
        while(!q.empty()) {
            int cur = q.front(); q.pop();
            for(int i=0; i<26; i++) {
                if(!trie[cur][i]) continue;
                int next = trie[cur][i];
                if(cur == 0) fail[i] = 0;
                else {
                    int f = fail[cur];
                    while(f && !trie[f][i] ) {
                        f = fail[f];
                    }
                    if(trie[f][i]) f = trie[f][i];
                    fail[next] = f;
                }
                if(term[fail[next]]) term[next] = term[fail[next]];
                q.push(next);
            }
        }
    }
    bool solve(string s) {
        int cur = 0;
        for(int i=0; i<s.size(); i++) {
            int next = to_num(s[i]);
            while(cur && !trie[cur][next]) {
                cur = fail[cur];
            }
            if(trie[cur][next]) cur = trie[cur][next];
            if(term[cur]) return true;
        }
        return false;
    }
};
char tmp[10005];

int main() {
    AhoCorasick* ac= new AhoCorasick();
    int N; scanf("%d", &N);
    while(N--) {
        scanf("%s", tmp); string A = tmp;
        ac->insert(A);
    }
    ac->make_failFunc();
    scanf("%d", &N);
    while(N--) {
        scanf("%s", tmp); string B = tmp;
        printf("%s\n", ac->solve(B) ? "YES" : "NO");
    }
}