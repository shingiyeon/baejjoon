//# Author : nuclear852 ========================#
//# Solution : 25721363 ========================#
//# Time Stamp : 2021-01-27 10:27:10 ===========#
//# Problem Title : 타일 채우기 3 ===============#
//# Language : C++17 ===========================#

#include <stdio.h>
#define MOD 1000000007
typedef long long ll;

ll d[1000001];
ll sum;
int main(){
    d[0] = 1;
    sum = d[0];
    int N; scanf("%d", &N);
    for(int i = 1; i <= N; i++) {
        if(i-2 >= 0) {
            d[i] = (d[i] + d[i-2]) % MOD;
        }
        d[i] = (d[i] + ( 2 * sum) ) % MOD;
        sum = (sum + d[i]) % MOD;
    }
    printf("%lld", d[N]);
}