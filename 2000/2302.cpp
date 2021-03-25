//# Author : nuclear852 ========================#
//# Solution : 4962329 =========================#
//# Time Stamp : 2017-01-07 22:49:07 ===========#
//# Problem Title : 극장 좌석 ==================#
//# Language : C++98 ===========================#

#include <iostream>
using namespace std;
int main()
{
        long long dy[41];
        dy[0] = 1;
        dy[1] = 1;
        for(int i=2; i<=40; i++)
        {
                dy[i] = dy[i-1] + dy[i-2];
        }
        long long ans = 1;

        int N, K;
        int arr[40];
        int start = 1;
        cin>>N>>K;
        for(int i=0; i<K; i++)
                cin>>arr[i];

        for(int i=0; i<K; i++)
        {
                ans = ans* dy[arr[i] - start];
                start = arr[i]+1;
        }
        ans = ans* dy[N+1 - start];
        cout<<ans<<endl;
}