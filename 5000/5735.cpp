//# Author : nuclear852 ========================#
//# Solution : 25348955 ========================#
//# Time Stamp : 2021-01-16 23:35:53 ===========#
//# Problem Title : Emoticons :-) ==========#
//# Language : C++17 ===========================#

#include <iostream>
#include <stdio.h>
#include <string>
#include <unordered_map>
#include <queue>
using namespace std;


unordered_map<char, int> to_num;

void make_dic() {
    int idx = 0;
    to_num[' '] = idx++;
    string str = "!?.,:;-_'#$%&/=*+(){}[]";
    for(char a = 'a'; a <= 'z'; a++) {
        to_num[a] = idx++;
    }
    for(char a = 'A'; a <= 'Z'; a++) {
        to_num[a] = idx++;
    }
    for(char a = '0'; a <= '9'; a++) {
        to_num[a] = idx++;
    }
    for(int i=0; i<str.size(); i++) {
        to_num[str[i]] = idx++;
    }
}

class Trie{
    public:
        unordered_map<char, Trie*> go;
        Trie* fail;
        bool isTerm;

        void insert(string str, int idx) {
            if(idx == str.size()) {
                isTerm = true;
                return;
            }
            int path = to_num[str[idx]];
            if(go.find(path) == go.end()) {
                go[path] = new Trie();
            }
            go[path]->insert(str, idx+1);
            return;
        }
};

class AhoCorasick {
    private:
        Trie* root;
    
    public:
        AhoCorasick() {
            root = new Trie();
        }
        ~AhoCorasick() {
            delete root;
        }
        void insert(string str) {
            root->insert(str, 0);
            return;
        }
        void make_failFunc() {
            queue<Trie*> q; q.push(root);
            while(!q.empty()) {
                Trie* cur = q.front(); q.pop();
                for(auto it = cur->go.begin(); it != cur->go.end(); it++) {
                    int path = it->first;
                    Trie* next = it->second;
                    if(cur == root) {
                        next->fail = root;
                    }
                    else {
                        Trie* f = cur->fail;
                        while(f != root && f->go.find(path) == f->go.end()) {
                            f = f->fail;
                        }
                        if(f->go.find(path) != f->go.end()) f = f->go[path];
                        next->fail = f;
                    }
                    if(next->fail->isTerm) {
                        next->isTerm = next->fail->isTerm;
                    }
                    q.push(next);
                } 
            }
        }

        int solve(string s) {
            int tmp_ans = 0;
            Trie* cur = root;
            for(int i=0; i<s.size(); i++) {
                int path = to_num[s[i]];
                while(cur != root && cur->go.find(path) == cur->go.end()) cur = cur->fail;
                if(cur->go.find(path) != cur->go.end()) cur = cur->go[path];
                if(cur->isTerm) {
                    tmp_ans++;
                    cur = root;
                }
            }
            return tmp_ans;
        }

};

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);
    make_dic();
    int N, M;
    cin >> N >> M;
    while(N != 0 && M != 0) {
        AhoCorasick* ac = new AhoCorasick();
        string A, B;
        int ans = 0;
        for(int i=0; i<=N; i++) {
            getline(cin, A);
            if(i == 0) continue;
            ac->insert(A);
        }
        ac->make_failFunc();
        for(int j=0; j<M; j++) {
            getline(cin, B);
            ans += ac->solve(B);
        }
        delete ac;
        printf("%d\n", ans);
        cin >> N >> M;
    }

}