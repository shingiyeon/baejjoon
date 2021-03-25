//# Author : nuclear852 ========================#
//# Solution : 22603534 ========================#
//# Time Stamp : 2020-09-16 22:37:59 ===========#
//# Problem Title : 수열과 쿼리 17 ==============#
//# Language : C++14 ===========================#

#include <stdio.h>
#include <algorithm>
using namespace std;

int N, M;
int arr[100001];
int tree[400004];

int init(int index, int start, int end) {
    if(start == end) {
        tree[index] = arr[start];
        return tree[index];
    }
    int mid = (start + end) / 2;
    init(index * 2 , start , mid);
    init(index * 2 + 1, mid + 1, end);
    tree[index] = min(tree[index * 2], tree[index * 2 + 1]);
    return tree[index];
}

void update(int index, int start, int end, int cur) {
    if(cur < start || cur > end) return;
    if(start == end) {
        if(start == cur) tree[index] = arr[start];
        return;
    }
    int mid = (start + end) / 2;
    update(index * 2, start, mid, cur);
    update(index * 2 + 1, mid + 1, end, cur);
    tree[index] = min(tree[index * 2], tree[index * 2 + 1]);
}  

int find(int index, int start, int end, int left, int right) {
    if(left <= start && end <= right) {
        return tree[index];
    }
    if(end < left || start > right) return 1000000000;
    if(start == end) return tree[index];
    int mid = (start + end) / 2;
    return min(find(index * 2, start, mid, left, right), find(index * 2 + 1, mid + 1, end, left, right));
} 

int main() {
    scanf("%d", &N);
    for(int i=1; i<=N; i++) scanf("%d", &arr[i]);
    init(1, 1, N);
    scanf("%d", &M);
    for(int i=1; i<=M; i++) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        if(a == 1) {
            arr[b] = c;
            update(1, 1, N, b);
        }
        else {
            printf("%d\n", find(1, 1, N, b, c));
        }
    }

}