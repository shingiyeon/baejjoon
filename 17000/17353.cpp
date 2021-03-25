//# Author : nuclear852 ========================#
//# Solution : 26515575 ========================#
//# Time Stamp : 2021-02-18 22:42:19 ===========#
//# Problem Title : 하늘에서 떨어지는 1, 2, ..., R-L+1개의 별 #
//# Language : C++17 ===========================#

#include <iostream>
#include <vector>
typedef long long ll;
using namespace std;
int N, Q;
ll lazy[404040];
ll tree[404040];
ll arr[101010];

void init(int index, int start, int end) {
    if(start == end) {
        tree[index] = arr[start] - arr[start-1];
        return;
    }
    int mid = (start + end) / 2;
    init(index * 2, start, mid);
    init(index * 2 + 1, mid + 1, end);
    tree[index] = tree[index * 2] + tree[index * 2 + 1];
}

void propagation(int index, int start, int end, int left, int right) {
    if(lazy[index] != 0) {
        tree[index] += (end - start + 1) * lazy[index];
        if(start != end) {
            lazy[index * 2] += lazy[index];
            lazy[index * 2 + 1] += lazy[index];
        }
        lazy[index] = 0;
    }
}

void update(int index, int start, int end, int left, int right, ll diff) {
    propagation(index, start, end, left, right);
    if(right < start || left > end) return;
    if(left <= start && end <= right) {
        tree[index] += (end - start + 1) * diff;
        if(start != end) {
            lazy[index * 2] += diff;
            lazy[index * 2 + 1] += diff;
        }
        return;
    }
    if(start == end) return;
    int mid = (start + end) / 2;
    update(index * 2, start, mid, left, right, diff);
    update(index * 2 + 1, mid + 1, end, left, right, diff);
    tree[index] = tree[index * 2] + tree[index * 2 + 1];
}

ll find(int index, int start, int end, int left, int right) {
    propagation(index, start, end, left, right);
    if(right < start || left > end) return 0;
    if(left <= start && end <= right) {
        return tree[index];
    }
    if(start == end) return 0;
    int mid = (start + end) / 2;
    return find(index * 2, start, mid, left, right) + find(index * 2 + 1, mid + 1, end, left, right);
}

int main() {
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
    cin >> N; for(int i=1; i<=N; i++) cin >> arr[i];
    init(1, 1, N+1);
    cin >> Q;
    for(int i=1; i<=Q; i++) {
        int tmp, a, b; cin >> tmp;
        if(tmp == 1) {
            cin >> a >> b;
            update(1, 1, N+1, a, b, (ll)1);
            update(1, 1, N+1, b+1, b+1, (ll)-(b-a+1));

        }
        else {
            cin >> a;
            cout << find(1, 1, N+1, 1, a) << "\n";
        }
    }
}