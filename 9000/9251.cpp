//# Author : nuclear852 ========================#
//# Solution : 4943699 =========================#
//# Time Stamp : 2017-01-05 16:29:33 ===========#
//# Problem Title : LCS ====================#
//# Language : C++98 ===========================#

#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;

char a[1005], b[1005];
int arr[1005][1005];
int n;

int dy(int x, int y)
{
        int max = 0;
        if(x<0 || y<0)
                return 0;
        else if( arr[x][y] != -1)
                return arr[x][y];
        else if( a[x] == b[y]){
                arr[x][y] = 1 + dy(x-1, y-1);
                return arr[x][y];
        }
        else{
                if( dy(x-1, y) > max)
                        max = dy(x-1, y);
                if( dy(x, y-1) > max)
                        max = dy(x, y-1);
        }
        arr[x][y] = max;
        return arr[x][y];
}


int main(){
        for(int i=0; i<=1000; i++)
                for(int j=0; j<=1000; j++)
                        arr[i][j] = -1;
        scanf("%s", a);
        scanf("%s", b);
        cout<<dy(strlen(a)-1,strlen(b)-1)<<endl;
}