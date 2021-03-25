//# Author : nuclear852 ========================#
//# Solution : 2994757 =========================#
//# Time Stamp : 2016-05-26 15:36:17 ===========#
//# Problem Title : 막대 배치 ==================#
//# Language : C++98 ===========================#

#include <iostream>
using namespace std;
int main(void){
        long long dy[21][21][21];
        for(int i=0; i<21; i++)
        {
                for(int j=0; j<21; j++)
                {
                        for(int k=0; k<21; k++)
                        {
                                dy[i][j][k] = 0;
                        }
                }
        }
        dy[1][1][1] = 1;
        for(int i=2; i<21; i++)
        {
                for(int j=0; j<21; j++)
                {
                        for(int k=0; k<21; k++)
                        {
                                dy[i][j][k] = dy[i-1][j-1][k] + dy[i-1][j][k-1] + (dy[i-1][j][k] * (i-2));
                        }
                }
        }
        int test;
        cin>>test;
        while(test--)
        {
                int n, l, r;
                cin>>n>>l>>r;
                cout<<dy[n][l][r]<<endl;
        }
}