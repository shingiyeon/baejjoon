//# Author : nuclear852 ========================#
//# Solution : 2247270 =========================#
//# Time Stamp : 2016-03-12 17:20:52 ===========#
//# Problem Title : 모노톤길 ===================#
//# Language : C++98 ===========================#

#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;
struct point{
        int x;
        int y;
};
bool cmp(point a, point b){
        if( a.x != b.x)
                return a.x < b.x;
        else
                return a.y < b.y;
}
bool cmpy1(point a, point b){
        return a.y < b.y;
}
bool cmpy2(point a, point b){
        return a.y > b.y;
}
int main(void){
        int T;
        cin>>T;
        while(T--){
                int n;
                cin>>n;
                point arr[n+1];
                int xvalue[100001];
                for(int i=0; i<=100000; i++)
                        xvalue[i] = 0;
                arr[0].x = -1;
                arr[0].y = 0;
                for(int i=1; i<=n; i++){
                        scanf("%d %d",&arr[i].x,&arr[i].y);
                        xvalue[ arr[i].x ]++;
                }
                int num = 1;
                sort( arr, arr+1+n, cmp);
                while(num <= n)
                {
                        if( xvalue[ arr[num].x ] > 1 )
                        {
                                if( arr[num-1].y > arr[num].y)
                                        sort( arr+num, arr+num+xvalue[ arr[num].x], cmpy2);
                        }
                        num = num + xvalue[ arr[num].x ];
                }
                int k;
                cin>>k;
                for(int i=0; i<k; i++)
                {
                        int tmp;
                        scanf("%d",&tmp);
                        printf("%d %d\n",arr[tmp].x,arr[tmp].y);
                }
        }
}