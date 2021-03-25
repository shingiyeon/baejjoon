//# Author : nuclear852 ========================#
//# Solution : 5108024 =========================#
//# Time Stamp : 2017-01-25 22:59:45 ===========#
//# Problem Title : 나는야 포켓몬 마스터 이다솜 ========#
//# Language : C++98 ===========================#

#include <stdio.h>
#include <stdlib.h>
#include <map>
#include <iostream>
#include <string.h>
using namespace std;
using std::string;
int main(){
        int M,N;
        map<int, string> m1;
        map<string, int> m2;
        char temp[22];
        scanf("%d %d",&M,&N);
        for(int i=1; i<=M; i++){
                scanf("%s",temp);
                string str(temp);
                m1[i] = str;
                m2[str] = i;
        }
        for(int i=1; i<=N; i++){
                scanf("%s", temp);
                string str(temp);
                if( temp[0] >= '0' && temp[0] <= '9')
                        printf("%s\n", m1[atoi(temp)].c_str());
                else
                        printf("%d\n", m2[str]);
        }
}