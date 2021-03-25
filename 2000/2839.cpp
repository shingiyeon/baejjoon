//# Author : nuclear852 ========================#
//# Solution : 5013162 =========================#
//# Time Stamp : 2017-01-13 23:06:41 ===========#
//# Problem Title : 설탕 배달 ==================#
//# Language : C++98 ===========================#

#include <iostream>
using namespace std;
int main(){
        int N;
        cin>>N;
        int ans = -1;
        for(int i=0; i<=(int)N/5; i++)
        {
                if( (N-(i*5))%3 == 0 )
                        ans = i + ((N-(i*5))/3);
        }
        cout<<ans<<endl;
}