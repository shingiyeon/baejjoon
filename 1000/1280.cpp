//# Author : nuclear852 ========================#
//# Solution : 22653349 ========================#
//# Time Stamp : 2020-09-18 23:07:47 ===========#
//# Problem Title : 나무 심기 ==================#
//# Language : C++14 ===========================#

#include <stdio.h>
#include <utility>
#define MOD 1000000007
typedef long long ll;
using namespace std;

ll arr[200001];
pair<int, ll> tree[800005];

int N;


void update(int index, int start, int end, int cur) {
    if(cur < start || end < cur) return;
    if(start <= cur && cur <= end) {
        tree[index].first++;
        tree[index].second += cur;
        //printf("%d %d %d %d %d %lld\n", index, start, end, cur, tree[index].first, tree[index].second);
    }
    if(start == end) return;
    int mid = (start + end) / 2;
    update(index * 2, start, mid, cur);
    update(index * 2 + 1, mid + 1, end, cur);
}

pair<int, ll> find(int index, int start, int end, int left, int right) {
    if(left <= start && end <= right) {
        //printf("%d %d %d %d %d %d %lld\n", index, start, end, left, right, tree[index].first, tree[index].second);
        return tree[index];
    }
    else if(end < left || right < start) {
        return {0, 0};
    }
    if(start == end) return {0, 0};
    int mid = (start + end) / 2;
    pair<int, ll> leftTree = find(index * 2, start, mid, left, right);
    pair<int, ll> rightTree = find(index * 2 + 1, mid + 1, end, left, right);
   
    //printf("%d %d %d %d %d %d %lld\n", index, start, end, left, right, leftTree.first + rightTree.first, leftTree.second + rightTree.second);
    return {leftTree.first + rightTree.first, leftTree.second + rightTree.second};
}


int main() {
    scanf("%d", &N);
    for(int i=1; i<=N; i++) scanf("%lld", &arr[i]);
    for(int i=0; i<=800004; i++) tree[i] = {0, (ll)0};
    ll ans = 1;
    update(1, 0, 199999, (int)arr[1]);
    for(int i=2; i<=N; i++) {
        pair<int, ll> left = find(1, 0, 199999, 0, (int)arr[i]);
        pair<int, ll> right = find(1, 0, 199999, (int)arr[i], 199999);
        ll temp = 0;
        temp += (ll)(left.first * arr[i]) - left.second;
        temp += right.second - (ll)(right.first * arr[i]);
        //printf("%d %lld %d %lld %lld\n",left.first, left.second, right.first, right.second, temp);
        ans = (ans * (temp % MOD)) % MOD;
        update(1, 0, 199999, arr[i]);
    }
    printf("%lld", ans);
}

//      5  8    7 
//     1 1       1
// 0 1 2 3 4 5 6 7 8 ... 199998  199999