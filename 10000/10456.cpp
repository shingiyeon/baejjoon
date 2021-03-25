//# Author : nuclear852 ========================#
//# Solution : 24182076 ========================#
//# Time Stamp : 2020-12-03 13:49:47 ===========#
//# Problem Title : Travel Card ============#
//# Language : C++17 ===========================#

#include <stdio.h>
#include <algorithm>
#define MAX 1000000000000LL;
typedef long long ll;

using namespace std;

int bus[10001], train[10001];
ll tB[10001], tT[10001];
ll d[10001];
ll d2[31];
int T;
int n, a, b;

int main() {
    scanf("%d", &T);
    while(T--) {
        for(int i=0; i<=10000; i++) {
            tB[i] = tT[i] = 0;
        }

        scanf("%d", &n);

        for(int i=1; i<=n; i++) {
            scanf("%d%d", &bus[i], &train[i]);
        }

        ll today;
        for(int i=1; i<=n; i++) {
            d[i] = (ll)bus[i] + 2*(ll)(train[i]) + d[i-1];

            d[i] = min(d[i], 3 + 2*(ll)(train[i]) + d[i-1]);
            d[i] = min(d[i], 6 + d[i-1]);

            int before_s_days = max(0, i-7);
            int seven_day = 0;
            d[i] = min(d[i], 36 + d[before_s_days]);
            for(int j=i; j>before_s_days; j--) seven_day += min(train[j] * 2, 6);
            d[i] = min(d[i], 18 + seven_day + d[before_s_days]);
            
            int before_month = max(0, i-30);
            int month = 0;
            d2[0] = 0;
            for(int j=before_month+1; j<=i; j++) {
                d2[j-before_month] = 2*train[j] + d2[j-before_month-1];
                d2[j-before_month] = min(d2[j-before_month], 6 + d2[j-before_month-1]);
                d2[j-before_month] = min(d2[j-before_month], 36 + d2[max(0, j-before_month-7)]);
            }
            d[i] = min(d[i], 45 + d2[i-before_month] + d[before_month]);
            d[i] = min(d[i], d[before_month] + 90);
        }
        printf("%lld\n", d[n]);
    }
}