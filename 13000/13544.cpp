//# Author : nuclear852 ========================#
//# Solution : 23088893 ========================#
//# Time Stamp : 2020-10-07 23:11:22 ===========#
//# Problem Title : 수열과 쿼리 3 ===============#
//# Language : C++14 ===========================#

#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

int arr[100001];
vector<int> tree[400010];
int N, M;

void init(int index, int start, int end) {
    if(start == end) {
        tree[index].push_back(arr[start]);
        return;
    }
    int mid = (start + end) / 2;
    init(index * 2, start, mid);
    init(index * 2 + 1, mid + 1, end);
    int Lindex = 0, Rindex = 0;
    vector<int> LT = tree[index*2];
    vector<int> RT = tree[index*2+1];
    while(Lindex < LT.size() && Rindex < RT.size()) {
        if (LT[Lindex] < RT[Rindex]) {
            tree[index].push_back(LT[Lindex++]);
        }
        else {
            tree[index].push_back(RT[Rindex++]);
        }
    }
    while(Lindex < LT.size()) {
        tree[index].push_back(LT[Lindex++]);
    }
    while(Rindex < RT.size()) {
        tree[index].push_back(RT[Rindex++]);
    }
}

int find(int index, int start, int end, int left, int right, int val) {
    if(left <= start && end <= right) {
        return tree[index].size() - (upper_bound(tree[index].begin(), tree[index].end(), val) - tree[index].begin());
    }
    if(end < left || start > right) {
        return 0;
    }
    if(start == end) return 0;
    int mid = (start + end) / 2;
    return find(index * 2, start, mid, left, right, val) + find(index * 2 + 1, mid + 1, end, left, right, val);
}

int main() {
    scanf("%d", &N);
    for(int i=1; i<=N; i++) scanf("%d", &arr[i]);
    init(1, 1, N);

    // for(int i=1; i<=30; i++) {
    //     if(tree[i].size()) {
    //         printf("%d : ", i);
    //         for(auto val: tree[i]) {
    //             printf("%d ", val);
    //         }
    //         printf("\n");
    //     }
    // }
    
    scanf("%d", &M);
    int a, b, c;
    int last_ans = 0;
    while(M--) {
        scanf("%d%d%d", &a, &b, &c);
        a = a ^ last_ans;
        b = b ^ last_ans;
        c = c ^ last_ans;

        last_ans = find(1, 1, N, a, b, c);
        printf("%d\n", last_ans);
    }
}