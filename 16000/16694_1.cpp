//# Author : nuclear852 ========================#
//# Solution : 25218521 ========================#
//# Time Stamp : 2021-01-13 09:37:46 ===========#
//# Problem Title : The ABCD Murderer ======#
//# Language : C++17 ===========================#

#include <stdio.h>
#include <string>
#include <queue>
#include <unordered_map>
using namespace std;

char tmp[300005];

int to_num(char c) {
    return c - 'a';
}
int d[300005];
int n = 0;
class AhoCorasick {
    public:
        unordered_map<char,int> trie[300005];
        int fail[300005];
        int lv[300005];
        int piv;

        AhoCorasick() {
            for(int i=0; i<300005; i++) {
                fail[i] = lv[i] = 0;
            }
            piv = 0;
        }
        ~AhoCorasick() {
        }

        void insertWord(string w) {
            int cur = 0;
            for(int i=0; i<w.size(); i++) {
                int next = to_num(w[i]);
                if(trie[cur].find(next) == trie[cur].end()) trie[cur][next] = ++piv;
                cur = trie[cur][next];
            }
            lv[cur] = w.size();
        }

        void make_failFunc() {
            queue<int> q;
            q.push(0);
            while(!q.empty()) {
                int cur = q.front(); q.pop();
                for(auto it = trie[cur].begin(); it != trie[cur].end(); it++) {
                    int next = it->second;
                    int i = it->first;
                    if(cur == 0) fail[next] = 0;
                    else {
                        int f = fail[cur];
                        while(f && trie[f].find(i) == trie[f].end()) {
                            f = fail[f];
                        }
                        if(trie[f].find(i) != trie[f].end()) f = trie[f][i];
                        fail[next] = f;
                    }
                    if(lv[fail[next]]) lv[next] = max(lv[next], lv[fail[next]]);
                    q.push(next);
                }
            }
        }
        int solve(string s) {
            int cur = 0;
            for(int i=0; i<s.size(); i++) {
                int next = to_num(s[i]);
                while(cur && trie[cur].find(next) == trie[cur].end()) {
                    cur = fail[cur];
                }
                if(trie[cur].find(next) != trie[cur].end() ) cur = trie[cur][next];
                if(lv[cur]) {
                    int len = lv[cur];
                    d[i + 1] = min(d[i+1], d[i+1 - len] + 1);
                    for(int j=i; j>=i+1-len; j--) {
                        if(d[j+1] < d[j]) d[j] = d[j+1];
                        else break;
                    }
                }
            }
            return d[s.size()];
        }
};

AhoCorasick* ac = new AhoCorasick();

int main() {
    for(int i=1; i<300005; i++) d[i] = 999999999;
    string A, B;
    int N; scanf("%d", &N);
    
    scanf("%s", tmp); A = tmp;
    while(N--) {
        scanf("%s", tmp); B = tmp;
        ac->insertWord(B);
    }
    ac->make_failFunc();
    int ans = ac->solve(A);
    printf("%d", ans != 999999999 ? ans : -1);
    delete ac;
}