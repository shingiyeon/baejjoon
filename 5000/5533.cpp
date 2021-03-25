//# Author : nuclear852 ========================#
//# Solution : 5243145 =========================#
//# Time Stamp : 2017-02-19 11:34:25 ===========#
//# Problem Title : 유니크 ====================#
//# Language : C++98 ===========================#

#include <stdio.h>
#include <string.h>
int main(){
    int N; scanf("%d",&N);
    int arr[205][3];
    for(int i=0; i<N; i++){
        for(int j=0; j<3; j++){
            scanf("%d",&arr[i][j]);
        }
    }
    int visited[101];
    int sum[205];
    memset(sum,0,sizeof(sum));
    for(int j=0; j<3; j++){
        memset(visited,0,sizeof(visited));
        for(int i=0; i<N; i++){
            visited[arr[i][j]]++;
        }
        for(int i=0; i<N; i++){
            if(visited[arr[i][j]]==1)
                sum[i] += arr[i][j];
        }
    }
    for(int i=0; i<N; i++){
        printf("%d\n",sum[i]);
    }
}