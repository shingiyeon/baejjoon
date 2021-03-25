//# Author : nuclear852 ========================#
//# Solution : 23635343 ========================#
//# Time Stamp : 2020-11-03 23:35:02 ===========#
//# Problem Title : 수열과 쿼리 8 ===============#
//# Language : C++17 ===========================#

#include <stdio.h>
#include <algorithm>
#include <math.h>

using namespace std;

int N, K, M;
int sq;
int arr[1000001];
long long tree[414141];
long long total = 0;
long long ans[100001];

struct Query {
    int left, right, index;
}Q[100001];

bool cmp(const struct Query& a, const struct Query& b) {
    int aR = a.right / sq;
    int bR = b.right / sq;
    return aR == bR ? a.left < b.left : aR < bR;
}
long long find(int index) {
    if(index < 0) return 0;
    long long res = 0;
    while(index > 0) {
        res += tree[index];
        index -= (index & -index);
    }
    return res;
}
void update(int index, int diff) {
    while(index <= 100000)  {
        tree[index] += (long long)diff;
        index += (index & -index);
    }
}

// void update(int index, int start, int end, int cur, int diff) {
//     if(start <= cur && cur <= end) {
//         tree[index] += diff;
//     }
//     if(cur < start || cur > end) return;
//     if(start == end) return;
//     int mid = (start + end) / 2;
//     update(index * 2, start, mid, cur, diff);
//     update(index * 2 + 1, mid + 1, end, cur, diff);
// }

// int find(int index, int start, int end, int left, int right) {
//     if(left <= start && end <= right) {
//         return tree[index];
//     }
//     if(end < left || start > right) {
//         return 0;
//     }
//     if(start == end) return 0;
//     int mid = (start + end) / 2;
//     return find(index * 2, start, mid, left, right) + find(index * 2 + 1, mid + 1, end, left, right);
// }


void f(int index, bool add) {
    if(add) {
        int left = arr[index] - K - 1;
        int right = min(100000, arr[index] + K );
        total += find(right) - find(left);
        update(arr[index], 1);
    }
    else {
        int left = arr[index] - K - 1;
        int right = min(100000, arr[index] + K);
        update(arr[index] , -1);
        total -= find(right) - find(left);
    }

}

int main() {
    scanf("%d%d", &N, &K);
    for(int i=1; i<=N; i++) {
        scanf("%d", &arr[i]);
    }
    sq = (int)sqrt(N);
    scanf("%d", &M);
    for(int i=1; i<=M; i++) {
        scanf("%d%d", &Q[i].left, &Q[i].right);
        Q[i].index = i;
    }
    sort(Q+1, Q+M+1, cmp);
    // for(int i=1; i<=M; i++) printf("%d ", Q[i].index);
    // printf("\n");
    int low = Q[1].left, high = Q[1].right;

    for(int i=low; i<=high; i++) {
        f(i, true);
    }
    ans[Q[1].index] = total;

    for(int i=2; i<=M; i++) {
        while(Q[i].left < low) {
            f(--low, true);
        }
        while(Q[i].right > high) {
            f(++high, true);
        }
        while(Q[i].left > low) {
            f(low++, false);
        }
        while(Q[i].right < high) {
            f(high--, false);
        }
        ans[Q[i].index] = total;
    }

    for(int i=1; i<=M; i++) {
        printf("%lld\n", ans[i]);
    }
}