//# Author : nuclear852 ========================#
//# Solution : 25097515 ========================#
//# Time Stamp : 2021-01-09 22:38:56 ===========#
//# Problem Title : 문자열의 주기 예측 =============#
//# Language : C++17 ===========================#

#include <stdio.h>
#include <string>
#include <algorithm>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll f[1000005];
ll dy[1000005];
string S;

void make_failFunc() {
    int j = 0;
    for(int i = 1; i < S.size(); i++) {
        while(j > 0 && S[i] != S[j]) {
            j= f[j-1];
        }
        if(S[i] == S[j]) {
            f[i] = ++j;
        }
    }
}

ll d(int c) {
    if(c < 0) return INF;
    if(dy[c] != -1) return dy[c];
    if(f[c] == 0) return INF;
    return dy[c] = min(f[c], d(f[c]-1));
}


int main() {
    char tmp[1000005];
    int N;
    scanf("%d", &N);
    scanf("%s", tmp);
    S = tmp;
    for(int i=0; i<1000005; i++) dy[i] = -1;
    make_failFunc();
    ll ans = 0;
    for(int i=0; i<N; i++) {
        ll nxt = d(i);
        if (nxt < INF) ans += i - nxt + 1;
    }
    printf("%lld", ans);
}