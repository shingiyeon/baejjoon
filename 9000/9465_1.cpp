//# Author : nuclear852 ========================#
//# Solution : 1415088 =========================#
//# Time Stamp : 2016-01-28 21:47:06 ===========#
//# Problem Title : 스티커 ====================#
//# Language : C++98 ===========================#

#include <iostream>
using namespace std;

int max(int a, int b)
{
        if(a>b)
                return a;
        else
                return b;
}

int main(void)
{
        int T;
        cin>>T;

        for(int test=0; test<T; test++)
        {
                int n;
                cin>>n;

                int arr[2][n];
                int dy[2][n];
                for(int i=0; i<2; i++)
                {
                        for(int j=0; j<n; j++)
                        {
                                cin>>arr[i][j];
                        }
                }
                dy[0][0]= arr[0][0];
                dy[1][0]= arr[1][0];

                dy[0][1]= arr[0][1] + dy[1][0];
                dy[1][1]= arr[1][1] + dy[0][0];

                for(int i=2; i<n; i++)
                {
                        dy[0][i]= max( dy[1][i-1] , dy[1][i-2]) + arr[0][i];
                        dy[1][i]= max( dy[0][i-1] , dy[0][i-2]) + arr[1][i];
                }

                int ans = dy[0][0];

                for(int i=0; i<2; i++)
                        for(int j=0; j<n; j++)
                                if( dy[i][j] > ans)
                                        ans = dy[i][j];

                cout<<ans<<endl;
        }
        return 0;
}