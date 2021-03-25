//# Author : nuclear852 ========================#
//# Solution : 11789470 ========================#
//# Time Stamp : 2019-02-15 02:41:42 ===========#
//# Problem Title : 피시방 알바 =================#
//# Language : C++98 ===========================#

#include <stdio.h>
bool visited[101];
int main(){
    int N; scanf("%d", &N);
    int sum = 0;
    while(N--){
        int temp; scanf("%d", &temp);
        if(visited[temp]) sum++;
        visited[temp] = 1;
    }
    printf("%d", sum);
}