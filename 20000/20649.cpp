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
typedef pair<int, int> pi;
#define MAX 0x7FFFFFFF

struct Cow{
    int x, y;
    int idx;
};

vector<struct Cow> cow[2];
int past_time[1001];
int parent[1001];
int ans[1001];

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    int N; cin >> N;
    for(int i=0; i<N; i++) {
        char c; Cow temp;
        cin >> c >> temp.x >> temp.y;
        past_time[i] = MAX;
        temp.idx = i;
        parent[i] = i;
        if(c == 'E') cow[0].push_back(temp);
        else cow[1].push_back(temp);
    }

    priority_queue< pair<pi, pi> > pq;
    for(int i=0; i<cow[0].size(); i++) {
        for(int j=0; j<cow[1].size(); j++) {
            Cow E = cow[0][i]; Cow N = cow[1][j];
            if(E.x <= N.x && E.y >= N.y) {
                if(N.x - E.x > E.y - N.y) {
                    pq.push({{-(N.x - E.x), 0}, {i, j}});
                }
                else if(N.x - E.x < E.y - N.y) {
                    pq.push({{-(E.y - N.y), 1}, {i, j}});
                }
            }
        }
    }

    while(!pq.empty()) {
        auto info = pq.top(); pq.pop();
        int time = -info.first.first;
        int dir = info.first.second;
        Cow E = cow[0][info.second.first];
        Cow N = cow[1][info.second.second];
        if(dir == 0 && past_time[E.idx] == MAX) {
            int cur_time = E.y - N.y;
            if(cur_time < past_time[N.idx]) {
                past_time[E.idx] = time;
                parent[E.idx] = N.idx;
            }
        }
        else if(dir == 1 && past_time[N.idx] == MAX){
            int cur_time = N.x - E.x;
            if(cur_time < past_time[E.idx]) {
                past_time[N.idx] = time;
                parent[N.idx] = E.idx;
            }
        }
    }

    for(int i=0; i<N; i++) {
        int idx = i;
        while(parent[idx] != idx) {
            ans[parent[idx]]++;
            idx = parent[idx];
        }
    }
    
    for(int i=0; i<N; i++) {
        cout << ans[i] << "\n";
    }

}