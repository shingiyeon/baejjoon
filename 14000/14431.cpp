//# Author : nuclear852 ========================#
//# Solution : 5169285 =========================#
//# Time Stamp : 2017-02-06 15:34:09 ===========#
//# Problem Title : 소수마을 ===================#
//# Language : C++98 ===========================#

#include <iostream>
#include <queue>
#include <vector>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;

struct village{
        int x, y;
};

int main(){
        bool sosu[4500]; memset(sosu,1,sizeof(sosu));
        sosu[0] = 0; sosu[1] = 0;
        for(int i=2; i<4500; i++){
                if(sosu[i] == 1){
                        for(int j=i*2; j<4500; j+=i){
                                sosu[j] = 0;
                        }
                }
        }
        struct village v[4005];
        int visited[4005]; bool vv[4005];
        for(int i=0; i<4005; i++) {visited[i] = 99999999; vv[i] = 0;}
        scanf("%d%d%d%d",&v[0].x,&v[0].y,&v[1].x,&v[1].y);
        int N; cin>>N;
        for(int i=2; i<N+2; i++) scanf("%d%d",&v[i].x,&v[i].y);
        visited[0] = 0;
        int p = 0;
        bool pos = 1; vv[0] = 1;
        while(p!=1){
                pos = 0;
                int np;
                int minv=99999999;
                for(int i=1; i<N+2; i++){
                        int k = (int)sqrt(pow(v[i].x-v[p].x,2) + pow(v[i].y-v[p].y,2));
                        if( sosu[k] && !vv[i]) {
                                if( visited[p]+k <= visited[i] ){
                                        visited[i] = visited[p]+k;
                                }
                        }
                }
                for(int i=1; i<N+2; i++){
                        if(vv[i] == 0 && visited[i] <minv){
                                pos = 1;
                                minv = visited[i];
                                np = i;
                        }
                }
                if(pos==0) break;
                vv[np] = 1;
                p = np;
        }
        if( visited[1] == 99999999) cout<<"-1";
        else    cout<<visited[1];
}