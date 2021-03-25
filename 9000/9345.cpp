//# Author : nuclear852 ========================#
//# Solution : 23015146 ========================#
//# Time Stamp : 2020-10-04 23:08:12 ===========#
//# Problem Title : 디지털 비디오 디스크(DVDs) ======#
//# Language : C++14 ===========================#

#include <stdio.h>
#include <algorithm>
#include <utility>
#define MAX 999999999
#define MIN 0

using namespace std;

int T, N, K;

pair<int, int> tree[400040];
int arr[400040];

void init(int index, int start, int end) {
    if(start == end) {
        tree[index] = {start, start};
        return;
    }
    int mid = (start + end) / 2;
    init(index * 2, start, mid);
    init(index * 2 + 1, mid + 1, end);
    
    tree[index].first = max(tree[index*2].first, tree[index*2+1].first);
    tree[index].second = min(tree[index*2].second, tree[index*2+1].second);
}

pair<int, int> find(int index, int start, int end, int left, int right) {
    if(left <= start && end <= right) {
        return tree[index];
    }
    if(right < start || end < left) return {MIN, MAX};
    if(start == end) return {MIN, MAX};

    int mid = (start + end) / 2;

    pair<int, int> lT = find(index * 2, start , mid, left, right);
    pair<int, int> rT = find(index * 2 + 1, mid + 1, end, left, right);

    return {max(lT.first, rT.first), min(lT.second, rT.second)};
}

void update(int index, int start, int end, int cur, int val) {
    if(cur < start || end < cur) return;

    if(start == end) {
        tree[index].first = val;
        tree[index].second = val;
        return;
    }

    int mid = (start + end) / 2;
    update(index * 2, start, mid, cur, val);
    update(index * 2 + 1, mid + 1, end, cur, val);

    tree[index].first = max(tree[index * 2].first, tree[index * 2 + 1].first);
    tree[index].second = min(tree[index * 2].second, tree[index * 2 + 1].second);
    return;
}

int main() {
    scanf("%d", &T);
    int Q, X, Y;
    while(T--) {
        scanf("%d%d", &N, &K);
        for(int i=0; i<N; i++) arr[i] = i;
        init(1, 0, N-1); 
        for(int i=0; i<K; i++) {
            scanf("%d%d%d", &Q, &X, &Y);
            if(Q) {
                pair<int, int> ans = find(1, 0, N-1, X, Y);
                //printf("%d %d : ", ans.first, ans.second);
                if(ans.first == Y && ans.second == X) {
                    printf("YES\n");
                }
                else {
                    printf("NO\n");
                }
            }
            else {
                update(1, 0, N-1, X, arr[Y]);
                update(1, 0, N-1, Y, arr[X]);
                int tmp = arr[Y];
                arr[Y] = arr[X];
                arr[X] = tmp;
                // for(int i=0; i<N; i++) {
                //     printf("%d ", arr[i]);
                // }
                // printf("\n");
            }
        }
    }
}