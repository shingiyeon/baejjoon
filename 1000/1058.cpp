//# Author : nuclear852 ========================#
//# Solution : 5216427 =========================#
//# Time Stamp : 2017-02-14 14:53:05 ===========#
//# Problem Title : 친구 =====================#
//# Language : C++98 ===========================#

#include <iostream>
#include <map>
#include <string.h>
#include <stdio.h>
#include <algorithm>
using namespace std;
int main(){
        int N; cin>>N;
        char c[50][100];
        for(int i=0; i<N; i++) scanf("%s",c[i]);
        map<int, int> m[50];
        int MAX = 0;
        for(int i=0; i<N; i++){
                for(int j=0; j<N; j++){
                        if(i==j) m[i][j] = 1;
                        if(c[i][j] == 'Y'){
                                 m[i][j] = 1;
                                 for(int k=0; k<N; k++){
                                        if(c[j][k] == 'Y'){
                                                m[i][k] = 1;
                                        }
                                }
                        }
                }
                int k = m[i].size()-1;
                MAX = max(MAX, k);
        }
        cout<<MAX;
}