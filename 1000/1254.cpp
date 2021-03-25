//# Author : nuclear852 ========================#
//# Solution : 5011733 =========================#
//# Time Stamp : 2017-01-13 19:41:57 ===========#
//# Problem Title : 팰린드롬 만들기 ===============#
//# Language : C++98 ===========================#

#include <iostream>
#include <string.h>
using namespace std;
int main(){
        char s[1002];
        cin>>s;
        int N = strlen(s);
        int min = 9999;
        for(int i=0; i<=N-1; i++)
        {
                bool pos = 1;
                int e = N-1;
                for(int j=i; j<=N-1; j++)
                {
                        if( s[j] != s[e]){
                                pos = 0;
                                break;
                        }
                        e--;
                }
                if(pos==1 && i < min)
                        min = i;
        }
        cout<<N+min<<endl;
}