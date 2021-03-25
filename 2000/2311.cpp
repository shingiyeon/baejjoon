//# Author : nuclear852 ========================#
//# Solution : 25886363 ========================#
//# Time Stamp : 2021-01-31 23:12:58 ===========#
//# Problem Title : 왕복 여행 ==================#
//# Language : C++17 ===========================#

#include <iostream>
#include <vector>
#include <queue>
typedef long long ll;
using namespace std;

class SPFA {
    private:
        int N;
        int S, E;
        vector< vector<int> > adj;
        vector< vector<int> > c;
        vector< vector<int> > f;
        vector< vector<int> > d;
        vector<int> parent;
        vector<int> inQ;
        vector<int> dist;
        const int INF = 999999999;

    public:
        SPFA(int _N, int _S, int _E) {
            N = _N; S = _S; E = _E;
            adj.resize(N + 5);
            c.resize(N + 5, vector<int>(N+5));
            f.resize(N + 5, vector<int>(N+5));
            d.resize(N + 5, vector<int>(N+5));
            parent.resize(N+5);
            inQ.resize(N+5);
            dist.resize(N+5);
        }

        void addEdge(int a, int b, int cap, int dist) {
            adj[a].push_back(b);
            adj[b].push_back(a);
            c[a][b] = cap;
            d[a][b] = dist;
            d[b][a] = -dist;
        }

        int in(int x) {
            return x*2;
        }

        int out(int x) {
            return x*2+1;
        }

        void setBidirectionalEdge(int x) {
            c[in(x)][out(x)] = INF;
            adj[in(x)].push_back(out(x));
            adj[out(x)].push_back(in(x));
        }

        void addBidirectionalEdge(int a, int b, int cap, int dist) {
            addEdge(out(a), in(b), cap, dist);
            addEdge(out(b), in(a), cap, dist);
        }

        pair<ll, ll> getSPFA() {
            ll cost = 0, flow = 0;
            while(true) {
                for(int i=1; i<=N; i++) {
                    parent[i] = -1; inQ[i] = 0; dist[i] = INF;
                }
                parent[S] = parent[E] = -1;
                inQ[S] = inQ[E] = 0;
                dist[S] = dist[E] = INF;

                queue<int> q;
                q.push(S);
                inQ[S] = true;
                dist[S] = 0;

                while(!q.empty()) {
                    int cur = q.front(); q.pop();
                    inQ[cur] = false;
                    for(auto next: adj[cur]) {
                        if(c[cur][next] > f[cur][next] && dist[cur] + d[cur][next] < dist[next]) {
                            dist[next] = dist[cur] + d[cur][next];
                            parent[next] = cur;
                            if(!inQ[next]) {
                                q.push(next);
                                inQ[next] = true;
                            }
                        }
                    }
                }
                if(parent[E] == -1) break;
                int cur_flow = INF;
                for(int i=E; i!=S; i=parent[i]) {
                    cur_flow = min(cur_flow, c[parent[i]][i] - f[parent[i]][i]);
                }
                flow += (ll)cur_flow;
                for(int i=E; i!=S; i=parent[i]) {
                    cost += (ll)cur_flow * d[parent[i]][i];
                    f[parent[i]][i] += cur_flow;
                    f[i][parent[i]] -= cur_flow;
                }
            }
            return {flow, cost};
        }
};

int main() {
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
    int N, M; cin >> N >> M;
    SPFA *spfa = new SPFA(N * 2 + 5, 0, 2*N+4);
    spfa->addEdge(0, spfa->out(1), 2, 0);
    spfa->addEdge(spfa->in(N), 2*N+4, 2, 0);
    for(int i=1; i<=N; i++) spfa->setBidirectionalEdge(i);
    for(int i=0; i<M; i++){
        int a, b, c; cin >> a >> b >> c;
        spfa->addBidirectionalEdge(a, b, 1, c);
    }
    cout << spfa->getSPFA().second;
    delete spfa;
}