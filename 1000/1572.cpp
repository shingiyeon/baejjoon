//# Author : nuclear852 ========================#
//# Solution : 22975850 ========================#
//# Time Stamp : 2020-10-02 22:57:41 ===========#
//# Problem Title : 중앙값 ====================#
//# Language : C++14 ===========================#

#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int N, K;

int temp[250000];
int arr[250001];
int tree[1000008];


int init(int index, int start, int end) {
    if(start == end) {
        return tree[index] = temp[start];
    }
    if(start > end) {
        return 0;
    }
    int mid = (start + end) / 2;
    int left_tree = init(index * 2, start, mid);
    int right_tree = init(index * 2 + 1, mid + 1, end);
    return tree[index] =  left_tree + right_tree;
}

int find(int index, int start, int end, int K) {
    if(start >= end)
        return start;
    
    int left_tree = tree[index * 2];
    int mid = (start + end) / 2;
    if(left_tree >= K) {
        return find(index*2, start, mid, K);
    }
    else {
        return find(index*2+1, mid+1, end, K-left_tree);
    }

}

void update(int index, int start, int end, int cur, int diff) {
    if(start <= cur && cur <= end) {
        tree[index] += diff;
    }
    else {
        return;
    }
    if(start == end) return;
    int mid = (start + end) / 2;
    update(index * 2, start, mid, cur, diff);
    update(index * 2 + 1, mid + 1, end, cur, diff);
    tree[index] = tree[index*2] + tree[index*2+1];
}

int main() {
    scanf("%d%d", &N, &K);
    for(int i=1; i<=N; i++) scanf("%d", &arr[i]);
    for(int i=1; i<=K; i++) {
        temp[arr[i]]++;
    }
    init(1, 0, 65535);
    const int target = ((K+1) / 2);
    long long answer = 0;
    for(int i=1; i<=N-K+1; i++) {
        int middle_val = find(1, 0, 65535, target);
        answer += (long long) middle_val;
        update(1, 0, 65535, arr[i], -1);
        update(1, 0, 65535, arr[i+K], 1);
    }
    printf("%lld", answer);
}