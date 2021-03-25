//# Author : nuclear852 ========================#
//# Solution : 25631362 ========================#
//# Time Stamp : 2021-01-24 23:27:46 ===========#
//# Problem Title : 평범한 배낭 2 ===============#
//# Language : C++17 ===========================#

#include <stdio.h>
#include <algorithm>
using namespace std;
typedef long long ll;

struct goods {
    int V, C;
}G[10005];

int idx = 0;
int dy[10005][10005];

int N, M;
int d(int num, int val) {
    if(dy[num][val] != -1) return dy[num][val];
    if(num >= idx) { 
        return 0;
    }
    dy[num][val] = d(num + 1, val);
    if(val >= G[num].V) {
        dy[num][val] = max(dy[num][val], d(num + 1, val - G[num].V) + G[num].C);
    }
    return dy[num][val];
}

int main() {
    scanf("%d%d", &N, &M);
    for(int i=0; i<10005; i++) {
        for(int j=0; j<10005; j++) dy[i][j] = -1;
    }
    for(int i=0; i<N; i++) {
        int p = 1;
        int V, C, K;
        scanf("%d%d%d", &V, &C, &K);
        while(K) {
            if(p <= K) {
                G[idx].V = p*V;
                G[idx].C = p*C;
                K -= p;
                p *= 2;
            }
            else {
                G[idx].V = K*V;
                G[idx].C = K*C;
                K = 0;
            }
            idx++;
        }
        if(K) {
            G[idx].V = K*V;
            G[idx].C = K*C;
            idx++;
        }
    }
    printf("%d", d(0, M));
}