//# Author : nuclear852 ========================#
//# Solution : 25394629 ========================#
//# Time Stamp : 2021-01-18 15:25:40 ===========#
//# Problem Title : 단어 퍼즐 ==================#
//# Language : C++17 ===========================#

#include <stdio.h>
#include <string>
#include <utility>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;

pair<pair<int, int>, int> ans[1001];
int word_size[1001];


int to_num(char c) {
    return c - 'A';
}

class Trie{
    public:
        Trie* go[26];
        Trie* fail;
        vector<int> isTerm;

        Trie() {
            for(int i=0; i<26; i++) {
                go[i] = nullptr;
            }
        }
        ~Trie() {
            for(int i=0; i<26; i++) {
                if(go[i] != nullptr) delete go[i];
            }
        }

        void insert(string str, int idx, int sidx){ 
            if(str.size() == idx) {
                isTerm.push_back(sidx);
                return;
            }
            int path = to_num(str[idx]);
            if(go[path] == nullptr) {
                go[path] = new Trie();
            }
            go[path]->insert(str, idx+1, sidx);
        }
};

class AhoCorasick{
    private:
        Trie* root;
    
    public:
        AhoCorasick() {
            root = new Trie();
        }
        void insert(string str, int sidx) {
            root->insert(str, 0, sidx);
            return;
        }
        void make_failFunc() {
            queue<Trie* > q; q.push(root);
            while(!q.empty()) {
                Trie* cur = q.front(); q.pop();
                for(int path=0; path<26; path++) {
                    if(cur->go[path] == nullptr) continue;

                    Trie* next = cur->go[path];
                    if(cur == root) {
                        next->fail = root;
                    }
                    else {
                        Trie* f = cur->fail;
                        while(f != root && f->go[path] == nullptr) f = f->fail;
                        if(f->go[path] != nullptr) f = f->go[path];
                        next->fail = f;
                    }

                    if(next->fail->isTerm.size()) {
                        for(auto val: next->fail->isTerm) {
                            next->isTerm.push_back(val);
                        }
                    }
                    q.push(next);
                }
            }
        }
        void solve(string s, int ix, int iy, int dir) {
            Trie* cur = root;
            for(int i=0; i<s.size(); i++) {
                int path = to_num(s[i]);
                while(cur != root && cur->go[path] == nullptr) cur = cur->fail;
                if(cur->go[path]!=nullptr) cur = cur->go[path];
                if(cur->isTerm.size()) {
                    for(auto val: cur->isTerm) {
                        if(dir == 0) {
                            ans[val] = min(ans[val], {{ix-i+word_size[val], iy}, dir});
                        }
                        if(dir == 1) {
                            ans[val] = min(ans[val], {{ix-i+word_size[val], iy+i-word_size[val]}, dir});
                        }
                        if(dir == 2) {
                            ans[val] = min(ans[val], {{ix, iy+i-word_size[val]}, dir});
                        }
                        if(dir == 3) {
                            ans[val] = min(ans[val], {{ix+i-word_size[val], iy+i-word_size[val]}, dir});
                        }
                        if(dir == 4) {
                            ans[val] = min(ans[val], {{ix+i-word_size[val], iy}, dir});
                        }
                        if(dir == 5) {
                            ans[val] = min(ans[val], {{ix+i-word_size[val], iy-i+word_size[val]}, dir});
                        }
                        if(dir == 6) {
                            ans[val] = min(ans[val], {{ix, iy-i+word_size[val]}, dir});
                        }
                        if(dir == 7) {
                            ans[val] = min(ans[val], {{ix-i+word_size[val], iy-i+word_size[val]}, dir});
                        }

                    }
                }
            }

        }
};

AhoCorasick *ac = new AhoCorasick();
char map[1002][1002];
char tmp[1002];
int L, C, W;

int main() {
    scanf("%d%d%d", &L, &C, &W);
    for(int i=0; i<L; i++) scanf("%s", map[i]);
    for(int i=0; i<W; i++) {
        ans[i].first.first = ans[i].first.second = ans[i].second = 999999999;
    }
    for(int i=0; i<W; i++) {
        scanf("%s", tmp); string str = tmp;
        word_size[i] = str.size()-1;
        ac->insert(str, i);
    }
    ac->make_failFunc();
    //A

    for(int i=0; i<C; i++) {
        string s = "";
        for(int j=L-1; j>=0; j--) {
            s += map[j][i];
        }
        ac->solve(s, L-1, i, 0);
    }
    //E
    for(int i=0; i<C; i++) {
        string s = "";
        for(int j=0; j<L; j++) {
            s += map[j][i];
        }
        ac->solve(s, 0, i, 4);
    }
    //B
    for(int i=0; i<=(L+C-2); i++) {
        string s = "";
        int x, y;
        if(i <= L-1) {
            x = i;
            y = 0;
            for(int j=x; j>=0; j--) {
                s += map[j][y];
                y++;
            }
            ac->solve(s, i, 0, 1);
        }
        else {
            x = L-1;
            y = i-L+1;
            for(int j=y; j<=C-1; j++) {
                s += map[x][j];
                x--;
            }
            ac->solve(s, L-1, i-L+1, 1);
        }
    }
    //F
    for(int i=0; i<=(L+C-2); i++) {
        string s = "";
        int x, y;
        if(i <= C-1) {
            x = 0;
            y = i;
            for(int j=y; j>=0; j--) {
                s += map[x][j];
                x++;
            }
            ac->solve(s, 0, i, 5);
        }
        else {
            x = i-C+1;
            y = C-1;
            for(int j=x; j<=L-1; j++) {
                s += map[j][y];
                y--;
            }
            ac->solve(s, i-C+1, C-1, 5);
        }
    }
    //C
    for(int i=0; i<L; i++) {
        string s = "";
        for(int j=0; j<C; j++) {
            s += map[i][j];
        }
        ac->solve(s, i, 0, 2);
    }
    //G
    for(int i=0; i<L; i++) {
        string s = "";
        for(int j=C-1; j>=0; j--) {
            s += map[i][j];
        }
        ac->solve(s, i, C-1, 6);
    }
    //D
    for(int i=0; i<=(L+C-2); i++) {
        string s = "";
        int x, y;
        if(L-1-i >= 0) {
            x = L-1-i;
            y = 0;
            for(int j=x; j<L; j++) {
                s += map[j][y];
                y++;
            }
            ac->solve(s, L-1-i, 0, 3);
        }
        else {
            x = 0;
            y = i - (L-1);
            for(int j=y; j<C; j++) {
                s += map[x][j];
                x++;
            }
            ac->solve(s, 0, i-(L-1), 3);
        }
    }
    //H
    for(int i=0; i<=(L+C-2); i++) {
        string s = "";
        int x, y;
        if(i<=C-1) {
            x = L-1;
            y = i;
            for(int j=y; j>=0; j--) {
                s += map[x][j];
                x--;
            }
            ac->solve(s, L-1, i, 7);
        }
        else {
            x = L+C-2-i;
            y = C-1;
            for(int j=x; j>=0; j--) {
                s += map[j][y];
                y--;
            }
            ac->solve(s, L+C-2-i, C-1, 7);
        }
    }

    for(int i=0; i<W; i++) {
        printf("%d %d %c\n", ans[i].first.first, ans[i].first.second, ans[i].second + 'A');
    }

    delete ac;
}