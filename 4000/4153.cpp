//# Author : nuclear852 ========================#
//# Solution : 5159934 =========================#
//# Time Stamp : 2017-02-04 17:16:44 ===========#
//# Problem Title : 직각삼각형 ==================#
//# Language : C++98 ===========================#

#include <iostream>
#include <algorithm>
using namespace std;
int main(){
        int a, b, c; cin>>a>>b>>c;
        while( !(!a&&!b&&!c)){
                if(a*a+b*b==c*c) cout<<"right\n";
                else if(a*a+c*c==b*b) cout<<"right\n";
                else if(b*b+c*c==a*a) cout<<"right\n";
                else cout<<"wrong\n";
                cin>>a>>b>>c;
        }
}