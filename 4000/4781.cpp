//# Author : nuclear852 ========================#
//# Solution : 4911702 =========================#
//# Time Stamp : 2017-01-02 11:08:00 ===========#
//# Problem Title : 사탕 가게 ==================#
//# Language : C++98 ===========================#

#include <iostream>
#include <stdio.h>
using namespace std;

struct candy{
        int c;
        int p;
        float p1;
};

int main(){
        int n;
        float m;
        int money;
        int dy[10001];
        dy[0] = 0;
        struct candy arr[5001];
        while(1)
        {
                dy[0] = 0;
                scanf("%d %f",&n, &m);
                money = m*100;
                if(n==0 && m==0)
                        break;
                for(int i=0; i<n; i++){
                        scanf("%d %f",&arr[i].c,&arr[i].p1);
                        arr[i].p = arr[i].p1*100;
                }

                for(int i=1; i<=money; i++){
                        int max = 0;
                        for(int j=0; j<n; j++)
                        {
                                if( i >= arr[j].p)
                                {
                                        if(dy[i- arr[j].p] + arr[j].c > max)
                                                max = dy[i-arr[j].p] + arr[j].c;
                                }
                        }
                        dy[i] = max;
                }
                cout<<dy[money]<<endl;
        }
}