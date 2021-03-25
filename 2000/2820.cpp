//# Author : nuclear852 ========================#
//# Solution : 23223595 ========================#
//# Time Stamp : 2020-10-13 23:25:39 ===========#
//# Problem Title : 자동차 공장 =================#
//# Language : C++14 ===========================#

#include <stdio.h>
#include <vector>
#include <utility>
typedef long long ll;
using namespace std;

int N, M;

vector<int> adj[500001];
ll arr[500001];
ll lazy[2000020];
int map[500001];
int imap[500001];
int size[500001];

int index = 1;
int dfs(int val) {

    imap[index] = val;
    map[val] = index++;

    size[map[val]] = adj[val].size();
    for(auto next: adj[val]) {
        size[map[val]] += dfs(next);
    }
    return size[map[val]];
}

void update(int index, int start, int end, int left, int right, int val) {
    if(lazy[index] != 0) {
        if(start != end) {
            lazy[index * 2] += lazy[index];
            lazy[index * 2 + 1] += lazy[index];
        }
        else {
            arr[imap[start]] +=  lazy[index];
        }
        lazy[index] = 0;
    }

    if(left <= start && end <= right) {
        if (start != end) {
            lazy[index * 2] += (ll)val;
            lazy[index * 2 + 1] += (ll)val;
        }
        else {
            arr[imap[start]] += (ll)val;
        }
        return;
    }
    if(end < left || start > right) return;
    if(start == end) return;
    int mid = (start + end) / 2;
    update(index * 2, start, mid, left, right, val);
    update(index * 2 + 1, mid + 1, end, left, right, val);
}

ll find(int index, int start, int end, int cur) {
    if(lazy[index] != 0) {
        if(start != end) {
            lazy[index * 2] += lazy[index];
            lazy[index * 2 + 1] += lazy[index];
        }
        else {
            arr[imap[start]] +=  lazy[index];
        }
        lazy[index] = 0;
    }

    if(start == end) {
        return arr[imap[start]];
    }

    int mid = (start + end) / 2;
    if(start <= cur && cur <= mid) {
        return find(index * 2, start, mid, cur);
    }
    else {
        return find(index * 2 + 1, mid + 1, end, cur);
    }

}


int main() {
    scanf("%d%d", &N, &M);
    scanf("%lld", &arr[1]);
    int parent;
    for(int i=2; i<=N; i++) {
        scanf("%lld %d", &arr[i], &parent);
        adj[parent].push_back(i);
    }

    dfs(1);
    // for(int i=1; i<=N; i++) {
    //     printf("%d %d %lld\n", imap[i], size[i], arr[imap[i]]);
    // }

    char q;
    int a, x;
    while(M--) {
        scanf("\n%c", &q);
        if(q == 'p') {
            scanf("%d%d", &a, &x);
            if(!size[map[a]]) continue;
            update(1, 1, N, map[a]+1, map[a]+size[map[a]], x);
        }
        else {
            scanf("%d", &a);
            printf("%lld\n", find(1, 1, N, map[a]));
        }
    }


}