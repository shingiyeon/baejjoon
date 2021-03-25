//# Author : nuclear852 ========================#
//# Solution : 4908975 =========================#
//# Time Stamp : 2017-01-01 22:33:51 ===========#
//# Problem Title : 고층 빌딩 ==================#
//# Language : C++98 ===========================#

#include <iostream>
using namespace std;
int main(void){
        long dy[101][101][101];
        for(int i=0; i<101; i++)
        {
                for(int j=0; j<101; j++)
                {
                        for(int k=0; k<101; k++)
                        {
                                dy[i][j][k] = 0;
                        }
                }
        }
        dy[1][1][1] = 1;
        for(int i=2; i<101; i++)
        {
                for(int j=0; j<101; j++)
                {
                        for(int k=0; k<101; k++)
                        {
                                dy[i][j][k] = (dy[i-1][j-1][k] + dy[i-1][j][k-1] + (dy[i-1][j][k] * (i-2))) % 1000000007;
                        }
                }
        }
        int n, l, r;
        cin>>n>>l>>r;
        cout<<dy[n][l][r]<<endl;
}