//# Author : nuclear852 ========================#
//# Solution : 5143217 =========================#
//# Time Stamp : 2017-02-01 17:36:18 ===========#
//# Problem Title : TGN ====================#
//# Language : C++98 ===========================#

#include <iostream>
#include <stdio.h>
using namespace std;
int main(){
        int T;  cin>>T;
        while(T--){
                int r,e,c;      scanf("%d %d %d",&r,&e,&c);
                r+c-e == 0 ? cout<<"does not matter"<<'\n' : ((r+c-e > 0) ? cout<<"do not advertise"<<'\n' : cout<<"advertise"<<'\n');
        }
}