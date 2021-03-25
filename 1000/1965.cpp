//# Author : nuclear852 ========================#
//# Solution : 1737029 =========================#
//# Time Stamp : 2016-02-16 16:31:47 ===========#
//# Problem Title : 상자넣기 ===================#
//# Language : C++98 ===========================#

#include <iostream>
using namespace std;
int main(void){
        int n;
        cin>>n;
        int dy[n+1];
        int a[n+1];
        for(int i=1; i<=n; i++)
                cin>>a[i];
        dy[1]=1;
        for(int i=2; i<=n; i++)
        {
                int max=0;

                for(int j=1; j<i; j++)
                {
                        if( a[i] > a[j] && dy[j] > max)
                                max = dy[j];
                }

                dy[i] = max+1;
        }
        int ans=0;
        for(int i=1; i<=n; i++)
                if(dy[i]>=ans)
                        ans=dy[i];
        cout<<ans<<endl;
}