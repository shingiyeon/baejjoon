//# Author : nuclear852 ========================#
//# Solution : 5227630 =========================#
//# Time Stamp : 2017-02-16 10:07:35 ===========#
//# Problem Title : 결혼식 ====================#
//# Language : C++98 ===========================#

#include <iostream>
#include <map>
#include <stdio.h>
#include <vector>
#include <string.h>
using namespace std;
int main(){
        map<int, int> m;
        int a, b; cin>>a>>b;
        vector<int> list[505];
        for(int i=0; i<b; i++){
                int r1, r2;
                scanf("%d%d",&r1,&r2);
                list[r1].push_back(r2);
                list[r2].push_back(r1);
        }
        m[1] = 1;
        for(int i=0; i<list[1].size(); i++){
                int n = list[1][i];
                m[n] = 1;
                for(int j=0; j<list[n].size(); j++)
                        m[ list[n][j] ] = 1;
        }
        int ans = 0;
        for(int i=1; i<=a; i++) ans += m[i];
        cout<< ans-1;
}