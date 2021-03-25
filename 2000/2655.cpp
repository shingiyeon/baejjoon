//# Author : nuclear852 ========================#
//# Solution : 4932525 =========================#
//# Time Stamp : 2017-01-04 13:42:47 ===========#
//# Problem Title : 가장높은탑쌓기 ================#
//# Language : C++98 ===========================#

#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int dy[101];
int start[101];

struct stone{
        int area;
        int height;
        int weight;
        int num;
}w[101];

bool cmp(struct stone a, struct stone b)
{
        return a.area < b.area? 1 : 0;
}

int dyna(int a)
{
        int max = w[a].height;
        if(dy[a] != 0)
                return dy[a];
        for(int i=a-1; i>=1; i--)
        {
                int temp = w[a].height;
                if(w[i].weight <= w[a].weight)
                        temp += dy[i];
                if(temp > max){
                        max = temp;
                        start[ w[a].num ] = w[i].num;
                }
        }
        dy[a] = max;
        return dy[a];
}

int main(){
        vector<int> order;
        cin>>N;
        for(int i=1; i<=N; i++){
                dy[i] = 0;
                scanf("%d %d %d",&w[i].area,&w[i].height,&w[i].weight);
                start[i] = 0;
                w[i].num = i;
        }
        sort(w+1,w+N+1,cmp);
        int max = 0;
        int startt = 0;
        for(int i=1; i<=N; i++){
                int temp = dyna(i);
                if(temp > max){
                        max = temp;
                        startt = w[i].num;
                }
        }
        int tmp = startt;
        while( tmp != 0)
        {
                order.push_back(tmp);
                tmp= start[tmp];
        }
        cout<<order.size()<<endl;
        for(int i=order.size()-1; i>=0; i--)
                printf("%d\n",order[i]);

}