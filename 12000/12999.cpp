//# Author : nuclear852 ========================#
//# Solution : 25722620 ========================#
//# Time Stamp : 2021-01-27 11:09:14 ===========#
//# Problem Title : 화려한 마을3 ================#
//# Language : C++17 ===========================#

#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

int N, M;
int sz;
int ans[101010];
int cnt[201010];
int s_cnt[101010];
int arr[101010];
int max_val = 0;
struct Query {
    int left, right, index;
}Q[101010];

bool cmp(const struct Query &a, const struct Query &b) {
    int aR = a.right / sz;
    int bR = b.right / sz;

    return aR == bR ? a.left < b.left : a.right < b.right;
}

void f(int idx, bool add) {
    int light = arr[idx] + 100000;
    if(add) {
        if(s_cnt[cnt[light]]) {
            s_cnt[cnt[light]]--;
        }
        cnt[light]++;
        s_cnt[cnt[light]]++;
        if(cnt[light] > max_val) {
            max_val = cnt[light];
        }
    }
    else {
        s_cnt[cnt[light]]--;
        if(max_val == cnt[light] && s_cnt[cnt[light]] == 0) {
            max_val = max_val - 1;
        }
        cnt[light]--;
        s_cnt[cnt[light]]++;
    }
}


int main(){
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> N >> M;
    sz = (int)sqrt(N);
    for(int i=1; i<=N; i++) cin >> arr[i];
    for(int i=1; i<=M; i++) {
        cin >> Q[i].left >> Q[i].right;
        Q[i].index = i;
    }
    sort(Q+1, Q+M+1, cmp);
    int low = Q[1].left, high = Q[1].right;
    for(int i=low; i<=high; i++) {
        f(i, true);
    }
    ans[Q[1].index] = max_val;
    for(int i=2; i<=M; i++) {
        while(Q[i].left < low) f(--low, true);
        while(Q[i].right > high) f(++high, true);
        while(Q[i].left > low) f(low++, false);
        while(Q[i].right < high) f(high--, false);
        ans[Q[i].index] = max_val;
    }
    for(int i=1; i<=M; i++) {
        cout << ans[i] << "\n";
    }
}