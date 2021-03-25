//# Author : nuclear852 ========================#
//# Solution : 25151462 ========================#
//# Time Stamp : 2021-01-11 16:16:23 ===========#
//# Problem Title : 휴대폰 자판 =================#
//# Language : C++17 ===========================#

#include <stdio.h>
#include <string>

using namespace std;

class Trie{
    private:
        Trie* children[26];
        bool autoButton;
        int pathNum;
        bool isTerminal;
        bool isRoot;

    public:
        Trie(bool _isRoot) {
            for(int i = 0; i < 26; i++) {
                children[i] = NULL;
            }
            autoButton = false;
            pathNum = 0;
            isTerminal = false;
            isRoot = _isRoot;
        }
        ~Trie() {
            for(int i = 0; i < 26; i++) {
                if(children[i] != NULL)
                    delete children[i];
            }
        }

        static int to_num(char c) {
            return c - 'a';
        }

        void insert(const char* words) {
            if(*words == '\0') {
                isTerminal = true;
                autoButton = false;
                return;
            }
            int next = to_num(*words);
            if(children[next] == NULL) {
                children[next] = new Trie(false);
                pathNum++;
                if(!isTerminal && pathNum == 1) autoButton = true;
                if(pathNum > 1) autoButton = false;
            }

            children[next]->insert(words + 1);
        }

        int find(const char* words) {
            int next = to_num(*words);
            if(*words == '\0') {
                return 0;
            }
            if(autoButton == true && isRoot == false) return children[next]->find(words+1);
            return (children[next]->find(words+1)) + 1;
        }
};

char str[100001][86];
int main() {
    int N;
    scanf("%d", &N);
    while(scanf("%d", &N) != EOF) {
        Trie head(true);
        for(int i = 0; i < N; i++) {
            scanf("%s", str[i]);
            head.insert(str[i]);
        }
        long long count = 0;
        for(int i = 0 ; i < N; i++) {
            long long tmp = (long long)head.find(str[i]);
            count += tmp;
        }

        printf("%.2f\n", (double) count / N);
    }
}