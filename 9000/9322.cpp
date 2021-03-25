//# Author : nuclear852 ========================#
//# Solution : 5134443 =========================#
//# Time Stamp : 2017-01-31 12:39:12 ===========#
//# Problem Title : 철벽 보안 알고리즘 =============#
//# Language : C++98 ===========================#

#include <iostream>
#include <string.h>
#include <stdio.h>
#include <utility>
#include <algorithm>
using namespace std;

bool cmp(pair<int,int> a, pair<int,int> b){
        return a.second < b.second;
}

int main(){
        int T;
        cin>>T;
        while(T--){
                int n;  cin>>n;
                pair <int, int> p[1001];
                char key[4][1001][11];
                for(int j=0; j<3; j++){
                        for(int i=0; i<n; i++)
                                scanf("%s", key[j][i]);
                }
                for(int i=0; i<n; i++){
                        for(int j=0; j<n; j++){
                                if( !strcmp(key[1][i], key[0][j])){
                                        p[i].first = i;
                                        p[i].second = j;
                                        break;
                                }
                        }
                }
                sort(p, p+n, cmp);
                for(int i=0; i<n; i++)
                        printf("%s ", key[2][ p[i].first ]);
                printf("\n");
        }
}