//# Author : nuclear852 ========================#
//# Solution : 4999108 =========================#
//# Time Stamp : 2017-01-12 10:57:07 ===========#
//# Problem Title : 공통 부분 문자열 ==============#
//# Language : C++98 ===========================#

#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
int dy[4003][4003];
char A[4003];
char B[4003];
int alen, blen;
int x(int a, int b)
{
        if(a > alen || b > blen)
                return 0;
        if(dy[a][b] != -1)
                return dy[a][b];
        else{
                if( A[a] == B[b] )
                        return dy[a][b] = x(a+1,b+1) + 1;
                else
                        return dy[a][b] = 0;
        }
}
int main(){
        cin>>A>>B;
        alen = strlen(A) - 1;
        blen = strlen(B) - 1;
        int Max = 0;
        for(int i=0; i<=alen; i++)
                for(int j=0; j<=blen; j++)
                        dy[i][j] = -1;
        for(int i=alen; i>=0; i--)
                for(int j=blen; j>=0; j--)
                        Max = max(Max, x(i,j));
        cout << Max << endl;
}