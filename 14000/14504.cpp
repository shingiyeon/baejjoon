//# Author : nuclear852 ========================#
//# Solution : 24727620 ========================#
//# Time Stamp : 2020-12-29 23:07:44 ===========#
//# Problem Title : 수열과 쿼리 18 ==============#
//# Language : C++17 ===========================#

#include <stdio.h>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

int N, M;
int sq;
int cnt[101010];
vector<int> bkt[505];
int arr[101010];

int main() {
    scanf("%d", &N); sq = (int)sqrt(N);
    for(int i=1; i<=N; i++) {
        scanf("%d", &arr[i]);
        
        bkt[i/sq].push_back(arr[i]);
    }
    for(int i=0; i<=sq+5; i++) {
        sort(bkt[i].begin(), bkt[i].end());
    }
    scanf("%d", &M);

    for(int i=1; i<=M; i++) {
        int con; scanf("%d", &con);
        if(con == 1) {
            int left, right, k; scanf("%d%d%d", &left, &right, &k);
            int ans = 0;
            while(left % sq > 0 && left <= right) {
                if (arr[left++] > k) ans++;
            }
            while((right+1) % sq > 0 && left <= right) {
                if (arr[right--] > k) ans++;
            }
            while(left <= right) {
                ans += bkt[left/sq].end() - upper_bound(bkt[left/sq].begin(), bkt[left/sq].end(), k);
                left += sq;
            }
            printf("%d\n", ans);
        }
        else {
            int cur, k; scanf("%d%d", &cur, &k);
            auto idx = lower_bound(bkt[cur/sq].begin(), bkt[cur/sq].end(), arr[cur]) - bkt[cur/sq].begin();
            bkt[cur/sq][idx] = k;
            sort(bkt[cur/sq].begin(), bkt[cur/sq].end());
            arr[cur] = k;
        }
    }
}