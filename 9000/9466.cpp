//# Author : nuclear852 ========================#
//# Solution : 5089617 =========================#
//# Time Stamp : 2017-01-23 22:54:57 ===========#
//# Problem Title : 텀 프로젝트 =================#
//# Language : C++98 ===========================#

#include <iostream>
#include <stdio.h>
#include <vector>
#include <string.h>
using namespace std;
int main(){
        int T; cin>>T;
        while(T--){
        int n;
        int arr[100003];
        int visited[100003];
        bool pos[100003];
        int num[100003];
        cin>>n;
        for(int i=1; i<=n; i++) {visited[i] = 0; pos[i] = 0;}
        for(int i=1; i<=n; i++)         scanf("%d", &arr[i]);
        for(int i=1; i<=n; i++){
                if(visited[i] == 0){
                        vector<int> v;
                        int temp = i;
                        int numnum = 0;
                        while( visited[temp] == 0){
                                visited[temp] = i;
                                v.push_back(temp);
                                temp = arr[temp];
                        }
                        int j;
                        for(j=0; j<v.size(); j++){
                                if(v[j] == temp)
                                        break;
                        }
                        for(int k=j; k<v.size(); k++)
                                pos[v[k]] = 1;
                }
        }
        int ans = 0;
        for(int i=1; i<=n; i++){
                if(pos[i]==0) ans++;}
        cout<<ans<<'\n';
        }
}