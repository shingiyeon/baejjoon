//# Author : nuclear852 ========================#
//# Solution : 5007780 =========================#
//# Time Stamp : 2017-01-13 11:14:52 ===========#
//# Problem Title : LCS 2 ==================#
//# Language : C++98 ===========================#

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
char x[1001];
char y[1001];
int dy[1002][1002];
int alen;
int blen;

using namespace std;
int d(int a, int b)
{
        if(a >= alen || b >= blen)
                return 0;
        if( dy[a][b] != -1)
                return dy[a][b];
        if( x[a] == y[b]){
                return dy[a][b] = 1+d(a+1,b+1);
        }
        if( x[a] != y[b]){
                return dy[a][b] = max( d(a+1,b), d(a,b+1));
        }
}

int main(){
        memset(dy,-1,sizeof(dy));
        cin>>x>>y;
        alen = strlen(x);
        blen = strlen(y);
        d(0,0);
        int xx = 0;
        int yy = 0;
        vector<char> st;
        do{
                if( x[xx] == y[yy] ){
                        st.push_back(x[xx]);
                        xx++;
                        yy++;
                }
                else if( xx+1 >= alen)
                        yy++;
                else if( yy+1 >= blen)
                        xx++;
                else{
                        if( dy[xx][yy] == dy[xx+1][yy])
                                xx++;
                        else
                                yy++;
                }

        }while( xx<alen && yy<blen);
        /*for(int i=0; i<alen; i++){
                for(int j=0; j<blen; j++)
                        cout<<dy[i][j]<<" ";
                cout<<endl;
        }*/
        cout<<dy[0][0]<<endl;
        for(int i=0; i<st.size(); i++)
                cout<<st[i];
        cout<<endl;
}