//# Author : nuclear852 ========================#
//# Solution : 5013232 =========================#
//# Time Stamp : 2017-01-13 23:18:31 ===========#
//# Problem Title : 완전제곱수 ==================#
//# Language : C++98 ===========================#

#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;
int main(){
        int M, N;
        cin>>M>>N;
        int ans = 0;
        int Min = 9999999;
        for(int i=M; i<=N; i++)
        {
                if( (int)sqrt(i) ==  sqrt(i)){
                        ans+=i; Min = min(Min, i);
                }
        }
        if(ans==0)
                cout<<"-1"<<endl;
        else{
                cout<<ans<<endl;
                cout<<Min<<endl;
        }
}