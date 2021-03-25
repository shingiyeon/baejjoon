//# Author : nuclear852 ========================#
//# Solution : 5153090 =========================#
//# Time Stamp : 2017-02-03 10:18:25 ===========#
//# Problem Title : 올림픽 ====================#
//# Language : C++98 ===========================#

#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;
struct medal{
        int gold;
        int silver;
        int bronze;
        int num;
};
bool cmp(struct medal a, struct medal b){
        return a.gold != b.gold ? a.gold>b.gold : (a.silver != b.silver ? a.silver > b.silver : a.bronze>b.bronze);
}
int main(){
        struct medal arr[1005];
        int N, K; cin>>N>>K;
        int rank = 0;
        for(int i=0; i<N; i++)
                scanf("%d %d %d %d",&arr[i].num,&arr[i].gold,&arr[i].silver,&arr[i].bronze);
        sort(arr,arr+N,cmp);
        int tmpg=-1, tmps=-1, tmpb=-1;
        int gae=1;
        int temp =gae;
        for(int i=0; i<N; i++){
                if( arr[i].gold != tmpg || arr[i].silver != tmps || arr[i].bronze != tmpb)
                {       rank+=gae; temp = rank; gae = 1; tmpg = arr[i].gold; tmps = arr[i].silver; tmpb = arr[i].bronze;}
                else{
                        rank = temp;
                        gae++;
                }
                if( arr[i].num == K)
                        cout<<rank;
        }
}