//# Author : nuclear852 ========================#
//# Solution : 4897466 =========================#
//# Time Stamp : 2016-12-30 22:46:04 ===========#
//# Problem Title : 철로 =====================#
//# Language : C++98 ===========================#

#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <queue>

using namespace std;

struct graph {
        int low;
        int high;
};

bool cmp_graph(graph a, graph b) {
        return a.high < b.high;
}
int main()
{
        int tmp1, tmp2;
        int n;
        struct graph pos[100005];
        int d;
        int max = 0;
        priority_queue<int> q;
        scanf("%d", &n);
        for (int i = 0; i < n; i++){
                scanf("%d %d", &tmp1, &tmp2);
                if(tmp1 > tmp2){
                        pos[i].high = tmp1;
                        pos[i].low = tmp2;
                }
                else{
                        pos[i].high = tmp2;
                        pos[i].low = tmp1;
                }
        }
        scanf("%d", &d);
        sort(pos, pos + n, cmp_graph);
        for (int i = 0; i < n; i++)
        {
                q.push(-pos[i].low);
                while( !q.empty() && -q.top() < pos[i].high - d)
                        q.pop();
                if( q.size() > max)
                        max = q.size();
        }
        printf("%d", max);
}