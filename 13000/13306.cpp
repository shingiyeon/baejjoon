//# Author : nuclear852 ========================#
//# Solution : 23838009 ========================#
//# Time Stamp : 2020-11-13 22:40:31 ===========#
//# Problem Title : 트리 =====================#
//# Language : C++17 ===========================#

#include <stdio.h>
#include <vector>
#include <utility>

using namespace std;

struct Query {
    bool c;
    int x, y;
    int index;
}q[400001];


int N, Q;
int p[200001];

vector<int> ans;

int parent(int x) {
    if(p[x] == x) {
        return p[x];
    }
    return p[x] = parent(p[x]);
}

void connect(int x, int y) {
    int pX = parent(x);
    int pY = parent(y);
    if(pX == pY) return;
    p[y] = x;
    return;
}

int main() {
    scanf("%d%d", &N, &Q);
    for(int i=1; i<=N; i++) p[i] = i;
    for(int i=2; i<=N; i++) {
        scanf("%d", &p[i]);
    }

    for(int i=1; i<=Q+N-1; i++) {
        scanf("%d", &q[i].c);
        if(q[i].c) {
            scanf("%d%d", &q[i].x, &q[i].y);
        }
        else {
            scanf("%d", &q[i].x);
            q[i].y = p[q[i].x];
        }
    }

    for(int i=1; i<=Q+N-1; i++) {
        if(!q[i].c) {
            p[q[i].x] = q[i].x;
        }
    }

    for(int i=Q+N-1; i>=1; i--) {
        if(!q[i].c) {
            connect(q[i].y, q[i].x);
        }
        else {
            ans.push_back(parent(q[i].x)==parent(q[i].y));
        }
    }

    for(int i = ans.size()-1; i>=0; i--) {
        if(ans[i]) {
            printf("YES\n");
        }
        else {
            printf("NO\n");
        }
    }
}