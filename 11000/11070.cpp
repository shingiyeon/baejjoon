//# Author : nuclear852 ========================#
//# Solution : 2176682 =========================#
//# Time Stamp : 2016-03-08 23:43:00 ===========#
//# Problem Title : 피타고라스 기댓값 ==============#
//# Language : C++98 ===========================#

#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;
struct Team{
        int p;
        int q;
};
int main(void){
        int T;
        cin>>T;
        while(T--)
        {
                int max = -1;
                int min = -1;
                int n, m;
                cin>>n>>m;
                Team arr[1001];
                for(int i=1; i<=n; i++)
                {
                        arr[i].p = 0;
                        arr[i].q = 0;
                }

                for(int i=0; i<m; i++)
                {
                        int tmp1, tmp2;
                        int tmpp, tmpq;
                        scanf("%d %d %d %d",&tmp1,&tmp2,&tmpp,&tmpq);
                        arr[tmp1].p = arr[tmp1].p + tmpp;
                        arr[tmp1].q = arr[tmp1].q + tmpq;
                        arr[tmp2].p = arr[tmp2].p + tmpq;
                        arr[tmp2].q = arr[tmp2].q + tmpp;
                }

                for(int i=1; i<=n; i++)
                {
                        double value;
                        if( arr[i].q == 0 && arr[i].p == 0)
                                value = 0;
                        else
                                value = 1000* pow( arr[i].p, 2) / ( (pow(arr[i].p, 2 )) + (pow(arr[i].q,2)));
                        int w = (int) value;
                        if( w < min || min < 0)
                                min = w;
                        if( w > max || max < 0)
                                max = w;
                }
                cout<<max<<endl<<min<<endl;
        }
}