//# Author : nuclear852 ========================#
//# Solution : 22722624 ========================#
//# Time Stamp : 2020-09-21 23:17:26 ===========#
//# Problem Title : 북서풍 ====================#
//# Language : C++14 ===========================#

#include <stdio.h>
#include <algorithm>
using namespace std;

int tree[300010];
struct Island {
    int x, y;
    int rnkX;
}arr[75001];

bool cmpX(struct Island a, struct Island b) {
    if(a.x == b.x) {
        return a.y < b.y;
    }
    return a.x > b.x;
}

bool cmpY(struct Island a, struct Island b) {
    if(a.y == b.y) {
        return a.x > b.x;
    }
    return a.y < b.y;
}

void update(int index, int start, int end, int cur) {
    if(start <= cur && cur <= end) {
        tree[index]++;
    }
    else {
        return;
    }
    if(start == end) return;
    int mid = (start + end) / 2;
    update(index * 2, start, mid, cur);
    update(index * 2 + 1, mid + 1, end, cur);
}

int sum(int index, int start, int end, int left, int right) {
    if(left <= start && end <= right) {
        return tree[index];
    }
    else if(end < left || right < start) {
        return 0;
    }
    if(start == end) return 0;
    int mid = (start + end) / 2;
    return sum(index * 2, start, mid, left, right) + sum(index * 2 + 1, mid + 1, end, left, right);
}

int T, n;

int main() {
    scanf("%d" ,&T);
    while(T--) {
        long long ans = 0;
        scanf("%d", &n);
        for(int i=1; i<=75000; i++) {
            arr[i].x = arr[i].y = arr[i].rnkX = 0;
        }
        for(int i=0; i<300010; i++) tree[i] = 0;
        for(int i=1; i<=n; i++) {
            scanf("%d%d", &arr[i].x, &arr[i].y);
        }
        sort(arr+1, arr+n+1, cmpX);
        for(int i=1; i<=n; i++) {
            arr[i].rnkX = i;
        }
        sort(arr+1, arr+n+1, cmpY);
        for(int i=1; i<=n; i++) {
            //printf("%d %d %d\n", arr[i].x, arr[i].y, arr[i].rnkX);
            ans += (long long)sum(1, 1, n, 1, arr[i].rnkX);
            update(1, 1, n, arr[i].rnkX);
        }
        printf("%lld\n", ans);
    }
}