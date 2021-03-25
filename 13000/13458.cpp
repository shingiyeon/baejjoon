//# Author : nuclear852 ========================#
//# Solution : 24887793 ========================#
//# Time Stamp : 2021-01-04 11:09:53 ===========#
//# Problem Title : 시험 감독 ==================#
//# Language : C++17 ===========================#

#include <stdio.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    long long ans = 0;
    vector<int> v;
    int N; scanf("%d", &N);
    int B, C;
    for(int i=0; i<N; i++) {
        int tmp; scanf("%d", &tmp); v.push_back(tmp);
    }
    scanf("%d%d", &B, &C);
    
    for(auto val: v) {
        ans++;
        int num = max(0, val - B);
        if(num % C == 0) {
            ans += (long long)num / C;
        }
        else {
            ans += (long long)num / C + 1;
        }
    }
    printf("%lld", ans);
}