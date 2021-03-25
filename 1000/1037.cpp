//# Author : nuclear852 ========================#
//# Solution : 4051631 =========================#
//# Time Stamp : 2016-09-01 22:06:34 ===========#
//# Problem Title : 약수 =====================#
//# Language : C++98 ===========================#

#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
        int T;
        cin>>T;

        int arr[51];

        for(int i=0; i<T; i++)
                cin>>arr[i];

        sort(arr,arr+T);

        if(arr[0]==1 || arr[T-1]==1)
        {
                cout<<arr[1]*arr[T-2]<<endl;
        }
        else
        {
                cout<<arr[0]*arr[T-1]<<endl;
        }
}