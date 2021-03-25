//# Author : nuclear852 ========================#
//# Solution : 1365559 =========================#
//# Time Stamp : 2016-01-23 19:57:30 ===========#
//# Problem Title : 1로 만들기 =================#
//# Language : C++98 ===========================#

#include <iostream>
using namespace std;
int min(int a, int b)
{
        if(a<b)
                return a;
        else
                return b;
}
int main(void)
{
        int N;

        cin>>N;

        int dy[N+1];

        dy[1]=0;
        dy[2]=1;
        dy[3]=1;

        for(int i = 4; i<N+1; i++)
        {
                if( i % 3 == 0 && i % 2 == 0)
                        dy[i]= min(dy[i/3], dy[i/2])+1;
                else if(i % 3 ==0)
                        dy[i]= min(dy[i/3],dy[i-1])+1;

                else if(i% 2 ==0)
                        dy[i]=min(dy[i/2],dy[i-1])+1;
                else
                        dy[i]=dy[i-1]+1;
        }
        cout<<dy[N]<<endl;
        return 0;
}