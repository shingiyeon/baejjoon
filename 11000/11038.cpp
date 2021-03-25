//# Author : nuclear852 ========================#
//# Solution : 4406111 =========================#
//# Time Stamp : 2016-10-01 00:06:23 ===========#
//# Problem Title : Entrance Examination ===#
//# Language : C++98 ===========================#

#include <iostream>
#include <stdio.h>
using namespace std;

int main(void)
{
        int m, nmin, nmax;

        while(1)
        {
                scanf("%d %d %d",&m,&nmin,&nmax);
                int arr[10000];
                int cha[10000];
                int max = 0;
                int ans = 0;

                if(m==0 && nmin==0 && nmax==0)
                        break;

                scanf("%d",&arr[0]);
                for(int i=1; i<m; i++)
                {
                        scanf("%d",&arr[i]);
                        cha[i-1] = arr[i-1]-arr[i];

                        //cout<<cha[i-1]<<endl;
                }
                for(int i=nmin; i<=nmax; i++)
                {
                        if(max<=cha[i-1])
                        {
                                max=cha[i-1];
                                ans=i;
                        }
                }

                printf("%d\n",ans);
        }
}