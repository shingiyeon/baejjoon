//# Author : nuclear852 ========================#
//# Solution : 24522515 ========================#
//# Time Stamp : 2020-12-22 10:52:18 ===========#
//# Problem Title : 수족관 2 ==================#
//# Language : C++17 ===========================#

#include <stdio.h>
#include <queue>
#include <algorithm>
#include <utility>
#include <vector>
#include <tuple>
#define INF 1000000001
using namespace std;

int N, K;
vector<int> x;
vector<int> y;
bool hasHole[300001];

vector< tuple<int, int, int> > tree;

void init(int index, int start, int end) {
    if(start == end) {
        tree[index] = make_tuple(y[start], start, hasHole[start]);
        return;
    }
    int mid = (start + end) / 2;
    init(index * 2, start, mid);
    init(index * 2 + 1, mid + 1, end);
    get<0>(tree[index]) = min(get<0>(tree[index*2]), get<0>(tree[index*2+1]));
    get<1>(tree[index]) = get<0>(tree[index*2]) < get<0>(tree[index*2+1]) ? get<1>(tree[index*2]) : get<1>(tree[index*2+1]);
    get<2>(tree[index]) = get<2>(tree[index*2]) + get<2>(tree[index*2+1]);
}

tuple<int, int, int> find(int index, int start, int end, int left, int right) {
    if (left <= start && end <= right) {
        return tree[index];
    }
    if(start > right || end < left) return make_tuple(INF, 0, 0);
    if(start == end) return make_tuple(INF, 0, 0);
    int mid = (start + end) / 2;
    tuple<int, int, int> LT = find(index * 2, start , mid , left, right);
    tuple<int, int, int> RT = find(index * 2 + 1, mid + 1 , end , left, right);
    tuple<int, int, int> CT;
    get<0>(CT) = get<0>(LT) < get<0>(RT) ? get<0>(LT) : get<0>(RT);
    get<1>(CT) = get<0>(LT) < get<0>(RT) ? get<1>(LT) : get<1>(RT);
    get<2>(CT) = get<2>(LT) + get<2>(RT);
    return CT;
}

pair<pair<long long, long long>, double> area(int left, int right, int sumH) {
    if(left > right) return {{0, 0}, 0};
    long long wholeArea = 0;
    long long curArea = 0;
    double time = 0;
    tuple<int, int, int> curTree = find(1, 0, (N/2) - 2, left, right);
    int height = get<0>(curTree);
    int idx = get<1>(curTree);
    int holeNum = get<2>(curTree);
    if(holeNum) {
        curArea = (long long) (x[right + 1] - x[left]) * (height - sumH);
        time = (double) curArea / holeNum;
    }
    wholeArea = (long long) (x[right + 1] - x[left]) * (height - sumH);
   
    auto lA = area(left, idx-1, height);
    auto rA = area(idx + 1, right, height);
    return { {curArea + lA.first.first + rA.first.first, wholeArea + lA.first.second + rA.first.second}, time + max(lA.second, rA.second)};
}


int main() {
    scanf("%d", &N);
    tree.resize(4*N+4);
    for(int i=0; i<(N/2); i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        scanf("%d %d", &a, &b);
        x.push_back(a); y.push_back(b);
    }
    scanf("%d", &K);
    for(int i=1; i<=K; i++) {
        int a, b; scanf("%d%d", &a, &b);
        hasHole[lower_bound(x.begin(), x.end(), a) - x.begin()] = true;
        scanf("%d%d", &a, &b);    
    }
    init(1, 0, (N/2) - 2);

    auto ans = area(0, (N/2)-2, 0);
    printf("%.2lf\n%lld",ans.second,ans.first.second-ans.first.first);


}