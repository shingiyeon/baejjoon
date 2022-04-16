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

struct Line {
public:
    int x_lo, x_hi;
    Line(int x_lo, int x_hi) {
        this->x_lo = x_lo;
        this->x_hi = x_hi;
    }
};

class Compare {
    public:
        bool operator() (Line a, Line b) {
            return a.x_hi > b.x_hi;
        }
};

bool cmp(struct Line &a, struct Line &b) {
    return a.x_lo != b.x_lo ? a.x_lo < b.x_lo : a.x_hi > b.x_hi;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    int N; cin >> N;
    int x_lo, x_hi;
    vector<Line> v;
    for(int i=0; i<N; i++) {
        cin >> x_lo >> x_hi;
        v.push_back(Line(x_lo, x_hi));
    }
    sort(v.begin(), v.end(), cmp);
    priority_queue<Line, vector<Line>, Compare> s;

    int ans = 1;
    s.push(v[0]);
    for(int i=1; i<v.size(); i++) {
        // cout << s.top().x_hi << "\n";
        while(!s.empty() && s.top().x_hi <= v[i].x_lo) {
            s.pop();
        }
        ans = max(ans, (int)s.size() + 1);
        s.push(v[i]);
    }
    cout << ans << "\n";
}