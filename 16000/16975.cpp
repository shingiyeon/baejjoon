//# Author : nuclear852 ========================#
//# Solution : 23222326 ========================#
//# Time Stamp : 2020-10-13 22:46:17 ===========#
//# Problem Title : 수열과 쿼리 21 ==============#
//# Language : C++14 ===========================#

#include <stdio.h>
typedef long long ll;
using namespace std;

int N, M;

int arr[100001];
ll tree[400010];
ll lazy[400010];

void init(int index, int start, int end){
    if(start == end) {
        tree[index] = (ll)arr[start];
        return;
    }
    int mid = (start + end) / 2;
    init(index * 2, start, mid);
    init(index * 2 + 1, mid + 1, end);
}

void update(int index, int start, int end, int left, int right, int val) {
    if (lazy[index] != 0) {
        if(start != end) {
            lazy[index * 2] += lazy[index];
            lazy[index * 2 + 1] += lazy[index];
        }
        else {
            tree[index] += lazy[index];
        }
        lazy[index] = 0;
    }

    if(left <= start && end <= right) {
        if(start != end) {
            lazy[index * 2] += (ll)val;
            lazy[index * 2 + 1] += (ll)val;
        }
        else {
            tree[index] += (ll)val;
        }
        return;
    }
    if(end < left || start > right) return;
    if(start == end) return;
    int mid = (start + end) / 2;
    update(index * 2, start, mid, left, right, val);
    update(index * 2 + 1, mid + 1, end, left, right, val);
    return;
} 

ll find(int index, int start, int end, int cur) {
    if (lazy[index] != 0) {
        if(start != end) {
            lazy[index * 2] += lazy[index];
            lazy[index * 2 + 1] += lazy[index];
        }
        else {
            tree[index] += lazy[index];
        }
        lazy[index] = 0;
    }
    if(start == end) return tree[index];
    int mid = (start + end) / 2;
    if (start <= cur && cur <= mid) {
        return find(index * 2, start, mid, cur);
    } 
    else {
        return find(index * 2 + 1, mid + 1, end, cur);
    }
}

int main() {
    scanf("%d", &N);
    for(int i=1; i<=N; i++) scanf("%d", &arr[i]);
    init(1, 1, N);
    scanf("%d", &M);
    int q, i, j, k, x;
    while(M--) {
        scanf("%d", &q);
        if(q == 1) {
            scanf("%d%d%d", &i, &j, &k);
            update(1, 1, N, i, j, k);
        }
        else {
            scanf("%d", &x);
            printf("%lld\n", find(1, 1, N, x));
        }
    }

}