//# Author : nuclear852 ========================#
//# Solution : 22925194 ========================#
//# Time Stamp : 2020-09-30 00:00:09 ===========#
//# Problem Title : 가계부 (Hard) =============#
//# Language : C++14 ===========================#

#include <stdio.h>
typedef long long ll;
using namespace std;

int N, Q;
ll tree[4000010];

void update(int index, int start, int end, int cur, ll diff) {
    if(cur < start || end < cur) return;
    if(start <= cur && cur <= end) {
        tree[index] += diff;
    }
    if(start == end) return;
    int mid = (start + end) / 2;
    update(index*2, start, mid, cur, diff);
    update(index*2 + 1, mid + 1, end, cur, diff);
}

ll sum(int index, int start, int end, int left, int right) {
    if(end < left || right < start) return 0;
    if(left <= start && end <= right) {
        return tree[index];
    }
    if(start == end) return 0;
    int mid = (start + end) / 2;
    return sum(index * 2, start, mid, left, right) + sum(index * 2 + 1, mid + 1, end, left, right);
}

int main() {
    scanf("%d%d", &N, &Q);
    int dir, left, right;
    while(Q--) {
        scanf("%d%d%d", &dir, &left, &right);
        if(dir == 1){
            update(1, 1, N, left, (ll)right);
        }
        else {
            printf("%lld\n", sum(1, 1, N, left, right));
        }
    }
}