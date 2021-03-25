//# Author : nuclear852 ========================#
//# Solution : 23896883 ========================#
//# Time Stamp : 2020-11-17 10:12:34 ===========#
//# Problem Title : 히스토그램 ==================#
//# Language : C++17 ===========================#

#include <stdio.h>
#include <utility>
#include <algorithm>
#define INF 2000000000
typedef long long ll;
using namespace std;

int N;
pair<int, int> tree[303030];

void update(int index, int start, int end, int cur, int diff) {
    if(cur < start || cur > end) return;
    if(start == end) {
        tree[index] = {cur, diff};
        return;
    }
    int mid = (start + end) / 2;
    update(index * 2, start , mid, cur, diff);
    update(index * 2 + 1, mid + 1 , end, cur, diff);
    if(tree[index * 2].second < tree[index * 2 + 1].second) {
        tree[index] = tree[index*2];
    }
    else {
        tree[index] = tree[index * 2 + 1];
    }
    
}

pair<int, int> find(int index, int start, int end, int left, int right) {
    if(start > right || end < left) {
        return {0, INF};
    }
    if(left <= start && end <= right) {
        return tree[index];
    }
    if(start == end) return {0, INF};
    int mid = (start + end) / 2;
    pair<int, int> LT = find(index * 2, start, mid, left, right);
    pair<int, int> RT = find(index * 2 + 1, mid + 1, end, left, right);
    if(LT.second < RT.second) {
        return LT;
    }
    else {
        return RT;
    }
}

ll find_min_tree(int start, int end) {
    if(start > end) return 0;
    pair<int, int> cur_tree = find(1, 1, N, start, end);
    ll LV = find_min_tree(start, cur_tree.first - 1);
    ll RV = find_min_tree(cur_tree.first + 1, end);
    ll CV = (end - start + 1) * cur_tree.second;
    return max(LV, max(RV, CV));
}

int main() {
    int tmp;
    scanf("%d", &N);
    for(int i=1; i<=N; i++) {
        scanf("%d", &tmp);
        update(1, 1, N, i, tmp);
    }
    printf("%lld\n", find_min_tree(1, N));

}