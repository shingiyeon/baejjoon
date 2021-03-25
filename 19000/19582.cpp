//# Author : nuclear852 ========================#
//# Solution : 22856714 ========================#
//# Time Stamp : 2020-09-26 22:59:57 ===========#
//# Problem Title : 200년간 폐관수련했더니 PS 최강자가 된 건에 대하여 #
//# Language : C++14 ===========================#

#include <stdio.h>
#include <algorithm>
#define MAX 1000000000000000
using namespace std;

struct contest{
    int r, g;
}C[100001];

int N;
long long dy[100001][2];

int main() {
    scanf("%d", &N);
    for(int i=1; i<=N; i++) scanf("%d%d", &C[i].r, &C[i].g);

    for(int i=1; i<=N; i++) {
        for(int j=0; j<=1; j++)
            dy[i][j] = MAX;
    }

    dy[1][0] = C[1].g;
    dy[1][1] = 0;
    //printf("%lld %lld\n", dy[1][0], dy[1][1]);
    
    for(int i=2; i<=N; i++) {
        if(C[i].r >= dy[i-1][0] && dy[i-1][0] != -1) {
            dy[i][0] = dy[i-1][0] + (long long)C[i].g;
        }
        else {
            dy[i][0] = -1;
        }

        if(dy[i-1][0] != -1) {
            dy[i][1] = min(dy[i][1], dy[i-1][0]);
        }
        if(C[i].r >= dy[i-1][1] && dy[i-1][1] != -1) {
            dy[i][1] = min(dy[i][1], (long long)C[i].g + dy[i-1][1]);
        }
        if (dy[i][1] == MAX) dy[i][1] = -1;
        //printf("%lld %lld\n", dy[i][0], dy[i][1]);
    }

    if(dy[N-1][0] != -1 || dy[N][1] != -1) {
        printf("Kkeo-eok");
    }
    else {
        printf("Zzz");
    }
}