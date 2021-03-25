//# Author : nuclear852 ========================#
//# Solution : 23406017 ========================#
//# Time Stamp : 2020-10-22 18:50:59 ===========#
//# Problem Title : 수열과 쿼리 4 ===============#
//# Language : C++14 ===========================#

#include <stdio.h>
#include <list>
#include <algorithm>
#include <math.h>

using namespace std;

int N, K, M;
int arr[101001];
list<int> li[101001];

int bket[101001];
int Sbket[101001];
int ans[101001];

int sq;

struct Query {
    int left, right, index;
}Q[100001];

bool cmp(const Query& a, const Query& b) {
    int A = a.right / sq;
    int B = b.right / sq;
    return A == B ?  a.left < b.left : A < B;
}

void f(int index, bool add, bool isLeft) {
    int val = 0;
    //printf("%d %d %d \n", index, add, isLeft);
    if(add == true) {
        if(li[arr[index]].size() > 0) {
            val = li[arr[index]].back() - li[arr[index]].front();
            bket[val]--;
            Sbket[val/sq]--;
        }
        if(isLeft) li[arr[index]].push_front(index);
        else li[arr[index]].push_back(index);
        val = li[arr[index]].back() - li[arr[index]].front();
        bket[val]++;
        Sbket[val/sq]++;
    }
    else {
        val = li[arr[index]].back() - li[arr[index]].front();
        bket[val]--;
        Sbket[val/sq]--;
        if(isLeft) li[arr[index]].pop_front();
        else li[arr[index]].pop_back();
        if(li[arr[index]].size() > 0) {
            val = li[arr[index]].back() - li[arr[index]].front();
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
    // for(int i=1; i<=M; i++) {
    //     printf("%d %d\n", Q[i].left, Q[i].right);
    // }
    
    int sLeft = Q[1].left, sRight = Q[1].right;
    for(int i=sLeft; i<=sRight; i++) {
        f(i, true, false);
    }
    ans[Q[1].index] = find_ans();

    int low = sLeft, high = sRight;
    for(int i=2; i<=M; i++) {
        while(low > Q[i].left) {
            f(--low, true, true);
        }
        while(high < Q[i].right) {
            f(++high, true, false);
        }
        while(low < Q[i].left) {
            f(low++, false, true);
        }
        while(high > Q[i].right) {
            f(high--, false, false);
        }
        ans[Q[i].index] = find_ans();
        //printf("=====================\n");
    }
    for(int i=1; i<=M; i++) {
        printf("%d\n", ans[i]);
    }
}