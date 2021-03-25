//# Author : nuclear852 ========================#
//# Solution : 2817290 =========================#
//# Time Stamp : 2016-04-15 15:31:46 ===========#
//# Problem Title : 통나무 건너뛰기 ===============#
//# Language : C++98 ===========================#

#include<iostream>
#include<algorithm>
#include <stdio.h>
using namespace std;
int arr[10000];

bool cmp(int a, int b)
 {
    return (a>b);
}

int ans = 0;
int main()
{
          int Case;  
        cin>>Case;
    while(Case--)
        {
            int N;
            cin>>N;
             ans = 0;
              for(int i=0; i<N; i++)
                  scanf("%d",&arr[i]);
               sort(arr,arr+N,cmp);
               for(int i=0; i<N; i++)
               {
                    if( i+2 < N)
                    {
                        if( arr[i] - arr[i+2] > ans)
                            ans = arr[i] - arr[i+2];
                    }
                   if( i==0)
                     {
                           if(arr[i] - arr[i+1] > ans)
                                  ans = arr[i] - arr[i+1];
                       }
               }
            cout<<ans<<endl;
        }
}