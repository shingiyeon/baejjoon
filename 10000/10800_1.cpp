//# Author : nuclear852 ========================#
//# Solution : 4900720 =========================#
//# Time Stamp : 2016-12-31 15:22:25 ===========#
//# Problem Title : 컬러볼 ====================#
//# Language : C++98 ===========================#

#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

struct ball{
        int size;
        int color;
        int num;
        int sum;
};

bool cmp(ball a, ball b){
        return a.num < b.num;
}

int main()
{
        vector<int> tmpc;
        vector<ball> map[2005];
        int color[200005];
        int tmpcolor[200005];
        struct ball b[200005];
        struct ball c[200005];
        int hap = 0;
        int number = 0;
        int N;
        cin>>N;
        for(int i=1; i<=N; i++){
                scanf("%d %d", &b[i].color, &b[i].size);
                b[i].num = i;
                map[b[i].size].push_back(b[i]);
                tmpcolor[i] = 0;
                color[i] = 0;
                tmpcolor[i] = 0;
        }
        for(int i=1; i<=2000; i++){
                int tempsum = 0;
                for(int j=0; j<map[i].size(); j++)
                {
                        tempsum += map[i][j].size;
                        c[number].sum = hap - color[ map[i][j].color];
                        c[number].num = map[i][j].num;
                        tmpc.push_back(map[i][j].color);
                        number++;
                }
                for(int j=0; j<tmpc.size(); j++){
                        int k = tmpc[j];
                        color[k] += i;
                }
                hap = hap+ tempsum;
                tmpc.clear();
        }
        sort(c, c+N, cmp);
        for(int i=0; i<N; i++)
                printf("%d\n",c[i].sum);
}