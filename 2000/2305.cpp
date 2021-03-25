//# Author : nuclear852 ========================#
//# Solution : 26260806 ========================#
//# Time Stamp : 2021-02-11 00:45:13 ===========#
//# Problem Title : 자리 배치 ==================#
//# Language : C++17 ===========================#

#include <iostream>

using namespace std;


long long dy[41];
long long sum[41];

long long d(int idx) {
    long long t = 0;
    if(idx == 0) return 0;
    else if(idx == 1) return 1;
    t = 2 * sum[idx-1];
    for(int i=1; i<=idx-2; i++) {
        t += dy[i] * dy[idx-1-i];
        t += sum[i-1] * dy[idx-1-i];
        t += dy[i] * sum[idx-2-i];
    }
    return t;
}

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);
    dy[0] = 1; dy[1] = 1;
    sum[0] = 1; sum[1] = 2;
    for(int i=2; i<=40; i++)  {
        dy[i] = dy[i-1] + dy[i-2];
        sum[i] = dy[i] + sum[i-1];
    }

    int N, K; cin>>N>>K;

    long long ans = dy[K-1] * dy[N-K];
    long long left, right;
    left = d(K-1) * dy[N-K];
    right = d(N-K) * dy[K-1];
   
    //cout << left << " " << right << "\n";
    ans += left + right;
    cout << ans;
    
}