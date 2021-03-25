//# Author : nuclear852 ========================#
//# Solution : 24712029 ========================#
//# Time Stamp : 2020-12-29 15:17:33 ===========#
//# Problem Title : 제곱 ㄴㄴ ==================#
//# Language : C++17 ===========================#

#include <stdio.h>
#include <algorithm>
#include <vector>
#include <math.h>
#define MAX 10000000000LL
typedef long long ll;
using namespace std;
ll K;
vector<ll> prime;
bool origin[1000005];
ll num[1000005];

int main() {
    scanf("%lld", &K);
    ll sqK = (ll)sqrt(MAX);
    for(ll i=2; i<=sqK; i++) {
        bool pos = true;
        for(auto val: prime) {
            if(val*val > i) break;
            if(i % val == 0) {
                pos = false;
                break;
            }
        } 
        if(pos) prime.push_back(i);
    }
    for(auto prim: prime) {
        origin[prim] = true;
        for(ll j=2*prim; j <= sqK; j+=prim) {
            num[j]++;
        }
        for(ll j=prim*prim; j<= sqK; j+=prim*prim) {
            num[j] = -999999999;
        }
    }

    ll start = 0, end = MAX;
    while(start <= end) {
        ll mid = (start + end) / 2;
        ll hap = 0;
        for(int i=2; (ll)i*i<=end; i++) {
            long long diff = 0;
            if(origin[i] == true) {
                diff = (mid / (long long)(i*i));
            }
            if(num[i] > 1) {
                long long tmp = (num[i]%2 == 0) ? -1 : 1;
                diff = tmp * (mid) / (long long)(i * i);
            }
            hap += diff;
        }
        if(mid - hap < K) {
            start = mid + 1 ;
        }
        else {
            end = mid - 1;
        }
    }
    printf("%lld", start);
}