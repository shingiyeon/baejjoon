//# Author : nuclear852 ========================#
//# Solution : 5090636 =========================#
//# Time Stamp : 2017-01-24 01:15:16 ===========#
//# Problem Title : 토너먼트 ===================#
//# Language : C++98 ===========================#

#include <iostream>
using namespace std;
int main(){
        int N, a, b;    cin>>N>>a>>b;
        int tmp = 1;
        while( (a-1)/2+1 != (b-1)/2+1 ){
                a = (a-1)/2+1;
                b = (b-1)/2+1;
                tmp++;
        }
        cout<<tmp<<endl;
}