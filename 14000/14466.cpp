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

int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int N, K, R;
    cin >> N >> K >> R;

    bool visited[10001];

    vector<int> color(N*N, 0);
    vector< vector<int> > m(N*N);
    vector< vector<int> > road(N*N);
    vector<int> c(N*N, 0);
    for(int i=0; i<R; i++) {
        int sx, sy, ex, ey;
        cin >> sx >> sy >> ex >> ey;
        sx--; sy--; ex--; ey--;
        road[sx*N + sy].push_back(ex*N + ey);
        road[ex*N + ey].push_back(sx*N + sy);
    }

    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            for(int k=0; k<4; k++) {
                int nx = i + dx[k]; int ny = j + dy[k];
                if(nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
                bool flag = false;
                for(auto val: road[i*N + j]) {
                    if(val == nx*N + ny) flag = true;
                }
                if(!flag) {
                    m[i*N + j].push_back(nx*N + ny);
                }
            }
        }
    }
    // for(int i=0; i<N; i++) {
    //     for(int j=0; j<N; j++) {
    //         for(auto val: m[i*N + j]) {
    //             cout << i << " " << j << " " << val << "\n";
    //         }
    //     }
    // }
    int col = 1;
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            if(color[i*N+j] == 0) {
                for(int k=0; k<N*N; k++) visited[k] = 0;
                queue<int> q;
                visited[i*N + j] = true;
                q.push(i*N + j);
                while(!q.empty()) {
                    int cur = q.front(); q.pop();
                    color[cur] = col;
                    for(auto next: m[cur]) {
                        if(!visited[next]) {
                            visited[next] = true;
                            q.push(next);
                        }
                    }
                }
                col++;
            }
        }
    }
    int ans = 0;
    for(int i=0; i<K; i++) {
        int x; int y; cin >> x >> y; x--; y--;
        //cout << color[x*N + y] << "\n";
        ans += (i - c[color[x*N + y]]);
        c[color[x*N + y]]++;
    }
    cout << ans;

}