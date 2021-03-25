//# Author : nuclear852 ========================#
//# Solution : 24343072 ========================#
//# Time Stamp : 2020-12-12 23:57:13 ===========#
//# Problem Title : 로봇 조종하기 ================#
//# Language : C++17 ===========================#

#include <stdio.h>
#include <algorithm>
using namespace std;

int dy[1002][1002][3];
int N, M;
int map[1002][1002];
int main() {
    scanf("%d%d", &N, &M);

    for(int i=1; i<=N; i++) {
        for(int j=1; j<=M; j++) {
            scanf("%d", &map[i][j]);
        }
    }

    for(int i=1; i<=M; i++) {
        dy[1][i][0] = dy[1][i][1] = dy[1][i][2] = dy[1][i-1][0] + map[1][i];
    }

    
    for(int i=2; i<=N; i++) {
        for(int j=1; j<=M; j++) {
            dy[i][j][1] = map[i][j] + max(dy[i-1][j][0], max(dy[i-1][j][1], dy[i-1][j][2]));
        }
        for(int j=1; j<=M; j++) {
            if(j == 1) {
                dy[i][j][0] = dy[i][j][1];
                continue;
            }
            dy[i][j][0] = map[i][j] + max(dy[i][j-1][1] , dy[i][j-1][0] );
        }
        for(int j=M; j>=1; j--) {
            if(j == M) {
                dy[i][j][2] = dy[i][j][1];
                continue;
            }
            dy[i][j][2] = map[i][j] + max(dy[i][j+1][1] , dy[i][j+1][2] );
        }
    } 

    // for(int i=1; i<=N; i++) {
    //     for(int j=1; j<=M; j++) {
    //         printf("%d %d %d || ", dy[i][j][0], dy[i][j][1], dy[i][j][2]);
    //     }
    //     printf("\n");
    // }

    printf("%d", max(dy[N][M][0], max(dy[N][M][1], dy[N][M][2])));
}