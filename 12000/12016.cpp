//# Author : nuclear852 ========================#
//# Solution : 24038996 ========================#
//# Time Stamp : 2020-11-25 10:03:11 ===========#
//# Problem Title : 라운드 로빈 스케줄러 ============#
//# Language : C++17 ===========================#

#include <stdio.h>
#include <algorithm>
typedef long long ll;
using namespace std;

int N;
ll tree[404040];
ll answer[101010];

struct Query {
    int val, cur;
}Q[100001];

bool cmp(const struct Query& l, const struct Query& r) {
    if(l.val < r.val) {
        return true;
    }
    else if(l.val > r.val) {
        return false;
    }
    else {
        if(l.cur > r.cur) {
            return true;
        }
        else {
            return false;
        }
    }
}

void init(int index, int start, int end) {
    if(start == end) {
        tree[index] = 1;
        return;
    }
    int mid = (start + end) / 2;
    init(index * 2, start, mid);
    init(index * 2 + 1, mid + 1, end);
    tree[index] = tree[index * 2] + tree[index * 2 + 1];
}

void update(int index, int start, int end, int cur) {
    if(cur < start || cur > end) {
        return;
    }
    if(start <= cur && cur <= end) {
        tree[index] -= 1;
    }
    if(start == end) {
        return;   
    }
    int mid = (start + end) / 2;
    update(index * 2, start, mid, cur);
    update(index * 2  + 1, mid + 1, end, cur);
    tree[index] = tree[index * 2] + tree[index * 2 + 1];
} 

ll sum(int index, int start, int end, int left, int right) {
    if(left <= start && end <= right) {
        return tree[index];
    }
    if(left > end || start > right) {
        return 0;
    }
    if(start == end) {
        return 0;
    }
    int mid = (start + end) / 2;
    return sum(index * 2, start, mid, left, right) + sum(index * 2 + 1, mid + 1, end, left, right);
}

int main() {
    scanf("%d", &N);
    for(int i=1; i<=N; i++) {
        scanf("%d", &Q[i].val);
        Q[i].cur = i;
    }
    sort(Q+1, Q+N+1, cmp);
    init(1, 1, N);

    ll ans = 0;
    ll beforeVal = 0;
    ll beforeCur = 0;
    ll loop = N;
    ll total = 0;
    for(int i=1; i<=N; i++) {
        if (Q[i].val != beforeVal) {
            ans += loop * (Q[i].val - 1 - beforeVal) + total;
            total = sum(1, 1, N, 1, N);
        }
        answer[Q[i].cur] = ans + sum(1, 1, N, 1, Q[i].cur);
        update(1, 1, N, Q[i].cur);
        loop = N-i;
        beforeVal = Q[i].val;
    }

    for(int i=1; i<=N; i++) {
        printf("%lld\n", answer[i]);
    }

}