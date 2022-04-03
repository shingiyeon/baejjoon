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

bool cmp(pair<int, int> &a, pair<int, int> &b) {
    return a.second > b.second;
}

vector< pair<int, int> > cow;
vector<int> chk;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int N, C; cin >> C >> N;
    for(int i=0; i<C; i++) {
        int tmp;
        cin >> tmp;
        chk.push_back(tmp);
    }
    for(int i=0; i<N; i++) {
        pair<int, int> tmp;
        cin >> tmp.first >> tmp.second;
        cow.push_back({tmp.first, tmp.second});
    }

    int ans = 0;
    sort(cow.begin(), cow.end(), cmp);
    sort(chk.begin(), chk.end());
    
    priority_queue< pair<int, int>, vector<pair<int, int> >, less<pair<int, int> > > pq;
    int cowIndex = 0;
    for(int i = C-1; i >= 0; i--) {
        int time = chk[i];
        while(cowIndex < N && time <= cow[cowIndex].second) {
            if(time >= cow[cowIndex].first) pq.push(cow[cowIndex]);
            cowIndex++;
        }

        while(!pq.empty()) {
            pair<int, int> cur = pq.top(); pq.pop();
            if(cur.first <= time && time <= cur.second) {
                ans++; break;
            }
        }

    }

    cout << ans;


}