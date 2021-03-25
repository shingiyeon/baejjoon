//# Author : nuclear852 ========================#
//# Solution : 5149805 =========================#
//# Time Stamp : 2017-02-02 17:32:42 ===========#
//# Problem Title : 내 학점을 구해줘 ==============#
//# Language : C++98 ===========================#

#include <stdio.h>
int main(){
        int T;
        scanf("%d",&T);
        while(T--){
                int N;  scanf("%d",&N);
                int num = 0;    float g = 0;
                while(N--){
                        int temp; float score; scanf("%d %f",&temp,&score);
                        num+=temp;
                        g+=(temp*score);
                }
                printf("%d %.1f\n",num,g/num);
        }
}