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

struct Edge {  
    Edge* rev;
    int to, c, f;
    Edge(int _to, int _c) {
        to = _to;
        c = _c;
        f = 0;
    }

    ~Edge() {
        delete rev;
    }

    void add_flow(int _f) {
        f += _f;
        rev->f -= _f;
    }
};

class Dinic {
private:
    vector< vector<Edge*> > G;
    vector<int> lv;
    vector<int> checked;
    int N;
    int S, E;

public:
    Dinic(int _N, int _S, int _E){
        N = _N;
        G.resize(N);
        lv.resize(N);
        checked.resize(N);
        S = _S; E = _E;
    }

    void addEdge(int x, int y, int cap) {
        Edge *a = new Edge(y, cap);
        Edge *b = new Edge(x, 0);
        a->rev = b;
        b->rev = a;

        G[x].push_back(a);
        G[y].push_back(b);
    }

    bool bfs() {
        queue<int> q;
        for(int i=0; i<N; i++) {
            lv[i] = -5;
        }
        lv[S] = 0;
        q.push(S);
        while(!q.empty()) {
            int cur = q.front(); q.pop();
            for(auto next: G[cur]) {
                if(lv[next->to] == -5 && next->c > next->f) {
                    lv[next->to] = lv[cur] + 1;
                    q.push(next->to);
                }
            }
        }
        return lv[E] != -5;
    }

    int dfs(int cur, int before_flow) {
        if(cur == E) return before_flow;
        for(int &i = checked[cur]; i < G[cur].size(); i++) {
            auto next = G[cur][i];
            if(lv[next->to] == lv[cur] + 1 && next->c > next->f) {
                int flow = dfs(next->to, min(before_flow, next->c - next->f));
                if(flow) {
                    next->add_flow(flow);
                    return flow;
                }
            }
        }
        return 0;
    }

    int totalFlow() {
        int tf = 0;
        while(bfs()) {
            for(int i=0; i<N; i++) checked[i] = 0;
            while(true) {
                int cur_flow = dfs(S, 999999999);
                if(!cur_flow) break;
                tf += cur_flow;
            }
        }
        return tf;
    }
};

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    int M, N; cin >> M >> N;
    Dinic *dic = new Dinic(M*N+N+2, 0, M*N+N+1);
    for(int i=1; i<=M; i++) {
        int tmp; cin >> tmp;
        dic->addEdge(0, i, tmp);
    }
    for(int i=0; i<N-1; i++) {
        for(int j=1; j<=M; j++) {
            dic->addEdge( (i*M) + j, ( (i+1) * M) + j,  999999999);
        }
    }
    for(int i=0; i<N; i++) {
        int A; cin >> A;
        vector<int> v;
        for(int j=0; j<A; j++) {
            int tmp; cin >> tmp;
            v.push_back(tmp);
            dic->addEdge( (i*M) + tmp, (N*M) + i + 1, 999999999);
        }
        
        if(i != N-1) {
            for(int j=0; j<v.size(); j++) {
                for(int k=0; k<v.size(); k++) {
                    if(j == k) continue;
                    dic->addEdge( (i*M) + v[j], ((i+1) * M) + v[k], 999999999);
                }
            }

        }
        int flow; cin >> flow;
        dic->addEdge( (N*M) + i + 1, M*N+N+1, flow);
    }
    cout << dic->totalFlow();
}