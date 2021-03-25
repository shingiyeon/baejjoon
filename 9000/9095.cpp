//# Author : nuclear852 ========================#
//# Solution : 2174566 =========================#
//# Time Stamp : 2016-03-08 20:38:34 ===========#
//# Problem Title : 1, 2, 3 더하기 ============#
//# Language : C++98 ===========================#

#include <iostream>
using namespace std;
int dfs(int n) {
        if( n>=3)
                return dfs(n-1)+dfs(n-2)+dfs(n-3);
        else if(n>=2)
                return dfs(n-2)+dfs(n-1);
        else if(n>=1)
                return dfs(n-1);
        else
                return 1;
}

int main(void)
{
        int T;
        cin>>T;
        while(T--)
        {
                int n;
                cin>>n;
                cout<<dfs(n)<<endl;
        }
}