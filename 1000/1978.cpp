//# Author : nuclear852 ========================#
//# Solution : 2175141 =========================#
//# Time Stamp : 2016-03-08 21:28:39 ===========#
//# Problem Title : 소수 찾기 ==================#
//# Language : C++98 ===========================#

#include <iostream>
#include <math.h>
using namespace std;
int main(void)
{
        int N;
        cin>>N;
        int arr[N];

        for(int i=0; i<N; i++)
                cin>>arr[i];

        int ans = 0;

        for(int i=0; i<N; i++)
        {
                bool okay = 0;
                for(int j=2; j<=arr[i]-1; j++)
                {
                        if(arr[i] % j == 0)
                                okay = 1;
                }

                if(okay == 0 && arr[i] != 1)
                        ans++;

        }
        cout<<ans<<endl;
}