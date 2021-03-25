//# Author : nuclear852 ========================#
//# Solution : 4051696 =========================#
//# Time Stamp : 2016-09-01 22:17:38 ===========#
//# Problem Title : 한수 =====================#
//# Language : C++98 ===========================#

#include <iostream>
using namespace std;

int main(void)
{
        int N;
        cin>>N;
        int ans = 0;
        for(int i=1; i<=N; i++)
        {
                if(i==1000);
                else if(i>=100)
                {
                        int a,b,c;
                        a=i/100;
                        b= (i-(a*100))/10;
                        c= i-(a*100)-(b*10);

                        if(a-b == b-c)
                                ans++;
                }
                else if(i>=1)
                {
                        ans++;
                }
        }
        cout<<ans<<endl;
}