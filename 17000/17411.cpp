//# Author : nuclear852 ========================#
//# Solution : 26161457 ========================#
//# Time Stamp : 2021-02-08 14:49:02 ===========#
//# Problem Title : 가장 긴 증가하는 부분 수열 6 ======#
//# Language : C++17 ===========================#

#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <utility>
#define MOD 1000000007
typedef long long ll;
using namespace std;

pair<int, ll> tree[4004040];
struct A{
    int idx, val, rnk;
}a[1000001];

bool cmpIdx(const struct A &a, const struct A &b) {
    return a.idx < b.idx;
}
bool cmpVal(const struct A &a, const struct A &b) {
    return a.val < b.val;
}

void update(int index, int start, int end, int cur, int LIS, long long val) {
    if(cur < start || end < cur) return;
    if(start <= cur && cur <= end) {
        if(tree[index].first < LIS) {
            tree[index].first = LIS;
            tree[index].second = val;
        }
        else if(tree[index].first == LIS) {
            tree[index].second = (tree[index].second + val) % MOD;
        }
    }
    if(start == end) return;
    int mid = (start + end) / 2;
    update(index * 2, start, mid, cur, LIS, val);
    update(index * 2 + 1, mid + 1, end, cur, LIS, val);
}

pair<int, ll> find(int index, int start, int end, int left, int right) {
    if(right < start || left > end) return {0, 0};
    else if(left <= start && end <= right) {
        return tree[index];
    }
    if(start == end) return{0, 0};
    int mid = (start + end) / 2;
    pair<int, ll> lT = find(index*2, start, mid, left, right);
    pair<int, ll> rT = find(index*2+1, mid+1, end, left, right);
    if(lT.first < rT.first) return rT;
    else if(lT.first > rT.first) return lT;
    else return {lT.first, (lT.second+rT.second) % MOD};
}

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);
    int N; cin >> N;
    for(int i=0; i<N; i++) {
        cin >> a[i].val;
        a[i].idx = i;
    }
    sort(a, a+N, cmpVal);
    int rnk = 1;
    for(int i=0; i<N; i++) {
        if(i == 0) a[i].rnk = rnk;
        else {
            if(a[i-1].val == a[i].val) a[i].rnk = rnk;
            else a[i].rnk = ++rnk;
        }
    }
    sort(a, a+N, cmpIdx);
    
    for(int i=0; i<N; i++) {
        auto cT = find(1, 0, rnk, 0, a[i].rnk-1);
        update(1, 0, rnk, a[i].rnk, cT.first+1, cT.second==0? 1 : cT.second);
    }
    cout << tree[1].first << " " << tree[1].second;

}