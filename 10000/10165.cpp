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
typedef long long ll;
using namespace std;

struct Path {
    int idx;
    ll low, high;
}P[1000005];

bool ans[500005];

bool cmp(struct Path &a, struct Path &b) {
    return a.low != b.low? a.low < b.low : a.high > b.high;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int N, M;
    cin >> N >> M;
    for(int i=0; i<M; i++) {
        cin >> P[i].low >> P[i].high;
        if(P[i].high < P[i].low) {
            P[i].high += N;
        }
        P[i].idx = i;
        P[i+M].idx = i;
        P[i+M].low = N + P[i].low;
        P[i+M].high = N + P[i].high;
        ans[i] = true;
    }



    sort(P, P+2*M, cmp);
    // for(int i=0; i<2*M; i++) {
    //     cout << P[i].idx << " " << P[i].low << " " << P[i].high << "\n";
    // }
    int leftIdx = 0;
    int rightIdx = 0;
    for(int i=1; i<2*M; i++) {
        while(leftIdx < rightIdx && P[i].low > P[leftIdx].high) {
            leftIdx++;
        }
        // cout << "Index : " << leftIdx << " " << i << "\n";
        if(leftIdx == i) continue;
        if(P[leftIdx].low <= P[i].low && P[i].high <= P[leftIdx].high) {
            // cout << "leftIdx test: " << i << " " << P[i].idx << "\n";
            ans[P[i].idx] = false;
        } else if(P[rightIdx].low <= P[i].low && P[i].high <= P[rightIdx].high) {
            // cout << "rightIdx test: " << i << " " << P[i].idx << "\n";
            ans[P[i].idx] = false;
        } else {
            rightIdx = i;
        }
    }

    for(int i=0; i<M; i++) {
        if(ans[i]) {
            cout << i+1 << " ";
        }
    }

}