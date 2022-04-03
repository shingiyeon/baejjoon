#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <functional>
#include <queue>
#include <stack>
#include <string>
using namespace std;

int N;
int arr[1000005];
int tree[4004040];

void update(int index, int start, int end, int cur) {
    if(start <= cur && cur <= end) {
        tree[index]++;
    }
    else {
        return;
    }
    if(start == end) return;
    int mid = (start + end) / 2;
    update(index * 2, start, mid, cur);
    update(index * 2  + 1, mid + 1, end, cur);
    tree[index] = tree[index * 2] + tree[index * 2 + 1];
}

int find(int index, int start, int end, int left, int right) {
    if(left <= start && end <= right) {
        return tree[index];
    }
    else if(end < left || start > right) return 0;
    int mid = (start + end) / 2;
    return find(index * 2, start, mid, left, right) + find(index * 2 + 1, mid + 1, end, left, right);
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> N;
    for(int i=1; i<=N; i++) cin >> arr[i];

    long long ans = 0;  
    for(int i=1; i<=N; i++) {
        ans += (long long)find(1, 1, N, arr[i], N);
        update(1, 1, N, arr[i]);
    }
    cout << ans;
}