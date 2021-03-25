//# Author : nuclear852 ========================#
//# Solution : 24442425 ========================#
//# Time Stamp : 2020-12-18 13:55:56 ===========#
//# Problem Title : 카드 배열 ==================#
//# Language : C++17 ===========================#

#include <stdio.h>
#include <vector>
#include <queue>
#include <functional>
typedef long long ll;
using namespace std;
const ll MOD = 1000000007;
int N, k, P;
int s_cnt, b_cnt;
int sindeg[300001], bindeg[300001];
int sv[300001], bv[300001];
vector<int> sadj[300001], badj[300001];
priority_queue<int, vector<int>, greater<int> > bq;
priority_queue<int, vector<int>, greater<int> > sq;
ll s, b;

int main() {
    scanf("%d%d%d", &N, &k, &P);
    s_cnt = k-1;
    b_cnt = (N-k);
    for(int i=0; i<P; i++) {
        int a, b; 
        scanf("%d%d", &a, &b);
        badj[b].push_back(a);
        sadj[a].push_back(b);
        sindeg[b]++; bindeg[a]++;
    }
    for(int i=0; i<k; i++) {
        if(!sindeg[i]) sq.push(i);
        if(!bindeg[i]) bq.push(i);
    }
    while(!sq.empty()) {
        int cur = sq.top(); sq.pop();
        sv[cur] = s_cnt--;
        for(auto next: sadj[cur]) {
            sindeg[next]--;
            if(!sindeg[next]) {
                sq.push(next);
            }
        }
    }

    while(!bq.empty()) {
        int cur = bq.top(); bq.pop();
        bv[cur] = b_cnt++;
        for(auto next: badj[cur]) {
            bindeg[next]--;
            if(!bindeg[next]) {
                bq.push(next);
            }
        }
    }
    // for(int i=k-1; i>=0; i--) {
    //     printf("%d ", bv[i]);
    // }
    // printf("\n");
    // for(int i=k-1; i>=0; i--) {
    //     printf("%d ", sv[i]);
    // }
    // printf("\n");
    long long ans = 0;
    long long a = 1;
    for(int i=0; i<k; i++) {
        ans += ((bv[i] - sv[i]) * a) % MOD;
        a = a * N % MOD;
        ans %= MOD;
    }
    //printf("%lld %lld\n", b, s);
    printf("%lld", (ans % MOD + MOD ) % MOD);
}