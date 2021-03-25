//# Author : nuclear852 ========================#
//# Solution : 1736511 =========================#
//# Time Stamp : 2016-02-16 16:11:13 ===========#
//# Problem Title : 동물원 ====================#
//# Language : C++98 ===========================#

#include <iostream>
using namespace std;
int main(void){
        int N;
        cin>>N;
        int dy[N+1][3];
        dy[1][0]=1;
        dy[1][1]=1;
        dy[1][2]=1;
        for(int i=2; i<=N; i++)
        {
                dy[i][0] = (dy[i-1][0]+dy[i-1][1]+dy[i-1][2])%9901;
                dy[i][1] = (dy[i-1][2]+dy[i-1][0])%9901;
                dy[i][2] = (dy[i-1][1]+dy[i-1][0])%9901;
        }
        cout<<(dy[N][0]+dy[N][1]+dy[N][2])%9901<<endl;
}