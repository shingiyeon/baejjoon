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
struct Mask{
    ll L, R;
};

struct Civil{
    ll P; int X;
};

struct compare {
    bool operator()(const struct Mask& x, const struct Mask& y) {
        return x.R > y.R;
    }
};

bool comMask(const struct Mask& x, const struct Mask& y) {
    return x.L < y.L;
}

bool comCivil(const struct Civil& x, const struct Civil& y) {
    return x.P < y.P;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int N, M;
    cin >> N >> M;

    vector<struct Mask> mask;
    vector<struct Civil> civil;

    for(int i=0; i<N; i++) {
        Mask tmp; cin >> tmp.L >> tmp.R;
        mask.push_back(tmp);
    }

    for(int i=0; i<M; i++) {
        Civil tmp; cin >> tmp.P >> tmp.X;
        civil.push_back(tmp);
    }

    sort(mask.begin(), mask.end(), comMask);
    sort(civil.begin(), civil.end(), comCivil);

    priority_queue<struct Mask, vector<struct Mask>, compare> pq;

    long long ans = 0;
    int idx = 0;
    for(auto c: civil) {
        while(idx < N && c.P >= mask[idx].L) {
            if(c.P <= mask[idx].R) {
                pq.push(mask[idx]);
            }
            idx++;
        }
        while(!pq.empty()) {
            Mask cur = pq.top(); pq.pop();
            if(cur.L <= c.P && c.P <= cur.R) {
                ans++; c.X--;
            }
            if(c.X == 0) break;
        }
    }

    cout << ans;




}