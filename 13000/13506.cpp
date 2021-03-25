//# Author : nuclear852 ========================#
//# Solution : 25107299 ========================#
//# Time Stamp : 2021-01-10 09:43:06 ===========#
//# Problem Title : 카멜레온 부분 문자열 ============#
//# Language : C++17 ===========================#

#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int f[1000005];

vector<int> make_failFunc(string P) {
    vector<int> f(P.size(), 0);

    int j = 0;
    for(int i=1; i<P.size(); i++) {
        while(j > 0 && P[i] != P[j]) j = f[j-1];
        if(P[i] == P[j]) f[i] = ++j;
    }
    return f;
}

bool KMP(string S, string P) {
    int ans = 0;
    int j = 0;
    vector<int> f = make_failFunc(P);
    for(int i = 0; i < S.size(); i++) {
        while(j>0 && S[i] != P[j]) j = f[j-1];
        if(S[i] == P[j]) {
            ++j;
            if(j == P.size()) {
                ans++;
                j = f[j-1];
            }
        }
    }
    if(ans >= 3) {
        return true;
    }
    return false;
}

int main() {
    char tmp[1000005];
    string t;
    scanf("%s", tmp);
    t = tmp;
    auto PS = make_failFunc(t);
    int ans = -1;
    string ans_s;
    int idx = t.size()-1;

    while(idx > 0 && PS[idx] > 0) {
        string ref = "";
        for(int i=0; i<PS[idx]; i++) ref += t[i];
        if(KMP(t, ref)) {
            if(PS[idx] > ans) {
                ans_s = ref;
                ans = PS[idx];
                break;
            }
        }
        idx = PS[idx-1];
    }
    if(ans == -1)
        printf("%d", ans);
    else
        printf("%s", ans_s.c_str());
    
}