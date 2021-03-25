//# Author : nuclear852 ========================#
//# Solution : 1834960 =========================#
//# Time Stamp : 2016-02-20 22:46:15 ===========#
//# Problem Title : 터렛 =====================#
//# Language : C++98 ===========================#

#include <iostream>
#include <math.h>
using namespace std;
typedef long double ll;
ll distance(int x1, int y1, int x2, int y2)
{
        return sqrt((pow( x2-x1,2) + pow(y2-y1,2)));
}
int main(void)
{
        int T;
        cin >> T;
        for(int test=0; test<T; test++)
        {
                ll x1,y1 ,r1, x2, r2, y2;
                cin>>x1>>y1>>r1>>x2>>y2>>r2;
                int answer;
                if(x1==x2 && y1==y2)
                {
                        if(r1==r2)
                                answer = -1;
                        else
                                answer = 0;
                }

                else
                {
                        if( distance(x1,y1,x2,y2) > r1+r2)
                                answer = 0;
                        if( distance(x1,y1,x2,y2) == r1+r2)
                                answer = 1;
                        if( distance(x1,y1,x2,y2) < r1+r2)
                                answer = 2;
                        if( distance(x1,y1,x2,y2) + r1 < r2 || distance(x1,y1,x2,y2)+r2 < r1)
                                answer = 0;
                        if( distance(x1,y1,x2,y2) + r1 ==r2 || distance(x1,y1,x2,y2)+r2 == r1)
                                answer = 1;
                }
                cout<<answer<<endl;
        }
}