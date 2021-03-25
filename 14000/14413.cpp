//# Author : nuclear852 ========================#
//# Solution : 25786920 ========================#
//# Time Stamp : 2021-01-28 22:41:33 ===========#
//# Problem Title : Poklon =================#
//# Language : C++17 ===========================#

#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <unordered_map>
#include <math.h>
using namespace std;
typedef long long ll;

unordered_map<int, int> m;
int N, Q;
int arr[505050];
int cnt[505050];
int s_cnt[505050];
int ans[505050];
int sz;

struct Query{
    int left, right, idx;
}q[505050];

bool cmp(const struct Query &a, const struct Query &b) {
    int aR = a.right / sz;
    int bR = b.right / sz;

    return aR == bR ? a.left < b.left : a.right < b.right;   
}

void f(int idx, bool add) {
    int val = arr[idx];
    if(add){
        if(cnt[val]) s_cnt[cnt[val]]--;
        cnt[val]++;
        s_cnt[cnt[val]]++;
    }
    else {
        s_cnt[cnt[val]]--;
        cnt[val]--;
        if(cnt[val]) s_cnt[cnt[val]]++;
    }
}

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> N >> Q;
    sz = (int)sqrt(N);
    int idx = 0;
    int tmp;
    for(int i=1; i<=N; i++) {
        cin >> tmp;
        if(m.find(tmp) == m.end()) {
            m[tmp] = ++idx;
        }
        arr[i] = m[tmp];
    }
    for(int i=1; i<=Q; i++) {
        cin >> q[i].left >> q[i].right;
        q[i].idx = i;
    }

    sort(q+1, q+Q+1, cmp);

    int low = q[1].left, high = q[1].right;
    for(int i=low; i<=high; i++) {
        f(i, true);
    }
    ans[q[1].idx] = s_cnt[2];
    for(int i=2; i<=Q; i++) {
        while(q[i].left < low) f(--low, true);
        while(q[i].right > high) f(++high, true);
        while(q[i].left > low) f(low++, false);
        while(q[i].right < high) f(high--, false);
        ans[q[i].idx] = s_cnt[2];
    }
    for(int i=1; i<=Q; i++) {
        cout << ans[i] << "\n";
    }
}