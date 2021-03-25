//# Author : nuclear852 ========================#
//# Solution : 25187923 ========================#
//# Time Stamp : 2021-01-12 14:28:07 ===========#
//# Problem Title : 돌연변이 ===================#
//# Language : C++17 ===========================#

#include <stdio.h>
#include <string>
#include <queue>

using namespace std;


class Trie{
    private:
        Trie* go[4];
        Trie* fail;
        long long numOfTerminal;
        bool root;
    
    public:
        Trie(bool _root = false) {
            for(int i = 0; i < 4; i++) {
                go[i] = NULL;
            }
            numOfTerminal = 0;
            root = _root;
            fail = NULL;
        }

        ~Trie() {
            for(int i = 0 ; i < 4; i++) {
                if(go[i] != NULL)
                    delete go[i];
            }
        }

        Trie* getGo(int i) {
            return go[i];
        }

        Trie* getFail() {
            return fail;
        }

        void setFail(Trie* _fail) {
            fail = _fail;
        }

        bool isRoot() {
            return root;
        }

        long long getNumOfTerminal() {
            return numOfTerminal;
        }

        void addNumOfTerminal(long long _numOfTerminal) {
            numOfTerminal += _numOfTerminal;
        }

        static int to_num(char c) {
            if(c=='A') return 0;
            else if(c=='G') return 1;
            else if(c=='T') return 2;
            else return 3; //C
        }

        void insert(string word, int n) {
            if(n == word.size()) {
                numOfTerminal = 1;
                return;
            }
            int next = to_num(word[n]);
            if(go[next] == NULL) {
                go[next] = new Trie();
            }
            go[next]->insert(word, n+1);
        }
};


class aho_corasick {
    private:
        Trie* root;
        

    public:
        aho_corasick() {
            root = new Trie(true);
        }

        ~aho_corasick() {
            delete root;
        }

        void insert(string word) {
            root->insert(word, 0);
        }

        void make_failFunc() {
            queue<Trie*> q;
            q.push(root);

            while(!q.empty()) {
                Trie* cur = q.front(); q.pop();
                for(int i = 0; i < 4; i++) {
                    Trie* next = cur->getGo(i);
                    if(next == NULL) continue;
                    if(cur == root) next->setFail(root);
                    else {
                        Trie* fail = cur->getFail();
                        while(fail != root && fail->getGo(i) == NULL) {
                            fail = fail->getFail();
                        }
                        if(fail->getGo(i)) fail = fail->getGo(i);
                        next->setFail(fail);
                    }
                    next->addNumOfTerminal(next->getFail()->getNumOfTerminal());
                    q.push(next);
                }
            }
            return;
        }

        long long solve(string word) {
            long long ans = 0;
            Trie* cur = root;
            for(int i = 0 ; i < word.size(); i++) {
                int next  = Trie::to_num(word[i]);
                while(cur != root && cur->getGo(next)==NULL) {
                    cur = cur->getFail();
                }
                if(cur->getGo(next)) {
                    cur = cur->getGo(next);
                }
                ans += cur->getNumOfTerminal();
            }
            return ans;
        }
};

char str[1000005];
char mark[105];

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        int n, m; scanf("%d%d", &n, &m);
        scanf("%s%s", str, mark);
        string a = str, b = mark;

        aho_corasick* ac = new aho_corasick;
        for(int i=0; i<b.size(); i++) {
            for(int j=i+1; j<b.size()+1; j++) {
                string tmp = "";
                for(int k=0; k<i; k++) tmp += b[k];
                for(int k=j-1; k>=i; k--) tmp += b[k];
                for(int k=j; k<b.size(); k++) tmp += b[k];
                ac->insert(tmp);
            }
        }
        ac->make_failFunc();
        printf("%lld\n", ac->solve(a));
        delete ac;
    }
}