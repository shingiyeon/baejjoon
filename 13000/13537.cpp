//# Author : nuclear852 ========================#
//# Solution : 22975653 ========================#
//# Time Stamp : 2020-10-02 22:47:49 ===========#
//# Problem Title : 수열과 쿼리 1 ===============#
//# Language : C++14 ===========================#

#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
int arr[400010];
vector<int> tree[400010];

void init(int index, int start, int end) {
    if(start == end) {
        tree[index].push_back(arr[start]);
        return;
    }
    int mid = (start + end) / 2;
    init(index * 2 , start, mid);
    init(index * 2 +1 , mid + 1, end);

    int ltIdx = 0, rtIdx = 0;

    while(ltIdx < tree[index*2].size() && rtIdx < tree[index*2+1].size()) {
        if(tree[index*2][ltIdx] < tree[index*2+1][rtIdx]) {
            tree[index].push_back(tree[index*2][ltIdx++]);
        }
        else {
            tree[index].push_back(tree[index*2+1][rtIdx++]);
        }
    }
    for(;ltIdx < tree[index*2].size();ltIdx++) {
        tree[index].push_back(tree[index*2][ltIdx]);
    }
    for(;rtIdx < tree[index*2+1].size();rtIdx++) {
        tree[index].push_back(tree[index*2+1][rtIdx]);
    }
    return;
}

int find(int index, int start, int end, int left, int right, int value) {
    if(left <= start && end <= right) {
        // for(auto next: tree[index]) {
        //     printf("%d ", next);
        // }
        // printf("\n");
        // printf("%d %d %d %d\n",start, end, value, tree[index].size() - (lower_bound(tree[index].begin(), tree[index].end(), value) - tree[index].begin()));
        // printf("=====================\n");
        return tree[index].size() - (lower_bound(tree[index].begin(), tree[index].end(), value) - tree[index].begin());
    }
    if(end < left || right < start) {
        return 0;
    }
    if(start == end) return 0;
    int mid = (start + end) / 2;
    return find(index * 2 , start , mid, left, right, value) + find(index * 2 + 1, mid + 1, end, left, right, value);
}

int main() {
    scanf("%d", &N);
    for(int i=1; i<=N; i++) scanf("%d", &arr[i]);
    init(1, 1, N);
    scanf("%d", &M);
    int i,j,k;
    while(M--) {
        scanf("%d%d%d",&i,&j,&k);
        printf("%d\n", find(1, 1, N , i, j, k+1));
    }
}