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

ll check(vector<int> &v, int sz) {
    ll time = 0;
    priority_queue<ll, vector<ll>, greater<ll> > pq;
    int idx = sz;
    for(int i=0; i<sz; i++) {
        pq.push(v[i]);
    }
    while(!pq.empty()) {   
        ll cur_time = pq.top(); pq.pop();
        time = max(time, cur_time);
        if(idx < v.size()) {
            pq.push(v[idx++] + cur_time);
        }
    }
    return time;
}

int bs(vector<int> &v, ll &t) {
    int N = v.size(); 
    int start = 1; int end = N;
    while(start <= end) {
        int mid = (start + end) / 2;
        // cout << start << " " << mid << " " << end << "\n";
        ll cur_t = check(v, mid);
        if(cur_t <= t) {
            end = mid - 1;
        }
        else {
            start = mid + 1;
        }
        
        // cout << start << " " << mid << " " << end << "\n\n";
    }
    return start;
}


int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    int N; ll T; cin >> N >> T;
    vector<int> arr; int tmp;
    for(int i=0; i<N; i++) {
        cin >> tmp; arr.push_back(tmp);
    }
    cout << bs(arr, T);
}