//# Author : nuclear852 ========================#
//# Solution : 26532419 ========================#
//# Time Stamp : 2021-02-19 14:58:31 ===========#
//# Problem Title : Messi An-Gimossi =======#
//# Language : C++17 ===========================#

#include <iostream>
#define MOD 1000000007
typedef long long ll;
using namespace std;
const int RANGE = 1e7 + 1;
ll A[RANGE], B[RANGE];
int pn, spf[RANGE], pr[RANGE];
int N;

ll pow(ll val, int p) {
    ll A = 1;
    while(p) {
        if(p % 2) { 
            A = (A * val) % MOD;
            p -= 1;
        }
        val = (val * val) % MOD;
        p /= 2;
    }
    return A;
}

void f(ll x, bool isA) {
    if (isA) {
        while(x > 1) {
            A[spf[x]]++;
            x /= spf[x];
        }
    }
    else{
        while(x > 1) {
            B[spf[x]]++;
            x /= spf[x];
        }
    }
}

int main() {
    cin.tie(NULL); ios::sync_with_stdio(false);
    ll a = 1, b = 1;
    for(int i=2; i<RANGE; i++) {
        if(!spf[i]) spf[i] = pr[pn++] = i;
        for(int j = 0; i*pr[j] < RANGE; j++) {
            spf[i*pr[j]] = pr[j];
            if(i % pr[j] == 0) break;
        } 
    }
    cin >> N;
    while(N--) {
        ll ta, tb; cin >> ta >> tb;
        f(tb-ta, true); f(tb, false);
    }
    for(int i=2; i<RANGE; i++) {
        ll mv = min(A[i], B[i]);
        if(A[i] == 0 && B[i] == 0) continue;
        A[i] -= mv; B[i] -= mv;
        a = (a * pow(i, A[i])) % MOD;
        b = (b * pow(i, B[i])) % MOD;
    }
    cout << a << " " << b;
}