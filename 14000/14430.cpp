//# Author : nuclear852 ========================#
//# Solution : 5169339 =========================#
//# Time Stamp : 2017-02-06 15:39:19 ===========#
//# Problem Title : 자원 캐기 ==================#
//# Language : C++98 ===========================#

#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;
int main(){
        int N, M; cin>>N>>M;
        int map[305][305];
        int dy[305][305];
        for(int i=1; i<=N; i++) for(int j=1; j<=M; j++) {scanf("%d", &map[i][j]); dy[i][j] = 0;}
        for(int i=1; i<=N; i++){
                for(int j=1; j<=M; j++){
                        int temp = 0;
                        if(i-1>=1) temp = max(temp, dy[i-1][j]);
                        if(j-1>=1) temp = max(temp, dy[i][j-1]);
                        dy[i][j] = map[i][j]+temp;
                }
        }
        cout<<dy[N][M]<<endl;
}