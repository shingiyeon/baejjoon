//# Author : nuclear852 ========================#
//# Solution : 1364076 =========================#
//# Time Stamp : 2016-01-23 13:47:46 ===========#
//# Problem Title : 플러그 ====================#
//# Language : C++98 ===========================#

#include <iostream>
using namespace std;
int main()
{
        int N;
        cin>>N;
        int arr[N];
        int ans=1;
        for(int i=0;  i<N; i++)
        {
                cin>>arr[i];
                ans =ans + arr[i] -1;
        }
        cout << ans<<endl;
}