//# Author : nuclear852 ========================#
//# Solution : 24442026 ========================#
//# Time Stamp : 2020-12-18 13:31:41 ===========#
//# Problem Title : 카드 배열 ==================#
//# Language : C++17 ===========================#

#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <functional>
typedef long long ll;
using namespace std;
const ll MOD = 1000000007;
int N, k, P;
int s_cnt, b_cnt;
int sindeg[300001], bindeg[300001];
vector<int> sv, bv;
vector< vector<int> > sadj, badj;
priority_queue<int, vector<int>, greater<int> > bq;
priority_queue<int, vector<int>, greater<int> > sq;
ll s, b;
ll pow(ll a, int b) {
    ll ret = 1;
    while(b) {
        if(b%2) ret = (ret * a) % MOD;
        a = (a * a) % MOD;
        b /= 2;
    }
    return ret%MOD;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> k >> P;
   // scanf("%d%d%d", &N, &k, &P);
    sv.resize(k); bv.resize(k);
    sadj.resize(k); badj.resize(k);
    s_cnt = k-1;
    b_cnt = (N-k);
    for(int i=0; i<P; i++) {
        int a, b; cin >> a >> b;
        //scanf("%d%d", &a, &b);
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
    int a = 1;
    for(int i=0; i<k; i++) {
        ans += ((bv[i] - sv[i]) * pow(N, i)) % MOD;
    }
    //printf("%lld %lld\n", b, s);
    printf("%lld", (ans % MOD + MOD ) % MOD);
}