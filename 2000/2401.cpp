//# Author : nuclear852 ========================#
//# Solution : 25131799 ========================#
//# Time Stamp : 2021-01-10 23:22:34 ===========#
//# Problem Title : 최대 문자열 붙여넣기 ============#
//# Language : C++17 ===========================#

#include <stdio.h>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int dy[100001];

vector<int> make_failFunc(string S) {
    vector<int> f(S.size(), 0);
    int j = 0;
    for(int i = 1; i < S.size(); i++) {
        while( j > 0 && S[i] != S[j]) j = f[j-1];
        if(S[i] == S[j]) f[i] = ++j;
    }
    return f;
}

void KMP(string P, vector<string> S, vector<vector<int> > f) {
    int j = 0;
    int mem[505];
    for(int i = 0; i < S.size(); i++) mem[i] = 0;

    for(int i = 0; i < P.size(); i++) {
        if(i > 0) dy[i] = dy[i-1];
        for(int j = 0; j < S.size(); j++) {
            int &idx = mem[j];
            while(idx > 0 && P[i] != S[j][idx]) idx = f[j][idx-1];
            if(P[i] == S[j][idx]) {
                ++idx;
                if(idx == S[j].size()) {
                    if(i>=S.size()) dy[i] = max(dy[i], dy[i-S[j].size()] + (int)S[j].size());
                    else dy[i] = max(dy[i], (int)S[j].size());
                    idx = f[j][idx-1];
                }
            }
        }
    }
}

int main() {
    string P, S; int N;
    char tmp[100001];
    scanf("%s", tmp);
    P = tmp;
    scanf("%d", &N);
    vector<vector<int> > fail;
    vector<string> vS;
    while(N--) {
        scanf("%s", tmp);
        S = tmp;
        vS.push_back(S);
        fail.push_back(make_failFunc(S));
    }
    KMP(P, vS, fail);
    printf("%d", dy[P.size()-1]);


}