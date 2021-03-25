//# Author : nuclear852 ========================#
//# Solution : 23872968 ========================#
//# Time Stamp : 2020-11-15 23:20:22 ===========#
//# Problem Title : 서로 다른 수와 쿼리 1 ==========#
//# Language : C++17 ===========================#

# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <vector>

using namespace std;

vector<int> v;
int cnt[1001001];
int ans[1001001];
int arr[1001001];
int N, Q;
int sq;
int sum = 0;
struct Query {
    int left, right, index;
}q[1001001];

bool cmp(const struct Query &a, const struct Query &b) {
    int aR = a.right / sq;
    int bR = b.right / sq;

    return aR == bR ? a.left < b.left : aR < bR;
}

void f(int index, bool add) {
    int val = arr[index];
    if(add) {
        if(cnt[val] == 0) {
            sum++; 
        }
        cnt[val]++;
    }
    else {
        cnt[val]--;
        if(cnt[val] == 0) {
            sum--;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    //scanf("%d", &N);
    sq = (int)sqrt(N);
    for(int i=1; i<=N; i++) {
        //scanf("%d", &arr[i]);
        cin >> arr[i];
        v.push_back(arr[i]);
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    for(int i=1; i<=N; i++) {
        arr[i] = lower_bound(v.begin(), v.end(), arr[i]) - v.begin();
    }

    cin >> Q;
    //scanf("%d", &Q);
    for(int i=1; i<=Q; i++) {
        //scanf("%d%d", &q[i].left, &q[i].right);
        cin >> q[i].left >> q[i].right;
        q[i].index = i;
    }
    sort(q+1, q+Q+1, cmp);

    int low = q[1].left, high = q[1].right;
    for(int i=low; i<=high; i++) {
        f(i, true);
    }
    ans[q[1].index] = sum;
    for(int i=2; i<=Q; i++) {
        while(q[i].left < low) {
            f(--low, true);
        }
        while(q[i].right > high) {
            f(++high, true);
        }
        while(q[i].left > low) {
            f(low++, false);
        }
        while(q[i].right < high) {
            f(high--, false);
        }
        ans[q[i].index] = sum;
    }

    for(int i=1; i<=Q; i++) {
        cout << ans[i] << "\n";
        //printf("%d\n", ans[i]);
    }
}