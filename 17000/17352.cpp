//# Author : nuclear852 ========================#
//# Solution : 26495420 ========================#
//# Time Stamp : 2021-02-18 14:01:32 ===========#
//# Problem Title : 여러분의 다리가 되어 드리겠습니다! ====#
//# Language : C++17 ===========================#

#include <iostream>
#include <string>
using namespace std;

int p[300001];
int sz[300001];
int parent(int cur) {
    if(p[cur] == cur) return cur;
    return p[cur] = parent(p[cur]);
}

void merge(int a, int b) {
    int pA = parent(a);
    int pB = parent(b);
    if(pA == pB) return;
    if(sz[pA] > sz[pB]) {
        p[pB] = pA;
        sz[pA] += sz[pB];
    }
    else {
        p[pA] = pB;
        sz[pB] += sz[pA];
    }
    return;
}

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);
    int N; cin >> N;
    for(int i=1; i<=N; i++) {
        p[i] = i;
        sz[i] = i;
    }
    for(int i=1; i<N-1; i++)  {
        int a, b; cin >> a >> b;
        merge(a, b);
    }
    int tmp = parent(1);
    for(int i=1; i<=N; i++) {
        if(parent(tmp) != parent(i)) {
            cout << 1 << " " << i;
            return 0;
        }
    }
    return 0;
}