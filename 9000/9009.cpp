//# Author : nuclear852 ========================#
//# Solution : 2897009 =========================#
//# Time Stamp : 2016-05-05 22:42:30 ===========#
//# Problem Title : 피보나치 ===================#
//# Language : C++98 ===========================#

#include <iostream>
#include <stack>
using namespace std;
int main(void)
{
        long long fib[50];
        fib[0]=0;
        fib[1]=1;
        for(int i=2; i<50; i++){
                fib[i]=fib[i-1]+fib[i-2];
        }

        int n;
        cin>>n;
        while(n--)
        {
                long long k;
                cin>>k;
                stack<long long> ans;
                while(k){
                        for(int i=49; i>=1; i--)
                        {
                                if(fib[i]<=k)
                                {
                                        ans.push(fib[i]);
                                        k= k-fib[i];
                                }
                        }
                }
                while(!ans.empty())
                {
                        cout<<ans.top()<<" ";
                        ans.pop();
                }
                cout<<endl;
        }

}