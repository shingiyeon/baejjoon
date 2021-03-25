//# Author : nuclear852 ========================#
//# Solution : 23590401 ========================#
//# Time Stamp : 2020-11-01 22:20:16 ===========#
//# Problem Title : 수열과 쿼리 7 ===============#
//# Language : C++17 ===========================#

#include <stdio.h>
#include <list>
#include <algorithm>
#include <math.h>
using namespace std;

int arr[101010];
int sum[101010];
list<int> li[1000001];

int bket[101010];
int Sbket[101010];
int ans[101010];

int N, K, M;
int sq;

struct Query {
    int left, right, index;
}Q[101010];

bool cmp(const struct Query& a, const struct Query& b) {
    int aR = a.right / sq;
    int bR = b.right / sq;

    return aR == bR ? a.left < b.left : aR < bR;
}

void f(int index, bool add, bool isLeft) {
    list<int> &l = li[sum[index]];
    int val = 0;
    if(add) {
        if(l.size() > 0) {
            val = l.back() - l.front();
            bket[val]--; Sbket[val/sq]--;
        }
        if(isLeft) l.push_front(index);
        else l.push_back(index);
        val = l.back() - l.front();
        bket[val]++; Sbket[val/sq]++;
    }
    else {
        val = l.back() - l.front();
        bket[val]--; Sbket[val/sq]--;
        if(isLeft) l.pop_front();
        else l.pop_back();
        if(l.size() > 0) {
            val = l.back() - l.front();
            bket[val]++; Sbket[val/sq]++;
        }
    }
} 

int find_ans() {
    for(int i=sq+10; i>=0; i--) {
        if(Sbket[i] > 0) {
            for(int j=sq-1; j>=0; j--) {
                if(bket[i*sq+j] > 0) {
                    return i*sq+j;
                }
            }
        }
    }
    return 0;
}

int main() {
    scanf("%d%d", &N, &K);
    sq = (int)sqrt(N);
    for(int i=1; i<=N; i++) scanf("%d", &arr[i]);
    for(int i=1; i<=N; i++) sum[i] = (arr[i] + sum[i-1]) % K;
    scanf("%d", &M);
    for(int i=1; i<=M; i++) {
        int l, r; scanf("%d%d", &l, &r);
        Q[i].left = l-1; Q[i].right = r; Q[i].index = i;
    }
    sort(Q+1, Q+M+1, cmp);

    int low = Q[1].left, high = Q[1].right;
    for(int i=low; i<=high; i++) {
        f(i, true, false);
    }
    ans[Q[1].index] = find_ans();

    for(int i=2; i<=M; i++) {
        while(Q[i].left < low) {
            f(--low, true, true);
        }
        while(Q[i].right > high) {
            f(++high, true, false);
        }
        while(Q[i].left > low) {
            f(low++, false, true);
        }
        while(Q[i].right < high) {
            f(high--, false, false);
        }
        ans[Q[i].index] = find_ans();
    }

    for(int i=1; i<=M; i++) {
        printf("%d\n", ans[i]);
    }

}