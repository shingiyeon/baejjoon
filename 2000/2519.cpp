//# Author : nuclear852 ========================#
//# Solution : 24525631 ========================#
//# Time Stamp : 2020-12-22 13:51:07 ===========#
//# Problem Title : 막대기 ====================#
//# Language : C++17 ===========================#

#include <stdio.h>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

int N;
stack<int> S;
int num[10001], gNum[10001];
bool inS[10001];
bool pick[10001];
int t = 0, f = 0;
vector<int> ans;
int scc[10001];
int cnt = 0, s_cnt = 0;

vector< vector<int> > adj;

struct Line{
    int X1, Y1, X2, Y2;
}L[10001];

long long ccw(int x1, int y1, int x2, int y2, int x3, int y3) {
    return (x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1);
}

bool isCross(Line a, Line b) {
    long long tmp1 = ccw(a.X1, a.Y1, a.X2, a.Y2, b.X1, b.Y1) * ccw(a.X1, a.Y1, a.X2, a.Y2, b.X2, b.Y2);
    long long tmp2 = ccw(b.X1, b.Y1, b.X2, b.Y2, a.X1, a.Y1) * ccw(b.X1, b.Y1, b.X2, b.Y2, a.X2, a.Y2);
    return tmp1 <0 && tmp2 < 0;
}

void dfs(int cur) {
    S.push(cur);
    num[cur] = ++cnt;
    gNum[cur] = cnt;
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
            scc[s_cur] = s_cnt;
            inS[s_cur] = false;
            if(s_cur == cur) break;
        }
    }
}

int main() {
    scanf("%d", &N);
    adj.resize(10001);
    for(int i=0; i<N; i++) {
        for(int j=1; j<=3; j++){
            scanf("%d%d%d%d", &L[3*i+j].X1, &L[3*i+j].Y1, &L[3*i+j].X2, &L[3*i+j].Y2);
        }
        adj[i*3+1].push_back(3000 + (i*3+2));
        adj[i*3+1].push_back(3000 + (i*3+3));
        adj[i*3+2].push_back(3000 + (i*3+1));
        adj[i*3+2].push_back(3000 + (i*3+3));
        adj[i*3+3].push_back(3000 + (i*3+1));
        adj[i*3+3].push_back(3000 + (i*3+2));
    }
    for(int i=1; i<=3*N; i++) {
        for(int j=i+1; j<=3*N; j++) {
            if(isCross(L[i], L[j])) {
                adj[3000+i].push_back(j);
                adj[3000+j].push_back(i);
            }
        }
    }
    for(int i=1; i<=3*N; i++) {
        if(!num[i]) dfs(i);
        if(!num[i+3000]) dfs(i+3000); 
    }
    bool pos = true;
    for(int i=1; i<=3*N; i++) {
        if(scc[i] == scc[i+3000]) {
            pos = false; break;
        }
        if(scc[i+3000] > scc[i]) {
            ans.push_back(i);
        }
    }

    if(!pos) {
        printf("-1");
    }
    else {
        sort(ans.begin(), ans.end());
        printf("%lu\n", ans.size());
        for(auto val: ans) {
            printf("%d ", val);
        }
    }
}