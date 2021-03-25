//# Author : nuclear852 ========================#
//# Solution : 26165020 ========================#
//# Time Stamp : 2021-02-08 16:08:54 ===========#
//# Problem Title : 코끼리 ====================#
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
    int x, y, x_rnk, y_rnk;
}a[300001];

bool cmpX(const struct A &a, const struct A &b) {
    return a.x < b.x;
}

bool cmpY(const struct A &a, const struct A &b) {
    return a.y < b.y;
}

bool cmpXrnk(const struct A &a, const struct A &b) {
    return a.x_rnk == b.x_rnk ? a.y_rnk > b.y_rnk : a.x_rnk < b.x_rnk;
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
        cin >> a[i].x >> a[i].y;
    }
    sort(a, a+N, cmpX);
    int x_rnk = 1, y_rnk = 1;
    for(int i=0; i<N; i++) {
        if(i == 0) a[i].x_rnk = x_rnk;
        else {
            if(a[i-1].x == a[i].x) a[i].x_rnk = x_rnk;
            else a[i].x_rnk = ++x_rnk;
        }
    }
    sort(a, a+N, cmpY);
    for(int i=0; i<N; i++) {
        if(i == 0) a[i].y_rnk = y_rnk;
        else {
            if(a[i-1].y == a[i].y) a[i].y_rnk = y_rnk;
            else a[i].y_rnk = ++y_rnk;
        }
    }
    sort(a, a+N, cmpXrnk);
    for(int i=0; i<N; i++) {
        auto cT = find(1, 0, y_rnk, 0, a[i].y_rnk-1);
        update(1, 0, y_rnk, a[i].y_rnk, cT.first+1, cT.second==0? 1 : cT.second);
    }
    cout << tree[1].first << "\n" << tree[1].second;

}