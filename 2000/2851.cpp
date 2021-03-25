//# Author : nuclear852 ========================#
//# Solution : 5158663 =========================#
//# Time Stamp : 2017-02-04 11:38:46 ===========#
//# Problem Title : 슈퍼 마리오 =================#
//# Language : C++98 ===========================#

#include <iostream>
#include <stdlib.h>
using namespace std;
int main(){
        int arr[11], temp; arr[0] = 0; int ans = 0;
        for(int i=1; i<=10; i++){
                cin>>temp; arr[i] = arr[i-1]+temp;}
        for(int i=0; i<=10; i++){
                if( abs(100-ans) > abs(100-arr[i]) )
                        ans = arr[i];
                else if( abs(100-ans) == abs(100-arr[i]))
                        ans = (arr[i] > ans ? arr[i] : ans);
        }
        cout<<ans;
}