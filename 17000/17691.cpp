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
    int x_lo, x_hi;
    int y;
    int idx;

    Line(int x_lo, int x_hi, int y, int idx) {
        this->x_lo = x_lo;
        this->x_hi = x_hi;
        this->y = y;
        this->idx = idx;
    }
};

bool cmp(struct Line &a, struct Line &b) {
    return a.x_lo != b.x_lo ? a.x_lo < b.x_lo : a.x_hi > b.x_hi;
}

class UnionFind {
public:
    int p[100001];
    int N;
    UnionFind(int N) {
        this->N = N;
        for(int i=1; i<=N; i++) {
            p[i] = i;
        }
    }

    int parent(int a) {
        if(p[a] == a) {
            return a;
        }
        return p[a] = parent(p[a]);
    }

    void merge(int a, int b) {
        if(isSameGroup(a, b)) return;
        int pA = parent(a);
        int pB = parent(b);
        p[pA] = pB;
        return;
    }

    bool isSameGroup(int a, int b) {
        return parent(a) == parent(b);
    }

};

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int N, Q; cin >> N >> Q;
    UnionFind uf(N);
    vector<Line> v;
    int x_lo, x_hi, y;
    for(int i=1; i<=N; i++) {
        cin >> x_lo >> x_hi >> y;
        v.push_back(Line(x_lo, x_hi, y, i));
    }

    sort(v.begin(), v.end(), cmp);

    int idx = 0;
    for(int i=1; i<v.size(); i++) {
        x_lo = v[i].x_lo;
        x_hi = v[i].x_hi;
        y = v[i].y;

        while(idx < i && x_lo > v[idx].x_hi) {
            idx++;
        }
        if(idx == i) continue;
        if(v[idx].x_lo <= x_lo && x_lo <= v[idx].x_hi) {
            uf.merge(v[idx].idx, v[i].idx);
        } 
    }


    for(int i=1; i<=Q; i++) {
        int a, b; cin >> a >>b;
        cout << uf.isSameGroup(a, b) << "\n";
    }
    
    // for(int i=1; i<=N; i++) {
    //     cout << i << " " << uf.parent(i) << "\t";
    // }

    cout << "\n";

    
}