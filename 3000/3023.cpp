//# Author : nuclear852 ========================#
//# Solution : 5160182 =========================#
//# Time Stamp : 2017-02-04 18:08:11 ===========#
//# Problem Title : 마술사 이민혁 ================#
//# Language : C++98 ===========================#

#include <iostream>
#include <stdio.h>
using namespace std;
int main(){
        int R, C; cin>>R>>C;
        char map[102][102];
        for(int i=0; i<R; i++) scanf("%s",map[i]);
        for(int i=0; i<R; i++)
                for(int j=C; j<2*C; j++)
                        map[i][j]=map[i][2*C-1-j];
        for(int i=R; i<2*R; i++)
                for(int j=0; j<2*C; j++)
                        map[i][j]=map[2*R-1-i][j];
        int A,B; cin>>A>>B;
        map[A-1][B-1] == '#' ? map[A-1][B-1] = '.' : map[A-1][B-1] = '#';
        for(int i=0; i<2*R; i++){
                for(int j=0; j<2*C; j++)
                        cout<<map[i][j];
                cout<<"\n";
        }
}