//# Author : nuclear852 ========================#
//# Solution : 23247253 ========================#
//# Time Stamp : 2020-10-14 23:42:34 ===========#
//# Problem Title : 금광 =====================#
//# Language : C++14 ===========================#

#include <stdio.h>
#include <vector>
#include <algorithm>
typedef long long ll;
using namespace std;

struct Point{
    int ox, w;
    int x, y;
}P[3001];

bool oxcmp(struct Point& a, struct Point& b) {
    return a.ox < b.ox;
}

bool ycmp(struct Point& a, struct Point& b) {
    return a.y < b.y;
}

vector<Point> v[3000];
int v_size = 0;
ll sum[12020];
ll lsum[12020];
ll rsum[12020];
ll maxsum[12020];
int N;

void init() {
    for(int i=0; i<12020; i++) sum[i] = lsum[i] = rsum[i] = maxsum[i] = 0;
}

void update(int index, int start, int end, int cur, int val) {
    if(cur < start || end < cur) return;
    if(start == end) {
        sum[index] += (ll)val;
        lsum[index] += (ll)val;
        rsum[index] += (ll)val;
        maxsum[index] += (ll)val;
        return;
    }
    int mid = (start + end) / 2;
    update(index * 2, start, mid, cur, val);
    update(index * 2 + 1, mid + 1, end, cur, val);
    sum[index] = sum[index*2] + sum[index*2+1];
    lsum[index] = max(lsum[index*2], sum[index*2] + lsum[index*2+1]);
    rsum[index] = max(rsum[index*2+1], sum[index*2+1] + rsum[index*2]);
    maxsum[index] = max(max(rsum[index*2] + lsum[index*2+1], sum[index]), max(maxsum[index*2], maxsum[index*2+1]));
}

int main() {
    scanf("%d", &N);
    for(int i=1; i<=N; i++) {
        scanf("%d%d%d", &P[i].ox, &P[i].y, &P[i].w);
    }
    sort(P+1, P+N+1, oxcmp);
    // for(int i=1; i<=N; i++) {
    //     printf("%d ", P[i].ox);
    // }
    // printf("\n");
    for(int i=1; i<=N; i++) {
        if(i==1) P[i].x = 1;
        else {
            if(P[i-1].ox == P[i].ox) P[i].x = P[i-1].x;
            else P[i].x = P[i-1].x + 1;
        }
    }
    sort(P+1, P+N+1, ycmp);
    for(int i=1; i<=N; i++) {
        if(!v_size) v[v_size++].push_back(P[i]);
        else {
            if( v[v_size-1][0].y == P[i].y) v[v_size-1].push_back(P[i]);
            else v[v_size++].push_back(P[i]);
        }
    }

    // for(int i=0; i<v_size; i++) {
    //     for(auto val: v[i]) {
    //         printf("%d %d %d %d   \t", val.ox, val.x, val.y, val.w);
    //     }
    //     printf("\n");
    // }

    long long ans = 0;
    //printf("%d\n", v_size);
    for(int i=0; i<v_size; i++) {
        init();
        for(int j=i; j<v_size; j++) {
            for(auto val: v[j]) {
                update(1, 1, N, val.x, val.w);
            }
            //printf("%lld\n", maxsum[1]);
            ans = max(ans, maxsum[1]);
        }
    }
    printf("%lld", ans);
}