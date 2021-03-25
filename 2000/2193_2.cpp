//# Author : nuclear852 ========================#
//# Solution : 1363853 =========================#
//# Time Stamp : 2016-01-23 12:23:03 ===========#
//# Problem Title : 이친수 ====================#
//# Language : C++98 ===========================#

#include <iostream>

using namespace std;

int main(void)
{
        int n;

        cin>>n;

        long dy[n][2];

        dy[0][0] = 1;
        dy[0][1] = 1;

        for(int i=1; i<n; i++)
        {
                dy[i][0]= dy[i-1][0] + dy[i-1][1];
                dy[i][1]= dy[i-1][0];
        }

        cout<<dy[n-1][1];
        return 0;
}