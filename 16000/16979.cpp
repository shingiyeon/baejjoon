//# Author : nuclear852 ========================#
//# Solution : 24106064 ========================#
//# Time Stamp : 2020-11-28 22:55:06 ===========#
//# Problem Title : 수열과 쿼리 23 ==============#
//# Language : C++17 ===========================#

#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <vector>

using namespace std;

int N, M;
int sq;

int tree[404040];
long long answer[101010];
long long cnt = 0;
int arr[101010];

struct Query {
    int left, right, index;
}Q[100001];

long long sum(int index) {
    if(index < 0) return 0;
    long long res = 0;
    while(index > 0) {
        res += (long long)tree[index];
        index -= (index & -index);
    }
    return res;
}

void update(int index, int diff) {
    while(index <= N) {
        tree[index] += diff;
        index += (index & -index);
    }
}


bool cmp(const struct Query& a, const struct Query& b) {
    int aR = a.right / sq;
    int bR = b.right / sq;

    return aR == bR ? a.left < b.left : aR < bR;
}


void f(int index, bool add, bool isRight) {
    if(add) {
        if(isRight) {
            //printf("Add  %lld\n", sum(N) - sum(arr[index]));
            cnt += sum(N) - sum(arr[index]);
        }
        else {
            //printf("Add  %lld\n", sum(arr[index] - 1));
            cnt += sum(arr[index] - 1);
        }
        update(arr[index], 1);

    }
    else {
        if(isRight) {
            //printf("Subtract %lld\n", sum(N) - sum(arr[index]));
            cnt -=  sum(N) - sum(arr[index]);
        }
        else {
            //printf("Subtract %lld\n", sum(arr[index]-1));
            cnt -=  sum(arr[index]-1);
        }
        update(arr[index], -1);

    }
}

int main() {
    vector<int> v;
    scanf("%d%d", &N, &M);
    sq = (int)sqrt(N);
    for(int i=1; i<=N; i++) {
        scanf("%d", &arr[i]);
        v.push_back(arr[i]);
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());

    for(int i=1; i<=N; i++) {
        arr[i] = lower_bound(v.begin(), v.end(), arr[i]) - v.begin() + 1;
    }

    for(int i=1; i<=M; i++) {
        scanf("%d%d", &Q[i].left, &Q[i].right);
        Q[i].index = i;
    }
    sort(Q+1, Q+M+1, cmp);


    int low = Q[1].left, high = Q[1].right;
    for(int i=low; i<=high; i++) {
        f(i, true, true);
    }
    answer[Q[1].index] = cnt;

    for(int i=2; i<=M; i++) {
        while(low > Q[i].left) {
            f(--low, true, false);
        }
        while(high < Q[i].right) {
            f(++high, true, true);
        }
        while(low < Q[i].left) {
            f(low++, false, false);
        }
        while(high > Q[i].right) {
            f(high--, false, true);
        }
        answer[Q[i].index] = cnt;
    } 
    for(int i=1; i<=M; i++) {
        printf("%lld\n", answer[i]);
    }

}