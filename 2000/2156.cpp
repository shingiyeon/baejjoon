//# Author : nuclear852 ========================#
//# Solution : 2160848 =========================#
//# Time Stamp : 2016-03-07 21:57:47 ===========#
//# Problem Title : 포도주 시식 =================#
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
int main(void){
        int n;
        cin>>n;
        int a[n];
        int dy[n];
        for(int i=0; i<n; i++)
                cin>>a[i];
        dy[0] = a[0];
        if( n>=1)
                dy[1] = a[0]+a[1];
        if( n>=2)
                dy[2] = max( a[0]+a[1], max(a[1]+a[2] , a[0]+a[2]));
        for(int i=3; i<n; i++)
        {
                if( i>=3)
                        dy[i] = max( dy[i-2] + a[i] , max(dy[i-3]+a[i-1],dy[i-3] + a[i-1]+a[i]));
                if( i>=4)
                        dy[i] = max( dy[i] , dy[i-4]+a[i-2]+a[i-1]);
        }
        cout<<dy[n-1]<<endl;
}