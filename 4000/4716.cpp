//# Author : nuclear852 ========================#
//# Solution : 5256864 =========================#
//# Time Stamp : 2017-02-21 10:37:55 ===========#
//# Problem Title : 풍선 =====================#
//# Language : C++98 ===========================#

#include <iostream>
#include <cstdio>
#include <math.h>
#include <algorithm>
using namespace std;

struct st{
        int n, a, b;
}s[1005];

bool cmp(st A, st B){
        return abs(A.a-A.b) > abs(B.a-B.b);
}

int main(){
        int N, A, B;
        cin>>N>>A>>B;
        while(N!=0||A!=0||B!=0){
                for(int i=0; i<N; i++){
                        scanf("%d%d%d",&s[i].n,&s[i].a,&s[i].b);
                }
                sort(s,s+N,cmp);
                int sum = 0;
                for(int i=0; i<N; i++){
                        if(s[i].a < s[i].b){
                                int temp = s[i].n < A ? s[i].n : A;
                                A -= temp;
                                sum += (temp*s[i].a);
                                temp = s[i].n - temp;
                                B -= temp;
                                sum += (temp*s[i].b);
                        }
                        else{
                                int temp = s[i].n < B? s[i].n : B;
                                B -= temp;
                                sum += (temp*s[i].b);
                                temp = s[i].n - temp;
                                A -= temp;
                                sum += (temp*s[i].a);
                        }
                }
                printf("%d\n",sum);
                scanf("%d%d%d",&N,&A,&B);
        }
}