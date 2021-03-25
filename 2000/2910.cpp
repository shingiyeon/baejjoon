//# Author : nuclear852 ========================#
//# Solution : 5134048 =========================#
//# Time Stamp : 2017-01-31 11:13:21 ===========#
//# Problem Title : 빈도 정렬 ==================#
//# Language : C++98 ===========================#

#include <stdio.h>
#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

struct rank{
        int num, fre;
        int ord;
};

bool cmp(struct rank a, struct rank b){
        return a.fre != b.fre? a.fre>b.fre : a.ord < b.ord;
}

int main(){
        int size = 0;
        int N, C;       cin>>N>>C;
        struct rank r[1001];
        for(int i=0; i<1001; i++){
                r[i].num = 0;
                r[i].fre = 0;
        }
        for(int i=0; i<N; i++){
                int temp;
                scanf("%d",&temp);
                int j=0;
                while(r[j].fre!=0 && r[j].num!=temp)    j++;
                r[j].num = temp;
                r[j].ord = j;
                r[j].fre++;
                size = max(size, j);
        }
        sort(r,r+size+1,cmp);
        for(int i=0; i<=size; i++){
                for(int j=0; j<r[i].fre; j++)
                        printf("%d ",r[i].num);
        }
}