//# Author : nuclear852 ========================#
//# Solution : 5136178 =========================#
//# Time Stamp : 2017-01-31 16:46:00 ===========#
//# Problem Title : 패션왕 신해빈 ================#
//# Language : C++98 ===========================#

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <map>
using std::string;
using namespace std;

struct wear{
        char name[22];
        char kind[22];
};

int main(){
        int T; cin>>T;
        while(T--){
                int n; cin>>n;
                struct wear w[31];
                map<string, int> m;
                for(int i=0; i<n; i++){
                        scanf("%s %s",w[i].name, w[i].kind);
                        m[ string (w[i].kind) ]++;
                }
                int ans = 1;
                map<string, int>::iterator iter;
                for(iter = m.begin(); iter != m.end(); ++iter)
                        ans = ans * (iter->second+1);
                ans--;
                printf("%d\n",ans);
        }
}