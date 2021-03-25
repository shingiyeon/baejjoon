//# Author : nuclear852 ========================#
//# Solution : 5169455 =========================#
//# Time Stamp : 2017-02-06 15:55:27 ===========#
//# Problem Title : 배스킨라빈스 31 ==============#
//# Language : C++98 ===========================#

#include <iostream>
#include <stdio.h>
using namespace std;
int main(){
        int n; cin>>n;
        int num; int len=99999999;
        for(int i=1; i<=n; i++){
                int t=0;
                int j, m; cin>>j>>m;
                int r= (j-1)%(1+m);
                t = (int)(r/m) + (r%m ? 1: 0);
                j = j-r;
                t += 2*(int)(j/(m+1)) + 1;
                if( t < len){
                        len = t;
                        num = i;
                }
        }
        cout<<num<<" "<<len;
}