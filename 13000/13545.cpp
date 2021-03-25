//# Author : nuclear852 ========================#
//# Solution : 23577812 ========================#
//# Time Stamp : 2020-11-01 01:30:21 ===========#
//# Problem Title : 수열과 쿼리 0 ===============#
//# Language : C++17 ===========================#

#include <stdio.h>
#include <list>
#include <math.h>
#include <algorithm>

using namespace std;

int arr[101001];
int sum[101001];
list<int> li[201001];

int bket[201001];
int Sbket[201001];
int ans[101001];

int N, M;
int sq;

struct Query {
    int left, right, index;
}Q[100001];

bool cmp(const struct Query &a, const struct Query &b) {
    int aS = a.right / sq;
    int bS = b.right / sq;

    return aS == bS ? a.left < b.left : aS < bS;
}

void f(int index, bool add, bool isLeft) {
    int val;
    list<int> &tmp = li[sum[index]+100000];
    if (add) {
        if(tmp.size() > 0) {
            val = tmp.back() - tmp.front();
            bket[val]--;
            Sbket[val/sq]--;
        }
        if(isLeft) tmp.push_front(index);
        else tmp.push_back(index);
        val = tmp.back() - tmp.front();
        bket[val]++;
        Sbket[val/sq]++;
    }
    else {
        val = tmp.back() - tmp.front();
        bket[val]--;
        Sbket[val/sq]--;
        if(isLeft) tmp.pop_front();
        else tmp.pop_back();
        if(tmp.size() > 0) {
            val = tmp.back() - tmp.front();
            bket[val]++;
            Sbket[val/sq]++;
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
    scanf("%d", &N);
    for(int i=1; i<=N; i++) {
        scanf("%d", &arr[i]);
        sum[i] = arr[i] + sum[i-1];
    }
    sq = (int)sqrt(N);
    scanf("%d", &M);
    for(int i=1; i<=M; i++) {
        int l, r;
        scanf("%d%d", &l, &r);
        Q[i].left = l-1; Q[i].right = r;
        Q[i].index = i;
    }
    sort(Q+1, Q+M+1, cmp);

    for(int i=Q[1].left; i<=Q[1].right; i++) {
        f(i, true, false);
    }

    ans[Q[1].index] = find_ans();

    int left = Q[1].left, right = Q[1].right;
    for(int i=2; i<=M; i++) {
        while(Q[i].left < left) {
            f(--left, true, true);
        }
        while(Q[i].right > right) {
            f(++right, true, false);
        }
        while(Q[i].left > left) {
            f(left++, false, true);
        }
        while(Q[i].right < right) {
            f(right--, false, false);
        }
        ans[Q[i].index] = find_ans();
    }

    for(int i=1; i<=M; i++) {
        printf("%d\n", ans[i]);
    }

}