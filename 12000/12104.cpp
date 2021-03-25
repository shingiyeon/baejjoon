//# Author : nuclear852 ========================#
//# Solution : 25129204 ========================#
//# Time Stamp : 2021-01-10 22:18:52 ===========#
//# Problem Title : 순환 순열 ==================#
//# Language : C++17 ===========================#

#include <stdio.h>
#include <string>
#include <vector>
using namespace std;

vector<int> make_failFunc(string S) {
    vector<int> f(S.size(), 0);
    int j = 0;
    for(int i = 1; i < S.size() ; i++) {
        while(j > 0 && S[i] != S[j]) j = f[j-1];
        if(S[i] == S[j]) f[i] = ++j;
    }
    return f;
}

int KMP(string P, string S) {
    int ans = 0;
    auto f = make_failFunc(S);
    int j = 0;
    for(int i = 0 ; i < P.size(); i++) {
        while(j > 0 && P[i] != S[j]) j = f[j-1];
        if(P[i] == S[j]) {
            ++j;
            if(j == S.size()) {
                if(i - S.size() + 1 < P.size() / 2 ){
                    ans++;
                }
                j = f[j-1];
            }
        }
    }
    return ans;
}

int main() {
    char tmp[100005];
    string P, S;
    scanf("%s", tmp);
    P = tmp;
    scanf("%s", tmp);
    S = tmp;
    int size = S.size();
    for(int i = 0; i < size; i++) {
        S += S[i];
    }
    printf("%d", KMP(S, P));
}