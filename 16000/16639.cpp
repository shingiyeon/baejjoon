//# Author : nuclear852 ========================#
//# Solution : 25428847 ========================#
//# Time Stamp : 2021-01-19 13:23:48 ===========#
//# Problem Title : 괄호 추가하기 3 ==============#
//# Language : C++17 ===========================#

#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <algorithm>
#define INF 9999999999LL
typedef long long ll;
using namespace std;

ll dp[10][10][2];
vector<int> num;
vector<int> ope;

ll calc(ll a, ll b, int o) {
    if(o == 0) {
        return a + b;
    }
    else if(o == 1) {
        return a - b;
    }
    else {
        return a * b;
    }
}

ll d(int x, int y, int o) {
    if(dp[x][y][o] != -INF && dp[x][y][o] != INF) {
        return dp[x][y][o];
    }
    if(x == y) {
        return dp[x][y][o] = num[x];
    }
    if(o == 0) {
        for(int i=x; i<y; i++) {
            if(ope[i] == 0) {
                dp[x][y][o] = max(dp[x][y][o], calc( d(x, i, 0), d(i+1, y, 0), 0) );
            }
            else if(ope[i] == 1) {  
                dp[x][y][o] = max(dp[x][y][o], calc( d(x, i, 0), d(i+1, y, 1), 1) );
            }
            else {
                dp[x][y][o] = max(dp[x][y][o], calc( d(x, i, 0), d(i+1, y, 0), 2) );
                dp[x][y][o] = max(dp[x][y][o], calc( d(x, i, 1), d(i+1, y, 0), 2) );
                dp[x][y][o] = max(dp[x][y][o], calc( d(x, i, 1), d(i+1, y, 1), 2) );
                dp[x][y][o] = max(dp[x][y][o], calc( d(x, i, 0), d(i+1, y, 1), 2) );
            }
        }
    }
    else {
        for(int i=x; i<y; i++) {
            if(ope[i] == 0) {
                dp[x][y][o] = min(dp[x][y][o], calc( d(x, i, 1), d(i+1, y, 1), 0) );
            }
            else if(ope[i] == 1) {  
                dp[x][y][o] = min(dp[x][y][o], calc( d(x, i, 1), d(i+1, y, 0), 1) );
            }
            else {
                dp[x][y][o] = min(dp[x][y][o], calc( d(x, i, 0), d(i+1, y, 1), 2) );
                dp[x][y][o] = min(dp[x][y][o], calc( d(x, i, 1), d(i+1, y, 0), 2) );
                dp[x][y][o] = min(dp[x][y][o], calc( d(x, i, 1), d(i+1, y, 1), 2) );
                dp[x][y][o] = min(dp[x][y][o], calc( d(x, i, 0), d(i+1, y, 0), 2) );
            }
        }
    }
    return dp[x][y][o];
}

int main() {
    for(int i=0; i<10; i++) {
        for(int j=0; j<10; j++) {
            dp[i][j][0] = -INF;
            dp[i][j][1] = INF;
        }
    }
    int N; cin>>N;
    string str; cin >> str;
    for(int i=0; i<str.size(); i++) {
        if(str[i] >= '0' && str[i] <= '9') num.push_back(str[i]-'0');
        else {
            if(str[i] == '+') ope.push_back(0);
            else if(str[i] == '-') ope.push_back(1);
            else ope.push_back(2);
        }
    }

    printf("%lld", d(0, (int)(N/2), 0));
}