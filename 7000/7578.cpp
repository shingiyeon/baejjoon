//# Author : nuclear852 ========================#
//# Solution : 22171685 ========================#
//# Time Stamp : 2020-08-31 00:12:20 ===========#
//# Problem Title : 공장 =====================#
//# Language : C++14 ===========================#

#include <stdio.h>
#include <map>
using namespace std;

map<int, int> m;
int N;
int arr[500001];
long long tree[2000001];


long long find(int index, int start, int end, int left, int right) {
    if(left <= start && end <= right) {
        return tree[index];
    }
    else if(left > end || start > right){
        return 0;
    }
    int mid = (start + end) / 2;
    return find(index*2, start , mid, left, right) + find(index*2+1, mid+1, end, left, right);
}

void update(int index, int start, int end, int cur) {
    if(start <= cur && cur <= end) {
        tree[index] += 1;
    }
    else {
        return;
    }
    if(start == end) return;
    int mid = (start + end) / 2;
    update(index * 2, start, mid, cur);
    update(index * 2 + 1, mid+1, end, cur);
}

int main() {
    scanf("%d", &N);
    int tmp;
    for(int i=1; i<=N; i++) scanf("%d", &arr[i]);
    for(int i=1; i<=N; i++) {
        scanf("%d", &tmp);
        m[tmp] = i;
    }
    for(int i=1; i<=N; i++) {
        arr[i] = m[arr[i]];
    }
    long long ans = 0;
    for(int i=1; i<=N; i++) {
        ans += find(1, 1, N, arr[i]+1, N);
        update(1, 1, N, arr[i]);
    }
    printf("%lld", ans);
}