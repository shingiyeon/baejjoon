//# Author : nuclear852 ========================#
//# Solution : 25147771 ========================#
//# Time Stamp : 2021-01-11 14:57:11 ===========#
//# Problem Title : 마법의 단어 =================#
//# Language : C++17 ===========================#

#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

int N, K;
string str[8];

vector<int> make_failFunc(string S) {
    vector<int> f(S.size(), 0);
    int j = 0;
    for(int i = 1; i < S.size(); i++) {
        while(j > 0 && S[i] != S[j]) j = f[j-1];
        if(S[i] == S[j]) f[i] = ++j;
    }
    return f;
}

bool KMP(string S) {
    vector<int> f = make_failFunc(S);
    string P = S;
    int size = S.size();
    for(int i = 0; i < size; i++) {
        P += S[i];
    }
    
    int ans = 0;
    int j = 0;
    for(int i = 0 ; i < P.size(); i++) {
        while(j > 0 && P[i] != S[j]) j = f[j-1];
        if(P[i] == S[j]) {
            ++j;
            if(j == S.size()) {
                if(i - S.size() + 1 < S.size() ) ans++;
                j = f[j-1];
            }
        }
    } 

    if(ans == K) return true;
    return false;
}

int permutation(int path, int number, string S) {
    int ans = 0;
    if(number == N) {
        return KMP(S);
    }
    for(int i = 0; i < N; i++) {
        int tmp = (1<<i);
        if( (path | tmp) == path) continue;
        ans += permutation(path | tmp, number + 1, S + str[i]);
    }
    return ans;
}

int main() {
    scanf("%d", &N);
    char tmp[25];
    for(int i = 0; i < N; i++) {
        scanf("%s", tmp);
        str[i] = tmp;
    }
    scanf("%d", &K);
    printf("%d", permutation(0, 0, ""));
}