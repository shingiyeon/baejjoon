//# Author : nuclear852 ========================#
//# Solution : 5148863 =========================#
//# Time Stamp : 2017-02-02 15:55:40 ===========#
//# Problem Title : 트리인가? ==================#
//# Language : C++98 ===========================#

#include <iostream>
#include <map>
#include <stdio.h>
using namespace std;
int main(){
        int a=0,b=0;
        bool pos = 1;
        int testcase = 1;
        while(a!=-1&&b!=-1){
                int num = 0;
                scanf("%d %d",&a,&b);
                if(a==-1 && b==-1) break;
                map<int, int> v;
                map<int, int> m;
                while(a!=0&&b!=0){
                        num++;
                        m[b]++; v[a]++; v[b]++;
                        scanf("%d %d",&a,&b);
                }
                map<int, int>::iterator iter;
                for(iter = m.begin(); iter != m.end(); iter++)
                        if((iter->second >= 2) && num!=0)       pos = 0;
                if( (m.size() != v.size()-1) && num!=0 )        pos = 0;
                pos ? printf("Case %d is a tree.\n",testcase) : printf("Case %d is not a tree.\n",testcase);
                testcase++;
                pos = 1;
        }
}