//# Author : nuclear852 ========================#
//# Solution : 1835215 =========================#
//# Time Stamp : 2016-02-20 23:00:49 ===========#
//# Problem Title : 어린 왕자 ==================#
//# Language : C++98 ===========================#

#include <iostream>
#include <math.h>
using namespace std;
struct circle{
        int x;
        int y;
        int r;
        int cover;
};
int main(){
        int T;
        cin >> T;
        for(int test=0;test<T;test++)
        {
                int x1, y1, x2, y2;
                cin>>x1>>y1>>x2>>y2;
                int n;
                cin>>n;
                circle arr[n];
                for(int i=0; i<n; i++){
                        cin>>arr[i].x>>arr[i].y>>arr[i].r;
                        arr[i].cover=0;

                        if( pow( x1 - arr[i].x , 2) + pow( y1 - arr[i].y, 2) < pow(arr[i].r,2) )
                                arr[i].cover++;
                        if( pow( x2 - arr[i].x , 2) + pow( y2 - arr[i].y, 2) < pow(arr[i].r,2) )
                                arr[i].cover++;
                }
                int answer = 0;
                for(int i=0; i<n; i++)
                {
                        if( arr[i].cover == 1)
                                answer++;
                }
                cout<<answer<<endl;
        }
}