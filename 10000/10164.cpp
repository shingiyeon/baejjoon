//# Author : nuclear852 ========================#
//# Solution : 4951170 =========================#
//# Time Stamp : 2017-01-06 13:01:26 ===========#
//# Problem Title : 격자상의 경로 ================#
//# Language : C++98 ===========================#

#include <iostream>
using namespace std;
int main(void) {
        int N, M, K;
        int dy[16][16];
        cin>>N>>M>>K;

        int a, b;
        a = ((K-1) / M)+ 1;
        b = ((K-1) % M)+ 1;

        for(int i=1; i<=N; i++)
                dy[i][1] = 1;
        for(int i=1; i<=M; i++)
                dy[1][i] = 1;
        for(int i=2; i<=N; i++)
                for(int j=2; j<=M; j++)
                        dy[i][j] = dy[i-1][j] + dy[i][j-1];
//      cout<< a<<" "<<b<<" "<<N-a+1 <<" "<< M-b+1 << endl;
        if(K == 0)
                cout << dy[N][M] << endl;
        else
                cout << dy[a][b] * dy[N-a+1][M-b+1] << endl;

}