//# Author : nuclear852 ========================#
//# Solution : 5167680 =========================#
//# Time Stamp : 2017-02-06 10:28:08 ===========#
//# Problem Title : 반올림 ====================#
//# Language : C++98 ===========================#

#include <iostream>
using namespace std;
int main(){
        int N; cin>>N; int temp = 1;
        while(N/(temp*10)){
                if(N%(temp*10) >= 5*temp) N += ( (temp*10) - N%(temp*10));
                else N -= N%(temp*10);
                temp*=10;
        }
        cout<<N;
}