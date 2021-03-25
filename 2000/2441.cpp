//# Author : nuclear852 ========================#
//# Solution : 5174488 =========================#
//# Time Stamp : 2017-02-07 12:28:52 ===========#
//# Problem Title : 별 찍기 - 4 ===============#
//# Language : C++98 ===========================#

#include <iostream>
using namespace std;
int main(){
        int N; cin>>N;
        for(int i=1; i<=N; i++){
                for(int j=1; j<=i-1; j++) cout<<" ";
                for(int j=1; j<=N-i+1; j++) cout<<"*";
                cout<<"\n";
        }
}