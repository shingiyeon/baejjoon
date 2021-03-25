//# Author : nuclear852 ========================#
//# Solution : 5141894 =========================#
//# Time Stamp : 2017-02-01 15:26:34 ===========#
//# Problem Title : 불만 정렬 ==================#
//# Language : C++98 ===========================#

#include <stdio.h>
#include <vector>
#include <iostream>
using namespace std;

vector<long long> before(100001);
vector<long long> after(100001);

long long sum(vector<long long> &tree, int i) {
        long long ans = 0;
        while(i>0) {
                ans += tree[i];
                i -= (i & -i);
        }
        return ans;
}

void update(vector<long long> &tree, int i, int diff) {
        while( i<tree.size()){
                tree[i] += diff;
                i += (i & -i);
        }
}

int main(){
        int arr[100005];
        int n;  scanf("%d",&n);
        for(int i=0; i<n; i++){
                scanf("%d", &arr[i]);
                update(after, arr[i], 1);
        }
        long long ans = 0;
        for(int i=0; i<n; i++){
                long long temp = sum(after, arr[i]-1) * ( sum(before, n) - sum(before, arr[i]) );
                ans += temp;
                update(before, arr[i], 1);
                update(after, arr[i], -1);
        }
        printf("%lld",ans);
}