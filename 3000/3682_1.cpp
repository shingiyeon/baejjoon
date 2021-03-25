//# Author : nuclear852 ========================#
//# Solution : 25639642 ========================#
//# Time Stamp : 2021-01-25 09:58:31 ===========#
//# Problem Title : 동치 증명 ==================#
//# Language : C++17 ===========================#

#include <stdio.h>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int T;

class SCC {
    private:
        int n, m;
        vector<vector<int> > adj;
        vector<vector<int> > scc;
        vector<int> iscc;
        vector<int> num;
        vector<int> gNum;
        bool inS[20005];
        stack<int> S;
        int cnt, s_cnt;

    public:
        SCC(int _n, int _m) {
            n = _n;
            m = _m;
            adj.resize(n + 5);
            scc.resize(n + 5);
            iscc.resize(n + 5);
            num.resize(n + 5);
            gNum.resize(n + 5);
            cnt = s_cnt = 0;
            for(int i=1; i<=n; i++) inS[i] = 0;
        }

        void insertEdge(int a, int b) {
            adj[a].push_back(b);
        }

        void dfs(int cur) {
            S.push(cur);
            num[cur] = ++cnt;
            gNum[cur] = num[cur];
            inS[cur] = true;

            for(auto next: adj[cur]) {
                if(!num[next]) {
                    dfs(next);
                    gNum[cur] = min(gNum[cur], gNum[next]);
                }
                else if(inS[next]) {
                    gNum[cur] = min(gNum[cur], num[next]);
                }
            }

            if(num[cur] == gNum[cur]) {
                s_cnt++;
                while(!S.empty()) {
                    int s_cur = S.top(); S.pop();
                    inS[s_cur] = false;
                    iscc[s_cur] = s_cnt;
                    scc[s_cnt].push_back(s_cur);
                    if(cur == s_cur) break;
                }
            }
        }

        void makeComponent() {
            for(int i=1; i<=n; i++) {
                if(!num[i]) dfs(i);
            }
        }

        int solve() {
            vector< vector<int> > scc_edge;
            vector<int> indeg;
            vector<int> outdeg;
            scc_edge.resize(s_cnt + 1);
            indeg.resize(s_cnt + 1);
            outdeg.resize(s_cnt + 1);
            int zero_indeg = 0;
            int zero_outdeg = 0;
            for(int i=1; i<=n; i++) {
                for(auto next: adj[i]) {
                    if(iscc[i] == iscc[next]) continue;
                    scc_edge[iscc[i]].push_back(iscc[next]);
                }
            }
            for(int i=1; i<=s_cnt; i++) {
                scc_edge[i].erase(unique(scc_edge[i].begin(), scc_edge[i].end()), scc_edge[i].end());
            }

            for(int i=1; i<=s_cnt; i++) {
                for(auto next: scc_edge[i]) {
                    outdeg[i]++;
                    indeg[next]++;
                }
            }

            for(int i=1; i<=s_cnt; i++) {
                if(!indeg[i]) zero_indeg++;
                if(!outdeg[i]) zero_outdeg++;
            }

            if(s_cnt == 1) {
                return 0;
            }
            else {
                return max(zero_indeg, zero_outdeg);
            }
            
        }

};

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> T;
    while(T--) {
        int n, m; cin >> n >> m;
        SCC* scc = new SCC(n, m);
        for(int i=0; i<m; i++) {
            int a, b; cin >> a >> b;
            scc->insertEdge(a, b);
        }
        scc->makeComponent();
        cout << scc->solve() << '\n';

        delete scc;
    }

}