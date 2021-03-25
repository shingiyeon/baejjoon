//# Author : nuclear852 ========================#
//# Solution : 12987227 ========================#
//# Time Stamp : 2019-05-01 14:32:10 ===========#
//# Problem Title : 트럭 =====================#
//# Language : C++98 ===========================#

#include <stdio.h>
#include <vector>

using namespace std;
int weight[1001];

int main(){
    int n, w, L;
    scanf("%d%d%d",&n,&w,&L);
    for(int i=0; i<n; i++)  scanf("%d", &weight[i]);
    int total = 0;
    int t = 0;
    int idx = 0;
    vector<int> v;    
    for(int i=0; i<w ; i++) v.push_back(0);
    while(idx < n){
        total -= v[0];
        v.erase(v.begin());
        if(total + weight[idx] <= L){
            total += weight[idx];
            v.push_back(weight[idx++]);
        }
        else v.push_back(0);
        t++;
    }
    printf("%d", t+w);
}