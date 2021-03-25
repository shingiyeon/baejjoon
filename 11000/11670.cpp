//# Author : nuclear852 ========================#
//# Solution : 26192330 ========================#
//# Time Stamp : 2021-02-09 09:33:46 ===========#
//# Problem Title : 초등 수학 ==================#
//# Language : C++17 ===========================#

#include <iostream>
#include <map>
#include <vector>
#include <queue>
typedef long long ll;
using namespace std;

map<ll, int> m;
map<int, ll> rm;
int N;
struct Query{
    int left, right;
}Q[2501];

vector<int> adj[2501];
int idx = 2501;
int checked[2501];
int lv[2501];
int aMatched[2501];
int bMatched[10501];

void add(int e_idx, ll num) {
    if(m.find(num) == m.end()) {
        rm[idx] = num;
        m[num] = idx++;
    }
    adj[e_idx].push_back(m[num]);
}

void bfs() {
    queue<int> q;
    for(int i=1; i<=N; i++) {
        if(aMatched[i] == -1) {
            lv[i] = 0;
            q.push(i);
        }
        else {
            lv[i] = -5;
        }
    }
    while(!q.empty()) {
        int cur = q.front(); q.pop();
        for(auto next: adj[cur]) {
            if(bMatched[next] != -1 && lv[bMatched[next]] == -5) {
                lv[bMatched[next]] = lv[cur] + 1;
                q.push(bMatched[next]);
            }
        }
    }
}

bool dfs(int cur) {
    for(int &i= checked[cur]; i < adj[cur].size(); i++) {
        int next = adj[cur][i];
        if(bMatched[next] == - 1) {
            aMatched[cur] = next;
            bMatched[next] = cur;
            return 1;
        }
        else if(lv[bMatched[next]] == lv[cur] + 1 && dfs(bMatched[next])) {
            aMatched[cur] = next;
            bMatched[next] = cur;
            return 1;
        }
    }
    return 0;
}


int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> N;
    for(int i=1; i<=N; i++) cin>>Q[i].left>>Q[i].right;
    int idx = 2501;
    for(int i=1; i<=N; i++) {
        add(i, (ll)Q[i].left+Q[i].right);
        add(i, (ll)Q[i].left-Q[i].right);
        add(i, (ll)Q[i].left*Q[i].right);
    }

    for(int i=0; i<=2500; i++) aMatched[i] = -1;
    for(int i=0; i<=10500; i++) bMatched[i] = -1;
    int total_flow = 0;
    while(true) {
        int flow = 0;
        for(int i=0; i<=2500; i++) checked[i] = 0;
        bfs();
        for(int i=1; i<=N; i++) {
            if(aMatched[i] == -1 && dfs(i)) flow++;
        }
        if(!flow) break;
        total_flow += flow;
    }
    if( total_flow < N) {
        cout << "impossible";
    }
    else {
        for(int i=1; i<=N; i++) {
            if ( rm[aMatched[i]] == (ll)Q[i].left + Q[i].right) {
                cout << Q[i].left << " + " << Q[i].right << " = " << rm[aMatched[i]] << "\n";
            }
            else if ( rm[aMatched[i]] == (ll)Q[i].left - Q[i].right) {
                cout << Q[i].left << " - " << Q[i].right << " = " << rm[aMatched[i]] << "\n";
            }
            else{
                cout << Q[i].left << " * " << Q[i].right << " = " << rm[aMatched[i]] << "\n";
            }
        }
    }
    return 0;
}