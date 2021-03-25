//# Author : nuclear852 ========================#
//# Solution : 23349316 ========================#
//# Time Stamp : 2020-10-19 22:43:04 ===========#
//# Problem Title : 군인 =====================#
//# Language : C++14 ===========================#

#include <stdio.h>
#include <algorithm>
typedef long long ll;

using namespace std;

int N, M;
int arr[500001];
ll tree[2000020];

void update(int index, int start, int end, int cur, int diff) {
    if(cur < start || cur > end) return;
    if(start <= cur && cur <= end) {
        tree[index] += (ll) diff;
    }
    if(start == end) return;
    int mid = (start + end) / 2;
    update(index * 2, start, mid, cur, diff);
    update(index * 2 + 1, mid + 1, end, cur, diff);
}

ll sum(int index, int start, int end, int left, int right) {
    if(left <= start && end <= right) {
        return tree[index];
    }
    if(left > end || start > right) return 0;
    if(start == end) return 0;
    int mid = (start + end) / 2;
    return sum(index * 2, start, mid, left, right) + sum(index * 2 + 1, mid + 1, end, left, right);
}

int find(int start, int end, long long val) {
    int mid = (start + end) / 2;
    if (start >= end) return start;
    
    ll find_val = sum(1, 1, N, 1, mid);

    if (find_val >= val) {
        return find(start, mid, val);
    }
    else {
        return find(mid + 1, end, val);
    }
}

void print(int index, int start, int end) {
    printf("%d/ %d %d: %lld\n", index, start, end, tree[index]);
    if(start == end) {
        return;
    }
    int mid = (start + end) / 2;
    print(index * 2, start, mid);
    print(index * 2 + 1, mid + 1, end);
}

int main() {
    scanf("%d", &N);
    for(int i=1; i<=N; i++) {
        scanf("%d", &arr[i]);
        update(1, 1, N, i, arr[i]);
    }
    scanf("%d", &M);
    int Q, x, y;
    ll t;
    for(int i=1; i<=M; i++) {
        scanf("%d", &Q);
        if(Q == 1) {
            scanf("%d%d", &x, &y);
            update(1, 1, N, x, y );
            //print(1, 1, N);
            //printf("====================\n");
        }
        else {
            scanf("%lld", &t);
            printf("%d\n", find(1, N, t));
        }
    }

}