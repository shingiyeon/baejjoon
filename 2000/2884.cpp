//# Author : nuclear852 ========================#
//# Solution : 5143182 =========================#
//# Time Stamp : 2017-02-01 17:32:46 ===========#
//# Problem Title : 알람 시계 ==================#
//# Language : C++98 ===========================#

#include <iostream>
using namespace std;
int main(){
        int x, y;       cin>>x>>y;
        x = (y-45<0)?((x-1<0)?23:x-1):x;
        y = (y-45<0)?15+y:y-45;
        cout<<x<<" "<<y;
}