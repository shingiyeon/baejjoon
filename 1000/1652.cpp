//# Author : nuclear852 ========================#
//# Solution : 5022160 =========================#
//# Time Stamp : 2017-01-15 12:00:29 ===========#
//# Problem Title : 누울 자리를 찾아라 =============#
//# Language : C++98 ===========================#

#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
using std::string;
int main(){
        int N;
        cin>>N;
        char map[103][103];
        bool okay = 1;
        int garo = 0, sero = 0;
        for(int i=0; i<N; i++)
                scanf("%s",map[i]);
        for(int i=0; i<N; i++)
        {
                okay = 1;
                for(int j=0; j<N-1; j++)
                {
                        if( map[i][j] == '.' && map[i][j+1] == '.' && okay == 1)
                        {       garo++; okay = 0;}
                        if( map[i][j] == 'X')
                                okay = 1;
                }
        }
        for(int i=0; i<N; i++)
        {
                okay = 1;
                for(int j=0; j<N-1; j++)
                {
                        if( map[j][i] == '.' && map[j+1][i] == '.' && okay == 1)
                        {       sero++; okay = 0;}
                        if( map[j][i] == 'X')
                                okay = 1;
                }
        }
        cout<<garo<<" "<<sero<<endl;
}