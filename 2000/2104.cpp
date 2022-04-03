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
typedef long long ll;

int N;
ll arr[101010];
ll sum[101010];
pair<ll, int> min_tree[404040];
ll ans = 0;
void init(int index, int start, int end) {
    if(start == end) {
        min_tree[index] = {arr[start], start};
        return;    
    }
    int mid = (start + end) / 2;
    init(index * 2, start, mid);
    init(index * 2 + 1, mid + 1, end);
    if(min_tree[index*2].first < min_tree[index*2+1].first) {
        min_tree[index] = min_tree[index * 2];
    }
    else {
        min_tree[index] = min_tree[index * 2 + 1];
    }
    return;
}

pair<ll, int> find_minValue(int index, int start, int end, int left, int right) {
    if(left > end || right < start) {
        return {1000001, 0};
    }
    if(left <= start && end <= right) {
        return min_tree[index];
    }
    if(start == end) return {1000000, 0};
    int mid = (start + end) / 2;
    auto lT = find_minValue(index * 2, start, mid, left, right);
    auto rT = find_minValue(index * 2 + 1, mid + 1, end, left, right);

    if(lT.first < rT.first) {
        return lT;
    }
    else {
        return rT;
    }
}

void find(int start, int end) {
    // cout << start << " " << end << "\n";
    if(start > end) return;
    auto minT = find_minValue(1, 1, N, start, end);
    ans = max(ans, (sum[end] - sum[start - 1]) * minT.first);
    find(start, minT.second - 1);
    find(minT.second+1, end);
    return;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> N;
    for(int i=1; i<=N; i++) cin >> arr[i];
    for(int i=1; i<=N; i++) sum[i] = sum[i-1] + arr[i];
    init(1, 1, N);
    find(1, N);
    cout << ans;

    
}