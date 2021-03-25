//# Author : nuclear852 ========================#
//# Solution : 22529651 ========================#
//# Time Stamp : 2020-09-13 23:34:59 ===========#
//# Problem Title : 화성 지도 ==================#
//# Language : C++14 ===========================#

#include <stdio.h>
#include <algorithm>
#include <utility>

using namespace std;

pair<int, int> tree[120001];

void update(int index, int start, int end, int left, int right, int isStart) {
    if(right < start || left > end) return;
    if(left <= start && end <= right) tree[index].second += isStart;
    else {
        int mid = (start + end) / 2;
        update(index * 2, start, mid, left, right, isStart);
        update(index * 2 + 1, mid + 1, end, left, right, isStart);
    }
    if(tree[index].second) {
        tree[index].first = (end - start + 1);
    }
    else {
        if(start == end) {
            tree[index].first = 0;
        }
        else{
            tree[index].first = tree[index * 2].first + tree[index * 2 + 1].first;
        }
    }
}

struct line {
    int x, y1, y2, isStart;
}L[20010];

bool cmp(line a, line b) {
    return a.x < b.x;
}

int N;

int main() {
    scanf("%d", &N);
    int x1, y1, x2, y2;
    for(int i=1; i<=N; i++) {
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        L[i*2-1].x = x1; L[i*2-1].isStart = 1; 
        L[i*2-1].y1 = y1; L[i*2-1].y2 = y2-1;
        L[i*2].x = x2; L[i*2].isStart = -1; 
        L[i*2].y1 = y1; L[i*2].y2 = y2-1;
    }


    sort(L+1, L+(2*N)+1, cmp);
    long long ans = 0;
    int last = L[1].x;
    for(int i=1; i<=2*N; i++) {
        int x = L[i].x;
        int y_low = L[i].y1; int y_high = L[i].y2;
        int isStart = L[i].isStart;
        ans += (long long)(x - last) * tree[1].first;
        update(1, 0, 30000, y_low, y_high, isStart);
        last = x;
    }
    printf("%lld", ans);

}