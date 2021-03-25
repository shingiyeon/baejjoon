//# Author : nuclear852 ========================#
//# Solution : 4940890 =========================#
//# Time Stamp : 2017-01-05 11:27:22 ===========#
//# Problem Title : 타일 채우기 =================#
//# Language : C++98 ===========================#

#include <iostream>
#include <algorithm>

using namespace std;
int dy(int N)
{
        int ans = 0;
        int temp;
        if( N==2)
                return 3;
        else if( N==0)
                return 1;
        else if( N%2)
                return 0;
        else{
                for(int i=2; N-i >=0; i=i+2)
                {
                        if( i==2)
                                temp = dy(N-i) * 3;
                        else
                                temp = dy(N-i) * 2;
                        ans = ans + temp;
                }
                return ans;
        }
}

int main(void){
        int N;
        cin>>N;
        cout<<dy(N)<<endl;
}