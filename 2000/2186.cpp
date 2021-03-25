//# Author : nuclear852 ========================#
//# Solution : 5071805 =========================#
//# Time Stamp : 2017-01-21 09:39:29 ===========#
//# Problem Title : 문자판 ====================#
//# Language : C++98 ===========================#

#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
int main(){
        int N,M,K; cin>>N>>M>>K;
        char map[103][103];
        int dx[4] = {-1,0,1,0};
        int dy[4] = { 0,1,0,-1};
        int x, y;
        int ans = 0;
        int arr[103][103][82];  memset(arr,0,sizeof(arr));
        for(int i=0; i<N; i++)  scanf("%s",map[i]);
        char key[83]; scanf("%s",key);
        int keylen = strlen(key);
        for(int i=0; i<N; i++){
                for(int j=0; j<M; j++){
                        if(map[i][j] == key[0])
                                arr[i][j][0] = 1;
                }
        }
        for(int k=1; k<keylen; k++){
                for(int i=0; i<N; i++){
                        for(int j=0; j<M; j++){
                                int tmp = 0;
                                if(map[i][j] == key[k]){
                                        for(int l=1; l<=K; l++){
                                                for(int m=0; m<4; m++){
                                                        x=i+(l*dx[m]); y=j+(l*dy[m]);
                                                        if(x<0||x>=N||y<0||y>=M)        continue;
                                                        tmp += arr[x][y][k-1];
                                                }
                                        }
                                        arr[i][j][k] = tmp;
                                }
                        }
                }
        }
        for(int i=0; i<N; i++){
                for(int j=0; j<M; j++){
                        ans +=arr[i][j][keylen-1];
                }
        }
        cout<<ans;
}