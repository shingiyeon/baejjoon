//# Author : nuclear852 ========================#
//# Solution : 22629854 ========================#
//# Time Stamp : 2020-09-17 23:28:14 ===========#
//# Problem Title : 굉장한 학생 =================#
//# Language : C++14 ===========================#

#include <stdio.h>
#include <algorithm>
using namespace std;

const int INF = 987654321;
int N;

struct Score{
    int x, y, z;
}S[500001];

bool cmp(Score a, Score b) {
    return a.x < b.x;
}

int tree[2000005];

void update(int index, int start, int end, int cur, int change) {
    if(cur < start || cur > end) return;
    if(start == end) {
        tree[index] = change;
        return;
    }
    int mid = (start + end) / 2;
    update(index * 2, start, mid, cur, change);
    update(index * 2 + 1, mid + 1, end, cur, change);
    tree[index] = min(tree[index * 2], tree[index * 2 + 1]);
    return;
}

int find(int index, int start, int end, int left, int right) {
    if(left <= start && end <= right) {
        return tree[index];
    }
    else if(end < left || start > right) {
        return INF;
    }
    int mid = (start + end) / 2;
    return min(find(index * 2, start, mid, left, right), find(index * 2 + 1, mid + 1, end, left, right));
}

int main() {
    scanf("%d", &N);
    int t;
    for(int i=1; i<=N; i++) {scanf("%d", &t); S[t].x = i;}
    for(int i=1; i<=N; i++) {scanf("%d", &t); S[t].y = i;}
    for(int i=1; i<=N; i++) {scanf("%d", &t); S[t].z = i;}
    sort(S+1, S+1+N, cmp);
    int ans = 0;
    for(int i=1; i<2000005; i++) tree[i] = INF;
    for(int i=1; i<=N; i++) {
        if(find(1, 1, N, 1, S[i].y) > S[i].z ) ans++;
        update(1, 1, N, S[i].y, S[i].z);
    }
    printf("%d", ans);
}
// 1 2 3 4  5 6 7 8  9 10
// 7 1 3 10 2 8 6 4  9 5 
// 1 3 7 9  8 2 4 10 6 5


// 2 5 3 8 10 7 1 6 9 4
// 1 2 3 4  5 6 7 8 9 10
// 3 8 7 10 5 4 1 2 6 9