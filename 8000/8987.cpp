//# Author : nuclear852 ========================#
//# Solution : 23163019 ========================#
//# Time Stamp : 2020-10-11 13:28:16 ===========#
//# Problem Title : 수족관 3 ==================#
//# Language : C++14 ===========================#

#include <stdio.h>
#include <queue>
#include <algorithm>
#include <utility>
#define INF 1000000001
using namespace std;

int N, K;
int x[300001];
int y[300001];
int p[300001];

priority_queue<long long> pq;

pair<int, int> tree[1200010];

void init(int index, int start, int end) {
    if(start == end) {
        tree[index] = {y[start], start};
        return;
    }
    int mid = (start + end) / 2;
    init(index * 2, start, mid);
    init(index * 2 + 1, mid + 1, end);
    tree[index] = tree[index*2].first < tree[index*2+1].first ? tree[index*2] : tree[index*2+1];
}

pair<int, int> find(int index, int start, int end, int left, int right) {
    if (left <= start && end <= right) {
        return tree[index];
    }
    if(start > right || end < left) return {INF, 0};
    if(start == end) return {INF, 0};
    int mid = (start + end) / 2;
    pair<int, int> LT = find(index * 2, start , mid , left, right);
    pair<int, int> RT = find(index * 2 + 1, mid + 1 , end , left, right);

    return LT.first < RT.first ? LT : RT;
}

long long area(int left, int right, int sumH) {
    if(left > right) return 0; 
    
    pair<int ,int> curTree = find(1, 1, (N/2) - 1, left, right);
    int height = curTree.first; int idx = curTree.second;
    long long curArea = (long long) (x[right + 1] - x[left]) * (height - sumH);

    long long lA = area(left, idx-1, height);
    long long rA = area(idx + 1, right, height);
    //printf("PUSH %lld\n", min(rA, lA));
    pq.push(min(rA, lA));
    //printf("%d %d %lld\n", left, right, curArea + max(lA, rA));
    return curArea + max(lA, rA);
}


int main() {
    scanf("%d", &N);
    for(int i=1; i<=(N/2); i++) {
        scanf("%d %d", &x[i], &y[i]);
        scanf("%d %d", &x[i], &y[i]);
    }

    init(1, 1, (N/2) - 1);

    scanf("%d", &K);
    long long ans = 0;
    long long a = area(1, (N/2)-1, 0);
    pq.push(a);
    while(K--&&!pq.empty()) {
        ans += pq.top();
        pq.pop();
    }
    printf("%lld", ans);

}