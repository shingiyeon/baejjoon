//# Author : nuclear852 ========================#
//# Solution : 1853465 =========================#
//# Time Stamp : 2016-02-21 20:36:22 ===========#
//# Problem Title : 분산처리 ===================#
//# Language : C++98 ===========================#

#include <iostream>
using namespace std;
int main(){
        int T;
        cin>>T;
        for(int test=0;test<T;test++)
        {
                int a, b;
                cin>>a>>b;
                int answer=1;
                for(int i=0; i<b; i++)
                        answer= (answer*a)%10;
                if(answer==0)
                    answer=10;
                cout<<answer<<endl;
        }
}