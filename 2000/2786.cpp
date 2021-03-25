//# Author : nuclear852 ========================#
//# Solution : 5148625 =========================#
//# Time Stamp : 2017-02-02 15:30:57 ===========#
//# Problem Title : 상근이의 레스토랑 ==============#
//# Language : C++98 ===========================#

#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;

struct price{
        int a, b;
        int bmina;
        int num;
};

struct price p1[500005];
struct price p2[500005];
bool visited[500005];

bool cmp(struct price A, struct price B){
        return  A.a< B.a;
}
bool cmp2(struct price A, struct price B){
        return  A.b < B.b;
}
int main(){
        int N;  scanf("%d",&N);
        memset(visited,0,sizeof(visited));
        int m1 = 0; int m2 = 0;
        long long w = 0;
        int temp;
        for(int i=0; i<N; i++){
                scanf("%d %d", &p1[i].a, &p1[i].b);
                p1[i].num = i; p2[i].num = i;
                p1[i].bmina = p1[i].b-p1[i].a;
                p2[i].a = p1[i].a; p2[i].b = p1[i].b;
                p2[i].bmina = p2[i].bmina;
        }
        sort(p1,p1+N,cmp);
        sort(p2,p2+N,cmp2);
        w = p1[0].a;
        temp = p1[0].b - p1[0].a;
        printf("%lld\n",w);
        m1++; visited[p1[0].num] = 1;
        for(int i=1; i<N; i++){
                while( visited[p1[m1].num] == 1 && m1<N)        m1++;
                while( visited[p2[m2].num] == 1 && m2<N)        m2++;
                if( w + temp + p1[m1].a < w + p2[m2].b ) {
                        w = w + temp + p1[m1].a;
                        temp = p1[m1].b - p1[m1].a;
                        visited[p1[m1].num]= 1;
                }
                else{
                        w = w + p2[m2].b;
                        visited[p2[m2].num] = 1;
                }
                printf("%lld\n",w);
        }
}