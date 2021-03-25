//# Author : nuclear852 ========================#
//# Solution : 5013044 =========================#
//# Time Stamp : 2017-01-13 22:50:55 ===========#
//# Problem Title : 저항 =====================#
//# Language : C++98 ===========================#

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>
using namespace std;
using std::string;
int main(){
        string s[10] = {"black","brown","red","orange","yellow","green","blue","violet", "grey", "white"};
        string input[3];
        cin>>input[0]>>input[1]>>input[2];
        long long ans = 0;
        int temp;
        for(int i=0; i<10; i++){
                if( s[i] == input[0])
                        ans += i*10;
                if( s[i] == input[1])
                        ans += i;
                if( s[i] == input[2])
                        temp = i;
        }
        ans = ans * pow(10, temp);
        cout<<ans<<endl;
}