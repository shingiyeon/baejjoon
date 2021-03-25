//# Author : nuclear852 ========================#
//# Solution : 4865096 =========================#
//# Time Stamp : 2016-12-26 15:04:56 ===========#
//# Problem Title : Q-인덱스 ==================#
//# Language : C++98 ===========================#

#include <iostream>
#include <algorithm>
#include <stdio.h>

using namespace std;

int main(void)
{
        int n;
        cin>>n;
        int arr[1000];
        int ans;

        for(int i=0; i<n; i++)
                scanf("%d",&arr[i]);
        sort(arr,arr+n);
        for(int j=0; j<10001; j++)
        {
                int num1=0;
                int num2=0;
                for(int i=0; i<n; i++)
                {
                        if(arr[i] >= j)
                        {
                                num1++;
                        }
                        if(arr[i] <= j)
                        {
                                num2++;
                        }
                }
                if(num1 == j || num2 == n-j)
                {
                        ans = j;
                        break;
                }
        }

        cout<<ans<<endl;
}