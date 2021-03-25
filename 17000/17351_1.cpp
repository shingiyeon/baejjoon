//# Author : nuclear852 ========================#
//# Solution : 26494671 ========================#
//# Time Stamp : 2021-02-18 13:38:33 ===========#
//# Problem Title : 3루수는 몰라 ================#
//# Language : C++17 ===========================#

#include <iostream>

using namespace std;

int dp[501][501];
int d[501][501];
char map[501][501];
int N;

int findD(int x, int y, int a, int b) {
    if(map[x][y] == 'A' && map[a][b] == 'L' && d[a][b] == 3) {
        d[x][y] = 0;
        return true;
    }
    if(map[x][y] == 'L' && map[a][b] == 'O' && d[a][b] == 2) {
        d[x][y] = 3;
        return false;
    }
    if(map[x][y] == 'O' && map[a][b] == 'M' && d[a][b] == 1) {
        d[x][y] = 2;
        return false;
    }
    if(map[x][y] == 'M') {
        d[x][y] = 1;
        return false;
    }
    d[x][y] = 0;
    return false;
}


int main() {
    cin >> N;
    for(int i=0; i<N; i++) cin >> map[i];

    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            if(map[i][j] == 'M') d[i][j] = 1;

            if(i-1 < 0) {
                dp[i][j] = dp[i][j-1];
                dp[i][j] += findD(i, j, i, j-1);
            }
            if(j-1 < 0) {
                dp[i][j] = dp[i-1][j];
                dp[i][j] += findD(i, j, i-1, j);
            }


            if(i-1 >= 0 && j-1 >= 0 && dp[i-1][j] > dp[i][j-1]) {
                dp[i][j] = dp[i-1][j];
                dp[i][j] += findD(i, j, i-1, j);
            }
            else if(i-1 >= 0 && j-1 >= 0 && dp[i][j-1] > dp[i-1][j]) {
                dp[i][j] = dp[i][j-1];
                dp[i][j] += findD(i, j, i, j-1);
            }
            else if(i-1 >= 0 && j-1 >= 0) {
                dp[i][j] = dp[i][j-1];
                if(map[i][j] == 'A') {
                    if(map[i-1][j] == 'L' && d[i-1][j] == 3) dp[i][j] += 1;
                    else if(map[i][j-1] == 'L' && d[i][j-1] == 3) dp[i][j] += 1;
                }
                else if(map[i][j] == 'L') {
                    if(map[i-1][j] == 'O' && d[i-1][j] == 2) d[i][j] = 3;
                    else if(map[i][j-1] == 'O' && d[i][j-1] == 2) d[i][j] = 3;
                }
                else if(map[i][j] == 'O') {
                    if(map[i-1][j] == 'M' && d[i-1][j] == 1) d[i][j] = 2;
                    else if(map[i][j-1] == 'M' && d[i][j-1] == 1) d[i][j] = 2;
                }
            }
        }
    }
    cout << dp[N-1][N-1];
}