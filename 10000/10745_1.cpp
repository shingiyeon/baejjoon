//# Author : nuclear852 ========================#
//# Solution : 25264455 ========================#
//# Time Stamp : 2021-01-14 14:56:10 ===========#
//# Problem Title : Censoring ==============#
//# Language : C++17 ===========================#

#include <stdio.h>
#include <string>
#include <queue>
#include <stack>
#include <vector>
#include <utility>

using namespace std;
typedef pair<int, int> p;

int d[100005];

class AhoCorasick {
    public:
    int trie[100005][26];
    int fail[100005];
    int lv[100005];
    int d[100005][26];
    int p[100005];
    int idx;

    AhoCorasick() {
        for(int i = 0; i < 100005; i++) {
            for(int j = 0; j < 26; j++) {
                trie[i][j] = 0;
                d[i][j] = -1;
            }
            fail[i] = lv[i] = 0;
            idx = 0;
        }
    }

    static int to_num(char c) {
        return c - 'a';
    }

    void insert(string s) {
        int cur = 0;
        for(int i = 0; i < s.size(); i++) {
            int next = to_num(s[i]);
            if(!trie[cur][next]) trie[cur][next] = ++idx;
            cur = trie[cur][next];
        }
        lv[cur] = s.size();
    }

    void make_failFunc() {
        queue<int> q; q.push(0);
        while(!q.empty()) {
            int cur = q.front(); q.pop();
            for(int i=0; i<26; i++) {
                if(!trie[cur][i]) continue;
                int next = trie[cur][i];
                if(cur == 0) {
                    fail[next] = 0;
                }
                else {
                    int f = fail[cur];
                    while(f && !trie[f][i]) f = fail[f];
                    if(trie[f][i]) f = trie[f][i];
                    fail[next] = f;
                }
                if(lv[fail[next]]) lv[next] = max(lv[next], lv[fail[next]]);
                q.push(next);
            }
        }
    }

    vector<int> solve(string s) {
        vector<int> v;
        v.reserve(400005);
        int cur = 0;
        int n = 0, k = 0, g = 0; long long total_f = 0;
        for(int i = 0; i<s.size(); i++) {
            int next = to_num(s[i]);
            int ori_cur = cur;
            if(d[cur][next] != -1) cur = d[cur][next];
            
            while(cur && !trie[cur][next]) {
                cur = fail[cur];
            }
            if(trie[cur][next]) cur = trie[cur][next];
            p[i] = cur;

            v.push_back(i);
            if(lv[cur]) { 
                for(int j=1; j<=lv[cur]; j++) {
                    v.pop_back();
                }
                if(v.empty()) {
                    cur = 0;
                }
                else {
                    if(!trie[ori_cur][next] && d[ori_cur][next] == -1) d[ori_cur][next] = cur;
                    cur = p[v.back()];
                }
            }
        }
        return v; 
    }
};
char tmp[100005];
string A, B;
AhoCorasick* ac = new AhoCorasick();
int main() {
    
    scanf("%s", tmp); A = tmp;
    int N; scanf("%d", &N);
    while(N--) {
        scanf("%s", tmp); B = tmp;
        ac->insert(B);
    }
    ac->make_failFunc();
    auto v = ac->solve(A);
    string ans = "";
    for(auto c : v) {
        ans += A[c];
    }
    printf("%s", ans.c_str());
    delete ac;
}