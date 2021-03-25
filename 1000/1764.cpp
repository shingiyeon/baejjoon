//# Author : nuclear852 ========================#
//# Solution : 5149462 =========================#
//# Time Stamp : 2017-02-02 16:57:03 ===========#
//# Problem Title : 듣보잡 ====================#
//# Language : C++11 ===========================#

#include <stdio.h>
#include <iostream>
#include <map>
#include <algorithm>
using namespace std;
int main(){
        map<string, int> m;
        int N, M;       cin>>N>>M;
        string a;
        for(int i=0; i<N+M; i++){
                cin>>a;
                m[a]++;
        }
        map<string, int>::iterator iter;
        int num = 0;
        for(iter=m.begin(); iter!=m.end(); iter++){
                if(iter->second >= 2)
                       num++;
        }
        cout<<num<<"\n";
        for(iter=m.begin(); iter!=m.end(); iter++){
                if(iter->second >= 2)
                        cout<<iter->first<<"\n";
        }
}