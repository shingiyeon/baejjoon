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

struct Cow{
    bool dir;
    int x, y;
    int index;

    Cow(bool _dir, int _x, int _y, int _index) {
        dir = _dir;
        x = _x;
        y = _y;
        index = _index;
    }
};

bool cmpX(struct Cow* a, struct Cow *b) {
    return a->x < b->x;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    vector<struct Cow*> cow[2];
    int visited[2][50];
    int ans[50];

    for(int i=0; i<50; i++) {
        visited[0][i] = visited[1][i] = 0;
        ans[i] = -1;
    }
    int N; cin >> N;
    for(int i=0; i<N; i++) {
        char c; 
        int a, b; cin >> c >> a >> b;

        if(c == 'E') {
            cow[0].push_back(new Cow(c, a, b, i));
        }
        else {
            cow[1].push_back(new Cow(c, a, b, i));
        }
    }

    sort(cow[0].begin(), cow[0].end(), cmpX);
    sort(cow[1].begin(), cow[1].end(), cmpX);

    priority_queue< pair<pi, pair<pi, pi> >  > pq;

    for(int i=0; i<cow[0].size(); i++) {
        for(int j=0; j<cow[1].size(); j++) {
            int dx = cow[1][j]->x - cow[0][i]->x;
            int dy = cow[0][i]->y - cow[1][j]->y;
            if(dx>=0 && dy>=0) {
                if(dx < dy) {
                    pq.push( { { -dy, 1}, { {0, i}, {1, j} } } );
                }
                else if(dx > dy) {
                    pq.push( { {-dx, 0}, { {0, i}, {1, j} } } );
                }
            }
        }
    }
    
    while(!pq.empty()) {
        auto info = pq.top(); pq.pop();
        auto E = info.second.first; auto N = info.second.second;
        int time = -info.first.first;
        int past_time;
        // cout << -info.first.first << " " << info.first.second << " " << E.first << " " << E.second << " " << N.first << " " << N.second << "\n";
        if(info.first.second == 0 && !visited[E.first][E.second]) {
            past_time = cow[E.first][E.second] -> y - cow[N.first][N.second] -> y;
            // cout << past_time << " " << visited[N.first][N.second] << "\n";
            if(visited[N.first][N.second] == 0 || visited[N.first][N.second] >= past_time) {    
                ans[cow[E.first][E.second]->index] = time;
                visited[E.first][E.second] = time;                
            }
        }
        if(info.first.second == 1 && !visited[N.first][N.second]) {
            past_time = cow[N.first][N.second] -> x - cow[E.first][E.second] -> x;
            // cout << past_time << " " << visited[E.first][E.second] <<  "\n";
            if(visited[E.first][E.second] == 0 || visited[E.first][E.second] >= past_time) {
                ans[cow[N.first][N.second]->index] = time;
                visited[N.first][N.second] = time;
            }
        }
    }

    for(int i=0; i<N; i++) { 
        if(ans[i] == -1) {
            cout << "Infinity\n";
        }
        else {
            cout << ans[i] << "\n";
        }
    }

}