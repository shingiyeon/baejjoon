//# Author : nuclear852 ========================#
//# Solution : 22975145 ========================#
//# Time Stamp : 2020-10-02 22:21:50 ===========#
//# Problem Title : 터보소트 ===================#
//# Language : C++14 ===========================#

#include <stdio.h>

using namespace std;
int N;

int arr[100001];
int pos[100001];
int tree[400010];

void init(int index, int start, int end) {
    if(start == end) {
        tree[index] = 1;
        return;
    }
    int mid = (start + end) / 2;
    init(index * 2, start, mid);
    init(index * 2 + 1, mid + 1, end);
    tree[index] = tree[index * 2] + tree[index * 2 + 1];
    return;
}

void update(int index, int start, int end, int cur) {
    if(cur < start || end < cur) {
        return;
    }
    if(start <= cur && cur <= end) {
        tree[index]--;
    }
    if(start == end) return;
    int mid = (start + end) / 2;
    update(index * 2, start, mid, cur);
    update(index * 2 + 1, mid + 1, end, cur);
}

int sum(int index, int start, int end, int left, int right) {
    if(right < start || end < left) return 0;
    if(left <= start && end <= right) {
        return tree[index];
    }
    if(start == end) return 0;
    int mid = (start + end) / 2;
    return sum(index * 2, start, mid, left, right) + sum(index * 2 + 1, mid + 1, end, left, right);
}

int main() {
    scanf("%d", &N);
    int left = 1;
    int right = N;
    int index = 1;
    for(int i=1; i<=N; i++) scanf("%d", &arr[i]);
    for(int i=1; i<=N; i++) pos[arr[i]] = i;
    init(1, 1, N);
    while(left <= right) { 
        if(index % 2) {
            printf("%d\n", sum(1, 1, N, 1, pos[left] - 1));
            update(1, 1, N, pos[left]);
            left++;
        }
        else {
            printf("%d\n", sum(1, 1, N, pos[right] + 1, N));
            update(1, 1, N, pos[right]);
            right--;
        }
        index++;
    }
}