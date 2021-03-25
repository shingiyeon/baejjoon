//# Author : nuclear852 ========================#
//# Solution : 25267990 ========================#
//# Time Stamp : 2021-01-14 16:20:38 ===========#
//# Problem Title : 빅 픽쳐 ===================#
//# Language : C++17 ===========================#

#include <stdio.h>
#include <map>
#include <string>
#include <queue>
#include <vector>
#include <utility>
using namespace std;

map<string, int> m;
int numMap[2002][2002];
int m_idx = 0;

class KMP {
    public:
    int f[2002];
    
    KMP() {
        for(int i=0; i<2002; i++) f[i] = 0;
    }

    void make_failFunc(vector<int> s) {
        int j = 0;
        for(int i = 1; i < s.size(); i++) {
            while(j && s[i] != s[j]) j = f[j-1];
            if(s[i] == s[j]) f[i] = ++j;
        }
    }

    int solve(vector<int> p, vector<int> s) {
        int ans = 0;
        int j = 0;
        for(int i = 0; i < p.size(); i++) {
            while(j && p[i] != s[j]) j = f[j-1];
            if(p[i] == s[j]) {
                ++j;
                if(j == s.size()) {
                    ans++;
                    j = f[j-1];
                }
            }
        }
        return ans;
    }  
};


class ahocorasick{
    public:
    int trie[4000004][2];
    int fail[4000004];
    int isTerm[4000004];
    int idx;

    ahocorasick() {
        for(int i=0; i<4000004; i++) {
            trie[i][0] = trie[i][1] = 0;
            fail[i] = 0;
            isTerm[i] = 0;
        }
        idx = 0;
    }

    static int to_num(char c) {
        return c == 'o' ? 0 : 1;
    }

    void insert(string a) {
        int cur = 0;
        for(int i=0; i<a.size(); i++) {
            int next = to_num(a[i]);
            if(!trie[cur][next]) trie[cur][next] = ++idx;
            cur = trie[cur][next];
        }
        isTerm[cur] = m[a];
    }

    void make_failFunc() {
        queue<int> q; q.push(0);
        while(!q.empty()) {
            int cur = q.front(); q.pop();
            for(int i=0; i<2; i++) {
                if(!trie[cur][i]) continue;
                int next = trie[cur][i];
                if(cur == 0) fail[next] = 0;
                else {
                    int f = fail[cur];
                    while(f && !trie[f][i]) f = fail[f];
                    if(trie[f][i]) f = trie[f][i];
                    fail[next] = f;
                }
                if(isTerm[fail[next]]) isTerm[next] = isTerm[fail[next]];
                q.push(next);
            }
        }
    }

    vector<pair<int, int> > solve(string s) {
        vector<pair<int, int> > v;
        int cur = 0;
        for(int i = 0; i < s.size(); i++) {
            int next = to_num(s[i]);
            while(cur && !trie[cur][next]) cur = fail[cur];
            if(trie[cur][next]) cur = trie[cur][next];
            if(isTerm[cur]) {
                v.push_back({i, isTerm[cur]});
            }
        }
        return v;
    }
};

ahocorasick* ac = new ahocorasick();
KMP* kmp = new KMP();
int main() {
    int a, b, c, d;
    char tmp[2002];
    vector<int> ans_v;
    scanf("%d%d%d%d", &a, &b, &c, &d);
    for(int i=0; i<a; i++) {
        scanf("%s", tmp);
        string A = tmp;
        if(m.find(A) == m.end()) {
            m[A] = ++m_idx;
        }
        ans_v.push_back(m[A]);
        ac->insert(A);
    }
    ac->make_failFunc();

    for(int i=0; i<c; i++) {
        scanf("%s", tmp);
        string A = tmp;
        auto v = ac->solve(A);
        for(auto val: v) {
            numMap[i][val.first] = val.second;
        }
    }

    kmp->make_failFunc(ans_v);
    int ans = 0;
    for(int i=0; i<d; i++) {
        vector<int> input;
        for(int j=0; j<c; j++) {
            input.push_back(numMap[j][i]);
        }
        ans += kmp->solve(input, ans_v);
    }
    printf("%d", ans);
    delete ac;
    delete kmp;
}