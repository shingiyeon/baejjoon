//# Author : nuclear852 ========================#
//# Solution : 5159907 =========================#
//# Time Stamp : 2017-02-04 17:12:48 ===========#
//# Problem Title : 거스름돈 ===================#
//# Language : C++98 ===========================#

#include <iostream>
using namespace std;
int main(){
        int N; cin>>N;
        N = 1000-N;
        int ans = 0;
        while(N!=0){
                if(N>=500)      N=N-500;
                else if(N>=100) N=N-100;
                else if(N>=50)  N=N-50;
                else if(N>=10) N=N-10;
                else if(N>=5) N=N-5;
                else if(N>=1) N=N-1;
                ans++;}
        cout<<ans;
}