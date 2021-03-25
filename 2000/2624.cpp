//# Author : nuclear852 ========================#
//# Solution : 5002525 =========================#
//# Time Stamp : 2017-01-12 17:16:26 ===========#
//# Problem Title : 동전 바꿔주기 ================#
//# Language : C++98 ===========================#

#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

struct coin{
        int money;
        int num;
};

bool cmp(struct coin a, struct coin b){
        return a.money < b.money;
}

int main(){
        int dy[101][10001];
        int T;
        int k;
        struct coin c[101];
        cin>>T>>k;
        for(int i=1; i<=k; i++)
                scanf("%d %d",&c[i].money,&c[i].num);
        for(int i=1; i<=T; i++)
                dy[0][i] = 0;
        dy[0][0] = 1;
        sort(c+1, c+k+1, cmp);
        for(int i=1; i<=k; i++)
                for(int j=0; j<=T; j++)
                        dy[i][j] = 0;
        for(int i=1; i<=k; i++){
                for(int j=0; j<=T; j++){
                        int temp = 0;
                        while( c[i].money * temp <= j && temp <= c[i].num)
                        {
                                dy[i][j] = dy[i][j] +dy[i-1][j - (c[i].money*temp)];
                                temp++;
                        }
                }
        }
        cout<<dy[k][T]<<endl;
}