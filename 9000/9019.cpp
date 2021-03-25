//# Author : nuclear852 ========================#
//# Solution : 5055850 =========================#
//# Time Stamp : 2017-01-19 10:36:58 ===========#
//# Problem Title : DSLR ===================#
//# Language : C++98 ===========================#

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <utility>
#include <queue>
using namespace std;
int main(){
        int T; cin>>T;
        while(T--){
                char DSLR[4] = {'D', 'S', 'L', 'R'};
                int s; int d; cin>>s>>d;
                vector<char> ans;
                int temp = d;
                char visited[10003];    memset(visited,0,sizeof(visited));
                int ivisited[10003];    memset(ivisited, 0, sizeof(ivisited));
                int n;
                int arr[4];
        //      vector<char> v; 
                queue< int > q;
                q.push( s);     visited[s] = 'E';       ivisited[s] = -1;
                while(!q.empty()){
                        n = q.front();  /*v = q.front().second;*/       q.pop();
                        arr[0] = (n*2)%10000;   arr[1] = ( (n==0)? 9999: n-1);
                        arr[2] = ((int)(n%1000))*10 + (int)(n/1000);
                        arr[3] = (int)(n/10) + ((int)(n%10))*(1000);
                        if( n == d) break;
                        for(int i=0; i<4; i++){
                                if( visited[ arr[i] ] != 0)     continue;
                                q.push( arr[i]);
                                visited[ arr[i] ] = DSLR[i];
                                ivisited[ arr[i] ]  = n;
                        }
                }
                while( temp != s){
                        ans.push_back( visited[temp]);
                        temp = ivisited[temp];
                }
                for(int i=ans.size()-1; i>=0; i--)
                        cout<<ans[i];
                cout<<endl;
        }
}