//# Author : nuclear852 ========================#
//# Solution : 26199990 ========================#
//# Time Stamp : 2021-02-09 14:18:22 ===========#
//# Problem Title : K진 트리 ==================#
//# Language : C++17 ===========================#

#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);
    long long N, K, Q; cin >> N >> K >> Q;
    long long idx = K - 2;
    for(int i=1; i<=Q; i++) {
        long long a, b; cin >> a >> b;
        long long ans = 0;
        if(K != 1) {
            while(a != b) {
                if(a > b) {
                    a = (a + idx)/K;
                }
                else {
                    b = (b + idx)/K;
                }
                ans++;
            }
        }
        else {
            ans = a > b ? a - b : b - a;
        }
        cout << ans << "\n";
    }
}