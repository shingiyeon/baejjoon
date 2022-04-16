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

pair<int, int> tree[88000];

class Line {
public:
    int x, y_lo, y_hi;
    int flag;
    
    Line(int _x, int _y_lo, int _y_hi, int _flag) {
        x = _x;
        y_lo = _y_lo;
        y_hi = _y_hi;
        flag = _flag;
    }
};

bool cmp(class Line &A, class Line &B) {
    return A.x < B.x;
}

void update(int index, int start, int end, int left, int right, int flag) {
    if(right < start || left > end) return;
    if(left <= start && end <= right) {
        tree[index].second += flag;
    } else {
        int mid = (start + end) / 2;
        update(index * 2, start, mid, left, right, flag);
        update(index * 2 + 1, mid + 1, end, left, right, flag);
    }

    if(tree[index].second >= 1) {
        tree[index].first = end - start + 1;
    } else {
        if(start == end) {
            tree[index].first = 0;
        } else {
            tree[index].first = tree[index * 2].first + tree[index * 2 + 1].first;
        }
    }

}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    vector<Line> v;
    int N; cin >> N;
    double x, y, w, h;
    for(int i=0; i<N; i++) {
        cin >> x >> y >> w >> h;
        x *= 10; y *= 10; w *= 10; h *= 10;
        v.push_back(Line((int)x, (int)y, (int)(y + h - 1), 1));
        v.push_back(Line((int)(x + w), (int)y, (int)(y + h - 1), -1));
    }

    for(int i=0; i<88000; i++) {
        tree[i].first = tree[i].second = 0;
    }

    sort(v.begin(), v.end(), cmp);

    // for(auto inf: v) {
    //     cout << inf.x << " " << inf.y_lo << " " << inf.y_hi << " " << inf.flag << "\n";
    // }

    int ans = 0;
    int lastX = v[0].x;
    for(int i=0; i<v.size(); i++) {
        int x = v[i].x;
        int y_lo = v[i].y_lo; int y_hi = v[i].y_hi;
        int flag = v[i].flag;
        ans += (x - lastX) * (tree[1].first);
        update(1, 0, 20000, y_lo, y_hi, flag);
        lastX = x;
    }
    // cout << ans << "\n";
    // cout << (ans % 100) << "\n";
    if(ans % (long long)100 == 0) {
        cout << ans / 100;
    } else {
        cout << fixed;
        cout.precision(2);
        cout << (double)ans / 100;
    }

}