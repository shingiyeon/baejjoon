//# Author : nuclear852 ========================#
//# Solution : 22507637 ========================#
//# Time Stamp : 2020-09-12 22:40:52 ===========#
//# Problem Title : 구간 합 구하기 3 =============#
//# Language : C++14 ===========================#

#include <stdio.h>
#include <algorithm>
using namespace std;
int N, M;
int arr[1025][1025];
int tree[1025][1025];

void update(int x, int y, int diff) {
    while(y <= N) {
        tree[x][y] += diff;
        y += (y & -y);
    }
}

int sum(int x, int y) {
    int ans = 0;
    while(y >= 1) {
        ans += tree[x][y];
        y -= (y & -y);
    }
    return ans;
}

int main() {
    scanf("%d%d", &N, &M);
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=N; j++) {
            scanf("%d", &arr[i][j]);
            update(i, j, arr[i][j]);
        }
    }
    
    int b, x1, y1, x2, y2, c;
    for(int i=1; i<=M; i++){
        scanf("%d", &b);
        if(b) {
            scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
            if (x1 >= x2 && y1 >= y2) {
                swap(x1, x2);
                swap(y1, y2);
             }
            int ans = 0;
            for(int j=x1; j<=x2; j++) {
                ans += sum(j, y2) - sum(j, y1-1);
            }
            printf("%d\n", ans);
        }
        else {
            scanf("%d%d%d",&x1,&y1,&c);
            update(x1, y1, c - arr[x1][y1]);
            arr[x1][y1] = c;
        }
    }
}