//# Author : nuclear852 ========================#
//# Solution : 5129739 =========================#
//# Time Stamp : 2017-01-30 16:26:45 ===========#
//# Problem Title : 영화 수집 ==================#
//# Language : C++98 ===========================#

#include <iostream>
#include <vector>
#include <stdio.h>
#include <string.h>
using namespace std;

int arr[200001];

int sum(vector<int> &tree, int i) {
        int ans = 0;
        while( i>0) {
                ans += tree[i];
                i -= (i & -i);
        }
        return ans;
}

void update(vector<int> &tree, int i, int diff){
        while( i<tree.size()){
                tree[i] += diff;
                i+=(i&-i);
        }
}

int main(){
        int T;  cin>>T;
        while(T--){
                int n, m;
                cin>>n>>m;
                memset(arr,0,sizeof(arr));
                vector<int> tree(200001);
                int height = n;
                for(int i=1; i<=n; i++){
                        update(tree,i,1);
                        arr[i] = n-i+1;
                }
                while(m--){
                        int temp;
                        scanf("%d", &temp);
                        printf("%d ", sum(tree,200000)-sum(tree,arr[temp]));
                        height++;
                        update(tree, arr[temp], -1);
                        arr[temp] = height;
                        update(tree, arr[temp], 1);
                }
                printf("\n");
        }
}