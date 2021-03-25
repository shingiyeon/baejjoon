//# Author : nuclear852 ========================#
//# Solution : 23331174 ========================#
//# Time Stamp : 2020-10-18 23:50:34 ===========#
//# Problem Title : 수열과 쿼리 22 ==============#
//# Language : C++14 ===========================#

#include <stdio.h>
#include <math.h>
#include <algorithm>

using namespace std;
int N, M;
int arr[100001];
long long ans[100001];
long long tree[400040];

struct UpdateQuery {
    int cur, val;
} UQ[101010];

struct FindQuery {
    int upindex, left, right, index;
} FQ[101010];

bool cmp(const FindQuery& a, const FindQuery& b) {
    return a.upindex < b.upindex;
}

void init(int index, int start, int end) {
    if(start == end) {
        tree[index] = (long long)arr[start];
        return;
    }
    int mid = (start + end) / 2;
    init(index * 2, start, mid);
    init(index * 2 + 1, mid + 1, end);
    tree[index] = tree[index * 2] + tree[index * 2 + 1];
}

void update(int index, int start, int end, int cur, int diff) {
    if(cur < start || cur > end) return;
    if(start <= cur && cur <= end) {
        tree[index] += (long long) diff;
    }
    if(start == end) return;
    int mid = (start + end) / 2;
    update(index * 2, start, mid, cur, diff);
    update(index * 2 + 1, mid + 1, end, cur, diff);
}

long long sum(int index, int start, int end, int left, int right) {
    if(end < left || start > right) return 0;
    if(left <= start && end <= right) {
        return tree[index];
    }
    if(start == end) return 0;
    int mid = (start + end) / 2;
    return sum(index * 2, start, mid, left, right) + sum(index * 2 + 1, mid + 1, end, left, right);
}

int main() {
    scanf("%d", &N);
    for(int i=1; i<=N; i++) {
        scanf("%d", &arr[i]);
    }
    scanf("%d", &M);
    int q, fqIdx = 1, uqIdx = 1;
    for(int i=1; i<=M; i++) {
        scanf("%d", &q);
        if(q == 1) {
            scanf("%d%d", &UQ[uqIdx].cur, &UQ[uqIdx].val);
            uqIdx++;
        }
        else {
            scanf("%d%d%d", &FQ[fqIdx].upindex, &FQ[fqIdx].left, &FQ[fqIdx].right);
            FQ[fqIdx].index = fqIdx++;
        }
    }
    init(1, 1, N);
    sort(FQ+1, FQ+fqIdx, cmp);

    // for(int i=1; i<fqIdx; i++) {
    //     printf("%d %d %d %d\n", FQ[i].upindex, FQ[i].left, FQ[i].right, FQ[i].index);
    // }

    uqIdx = 0;
    for(int i=1; i<fqIdx; i++) {
        if(uqIdx != FQ[i].upindex) {
            for(int j=uqIdx+1; j<=FQ[i].upindex; j++) {
                update(1, 1, N, UQ[j].cur, UQ[j].val - arr[UQ[j].cur]);
                arr[UQ[j].cur] = UQ[j].val;
            }
            uqIdx = FQ[i].upindex;
        }
        ans[ FQ[i].index ] = sum(1, 1, N, FQ[i].left, FQ[i].right);
    }
    for(int i=0; i<fqIdx-1; i++) {
        printf("%lld\n", ans[i]);
    }
}