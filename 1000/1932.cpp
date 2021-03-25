//# Author : nuclear852 ========================#
//# Solution : 1365667 =========================#
//# Time Stamp : 2016-01-23 20:29:47 ===========#
//# Problem Title : 정수 삼각형 =================#
//# Language : C++98 ===========================#

#include <iostream>
using namespace std;
int max(int a, int b)
{
        if(a<b)
                return b;
        else
                return a;
}

int main(void) {
        int n;
        cin>>n;
        int arr[n][n];
        int dy[n][n];
        for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                        dy[i][j]=0;}}
        for(int i=0; i<n; i++){
                for(int j=0; j<=i; j++){
                        cin>>arr[i][j];}}
        dy[0][0]=arr[0][0];
        for(int i=1; i<n; i++)
        {
                for(int j=0; j<=i; j++)
                {
                        if(j>0 && j<i)
                        {
                                dy[i][j]=max(dy[i-1][j-1],dy[i-1][j])+arr[i][j];
                        }

                        else if(j==0)
                        {
                                dy[i][j]=dy[i-1][j]+arr[i][j];
                        }

                        else if(j==i)
                        {
                                dy[i][j]=dy[i-1][j-1]+arr[i][j];
                        }
                }
        }
        int temp = dy[n-1][0];
        for(int i=0; i<n; i++)
        {
                temp = max(temp,dy[n-1][i]);
        }
        cout<<temp<<endl;
        return 0;
}