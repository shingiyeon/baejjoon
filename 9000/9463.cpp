//# Author : nuclear852 ========================#
//# Solution : 23089598 ========================#
//# Time Stamp : 2020-10-07 23:35:36 ===========#
//# Problem Title : 순열 그래프 =================#
//# Language : C++14 ===========================#

#include <stdio.h>
using namespace std;

int T, n;
int up[100001];
int map[100001];
int down[100001];

int tree[400010];


void update(int index, int start, int end, int cur) {
    if(cur < start || cur > end) return;
    tree[index] += 1;
    if(start == end) return;
    int mid = (start + end) / 2;
    update(index * 2, start, mid, cur);
    update(index * 2 + 1, mid + 1, end, cur);
}

int sum(int index, int start, int end, int left, int right) {
    if(left <= start && end <= right) return tree[index];
    if(end < left || start > right) return 0;
    if(start == end) return 0;
    int mid = (start + end) / 2;
    return sum(index * 2, start, mid, left, right) + sum(index * 2 + 1, mid + 1, end, left, right);
}

int main() {
    scanf("%d", &T);
    while(T--) {
        long long ans = 0;
        for(int i=0; i<100001; i++) map[i] = 0;
        for(int i=0; i<400010; i++)  tree[i] = 0;
        scanf("%d", &n);
        for(int i=1; i<=n; i++) scanf("%d", &up[i]);
        for(int i=1; i<=n; i++) {
            scanf("%d", &down[i]);
            map[down[i]] = i;
        }
        for(int i=1; i<=n; i++) {
            int tmp = sum(1, 1, n, map[up[i]], n);
            //printf("%d(%d) ", tmp, m[up[i]]);
            ans += (long long)tmp;
            update(1, 1, n, map[up[i]]);
        }
        printf("%lld\n", ans);
    }

}