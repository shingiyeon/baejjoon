//# Author : nuclear852 ========================#
//# Solution : 2232227 =========================#
//# Time Stamp : 2016-03-11 20:37:29 ===========#
//# Problem Title : 직사각형에서 탈출 ==============#
//# Language : C++98 ===========================#

#include <iostream>
using namespace std;
int main(void){
    int x,y,w,h;
    cin>>x>>y>>w>>h;
    int ansx,ansy;
    if(x>w-x)
        ansx = w-x;
    else
        ansx = x;
    if(y>h-y)
        ansy = h-y;
    else
        ansy = y;
    if(ansx > ansy)
        ansx=ansy;
    cout<<ansx<<endl;
}