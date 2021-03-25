//# Author : nuclear852 ========================#
//# Solution : 1363959 =========================#
//# Time Stamp : 2016-01-23 13:00:58 ===========#
//# Problem Title : 계단 오르기 =================#
//# Language : C++98 ===========================#

#include <iostream>
using namespace std;
long max(long a, long b)
{
        if( a<=b)
                return b;
        else
                return a;
}

long maxmax(long a, long b, long c)
{
        long tmp = a;
        if(b>tmp)
                tmp = b;
        if(c>tmp)
                tmp = c;

        return tmp;
}

int main(void)
{
        int n;
        cin>>n;

        int value[n];
        long dy[n];

        for(int i=0; i<n; i++)
        {
                cin >> value[i];
        }

        dy[0] = value[0];
        dy[1] = dy[0]+value[1];
        dy[2] = max( value[0], value[1]) + value[2];
        dy[3] = max( dy[0] + value[1] + value[3] , dy[0] + value[2] + value[3]);
        dy[4] = maxmax( value[3] + dy[1] + value[4] , value[2]+value[1]+value[4], value[2]+value[0]+value[4]);

        for( int i=5; i<n; i++)
        {
                dy[i] = maxmax(dy[i-3] + value[i-1]+value[i] ,dy[i-5] + value[i-3]+value[i-2]+value[i] , dy[i-4] + value[i-2]+value[i]);
        }

        cout<<dy[n-1]<<endl;
        return 0;
}