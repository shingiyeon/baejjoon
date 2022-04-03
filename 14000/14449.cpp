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

int tree[404040];

void update(int index, int start, int end, int cur) {
    if(cur < start || cur > end) return;
    if(start == end) {
        tree[index]++;
        return;
    }
    if(start <= cur && cur <= end) {
        tree[index]++;
    }
    int mid = (start + end) / 2;
    update(index * 2, start, mid, cur);
    update(index * 2 + 1, mid + 1, end, cur);
}

int sum(int index, int start, int end, int left, int right) {
    if(left <= start && end <= right) {
        return tree[index];
    }
    if(end < left || right < start) {
        return 0;
    }
    if(start == end) {
        return 0;
    }
    int mid = (start + end) / 2;
    return sum(index * 2, start, mid, left, right) + sum(index * 2 + 1, mid+ 1, end, left, right);
}


struct Num {
    int num, x;
    int idx;
};

bool cmp(const struct Num& x, const struct Num& y) {
    return x.num < y.num;
}

bool cmp2(const struct Num& x, const struct Num& y) {
    return x.idx < y.idx;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int N; cin >> N;
    vector<Num> num;
    for(int i=0; i<N; i++) {
        struct Num tmp; cin >> tmp.num;
        tmp.idx = i;
        num.push_back(tmp);
    }

    sort(num.begin(), num.end(), cmp);
    for(int i=0; i<num.size(); i++) {
        num[i].x = i + 1;
    }
    sort(num.begin(), num.end(), cmp2);

    int ans = 0;
    for(int i=0; i<num.size(); i++) {
        int l = sum(1, 1, N, num[i].x, N);
        int r = (N - num[i].x) - l;
        //cout << num[i].num << " " << num[i].x << " " << l << " " << r << "\n";
        if(l > 2 * r || r > 2 * l) {
            ans++;
        }
        update(1, 1, N, num[i].x);
    }

    cout << ans;
}