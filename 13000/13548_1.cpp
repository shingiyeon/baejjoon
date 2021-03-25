//# Author : nuclear852 ========================#
//# Solution : 23330131 ========================#
//# Time Stamp : 2020-10-18 22:59:47 ===========#
//# Problem Title : 수열과 쿼리 6 ===============#
//# Language : C++14 ===========================#

#include <stdio.h>
#include <math.h>
#include <algorithm>

using namespace std;
int N, M, C;
int cnt[101010];
int arr[101010];
int ans[101010];

int bket[101010];
int Sbket[101010];
int sq;
int now = 0;

struct query {
    int left, right, index;
} Q[101010];

bool cmp(const query& a, const query& b) {
    int aSR = a.right / sq;
    int bSR = b.right / sq;
    
    return aSR == bSR ? a.left < b.left : aSR < bSR;
}

void f(int index, bool add) {
    Sbket[(int)cnt[arr[index]] / sq]--;
    bket[cnt[arr[index]]]--;
    if(now == cnt[arr[index]] && bket[cnt[arr[index]]] == 0) {
        now = cnt[arr[index]] - 1;
    }
    if(add) {
        cnt[arr[index]]++;
    }
    else {
        cnt[arr[index]]--;
    }
    bket[cnt[arr[index]]]++;
    now = max(now, cnt[arr[index]]);

    Sbket[ (int)cnt[arr[index]]/ sq ]++;
}

int find_ans() {
    for(int j=sq-1; j>=0; j--) {
        if(Sbket[j] > 0) {
            for(int k=sq-1; k>=0; k--) {
                if( bket[j*sq+k] > 0 ) {
                    return j*sq+k;
                }
            }
        }
    }
    return 0;
}

int main() {
    scanf("%d", &N);
    sq = (int)sqrt(N);
    for(int i=1; i<=N; i++) {
        scanf("%d", &arr[i]);
    }
    scanf("%d", &M);
    for(int i=1; i<=M; i++) {
        scanf("%d%d", &Q[i].left, &Q[i].right);
        Q[i].index = i;
    }
    Sbket[0] = N;
    cnt[0] = N;
    sort(Q+1, Q+M+1, cmp);
    int lo = 1, hi = 0;
    for(int i=1; i<=M; i++) {
        while(Q[i].left < lo) {
            f(--lo, true);
        }
        while(Q[i].left > lo) {
            f(lo++, false);
        }
        while(Q[i].right > hi) {
            f(++hi, true);
        }
        while(Q[i].right < hi) {
            f(hi--, false);
        }

        // for(int i=0; i<=N; i++) {
        //     printf("%d ", cnt[i]);
        // }
        // printf("\n");
        // for(int i=0; i<=N; i++) {
        //     printf("%d ", bket[i]);
        // }
        // printf("\n");
        ans[Q[i].index] = now;
        //ans[Q[i].index] = find_ans();
    }

    for(int i=1; i<=M; i++) {
        printf("%d\n", ans[i]);
    } 
}