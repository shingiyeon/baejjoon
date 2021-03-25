//# Author : nuclear852 ========================#
//# Solution : 5169967 =========================#
//# Time Stamp : 2017-02-06 16:56:50 ===========#
//# Problem Title : 준오는 심술쟁이!! =============#
//# Language : C++98 ===========================#

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
char s[3005];
long long dy[3005][3005];
int main(){
        int l;
        for(int i=0; i<3005; i++){
                for(int j=0; j<3005; j++){
                        dy[i][j] = 0;
                }
        }
        cin>>l;
        scanf("%s",s);
        for(int i=0; i<=min(25,l); i++) dy[0][l-i] = 1;
        for(int i=1; i<strlen(s); i++)
                for(int j=0; j<=l; j++){
                                for(int k=0; k<=25; k++)
                                        if(j+k<=l)
                                                dy[i][j] = (dy[i][j]+dy[i-1][j+k]);
                                dy[i][j] = dy[i][j]%1000000007;
                }

        cout<<dy[strlen(s)-1][0];
}