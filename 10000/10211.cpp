//# Author : nuclear852 ========================#
//# Solution : 3540464 =========================#
//# Time Stamp : 2016-07-22 11:47:18 ===========#
//# Problem Title : Maximum Subarray =======#
//# Language : C++98 ===========================#

#include <iostream>
using namespace std;
int main(void)
{
        int testcase;
        cin >>testcase;
        int arr[1000];
        int arr2[1000];


        while(testcase--)
        {
                int N;
                cin>>N;
                for(int i=0; i<N; i++)
                        cin>>arr[i];

                arr2[0] = arr[0];
                int ans = arr2[0];

                for(int i=1; i<N; i++)
                {
                        if(arr2[i-1]+arr[i] > arr[i])
                                arr2[i] = arr2[i-1]+arr[i];
                        else
                                arr2[i] = arr[i];

                        if(arr2[i] > ans)
                                ans = arr2[i];
                }

                cout<<ans<<endl;
        }
}