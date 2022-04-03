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

int tree[12001];

void clear_tree() {
    for(int i=0; i<12001; i++) tree[i] = 0;
}

void update(int index, int start, int end, int cur) {
    if(start <= cur && cur <= end) tree[index]++;
    if(cur < start || cur > end) return;
    if(start == end) return;
    int mid = (start + end) / 2;
    update(index * 2, start, mid, cur);
    update(index * 2 + 1, mid + 1, end, cur);
}

int sum(int index, int start, int end, int left, int right) {
    if(left <= start && end <= right) {
        return tree[index];
    }
    if(end < left || start > right) return 0;
    if(start == end) return 0;
    int mid = (start + end) / 2;
    return sum(index * 2, start, mid, left, right) + sum(index * 2 + 1, mid + 1, end, left, right);
}

struct Cow{
    int x, y;
    int cx, cy;
};

bool cmp(struct Cow &a, struct Cow &b) {
    return a.cy == b.cy? a.cx < b.cx : a.cy < b.cy;
}

bool sortX(struct Cow &a, struct Cow &b){
    return a.x < b.x;
}

bool sortY(struct Cow &a, struct Cow &b){
    return a.y < b.y;
}

vector<struct Cow> cow;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int N; cin >> N;
    for(int i=0; i<N; i++) {
        Cow temp; cin >> temp.x >> temp.y;
        cow.push_back(temp);
    }

    sort(cow.begin(), cow.end(), sortX);
    int idx = 1;
    for(int i=0; i<N; i++) {
        if(i==0 || cow[i].x != cow[i-1].x) {
            cow[i].cx = idx++;
        }
        else {
            cow[i].cx = idx - 1;
        }
    }

    sort(cow.begin(), cow.end(), sortY);
    idx = 1;
    for(int i=0; i<N; i++) {
        if(i==0 || cow[i].y != cow[i-1].y) {
            cow[i].cy = idx++;
        }
        else {
            cow[i].cy = idx - 1;
        }
    }

    sort(cow.begin(), cow.end(), cmp);
    long long ans = 0;
    for(int i=0; i<N; i++) {
        clear_tree();
        long long tmp = 0;
        for(int j=i; j<N; j++) {
            int lx = min(cow[i].cx, cow[j].cx);
            int rx = max(cow[i].cx, cow[j].cx);

            int left = sum(1, 0, N + 1, 0, lx - 1) + 1;
            int right = sum(1, 0, N + 1, rx + 1, N + 1) + 1;
            tmp += (long long)left * right;
            update(1, 0, N + 1, cow[j].cx);
        }
        // cout << tmp << "\n";
        ans += tmp;
    }
    cout << ans + 1 << "\n";

}