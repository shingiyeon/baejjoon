//# Author : nuclear852 ========================#
//# Solution : 2294406 =========================#
//# Time Stamp : 2016-03-15 00:44:49 ===========#
//# Problem Title : N-Queen ================#
//# Language : C++98 ===========================#

#include <iostream>
using namespace std;
int row[15];
int N;
int count=0;
bool isPossible(int a, int b)
{
        for(int i=0; i<a; i++)
        {
                if( row[i] == b || i- a == row[i]-b || i-a == b-row[i])
                        return 0;
        }
        return 1;
}
void dfs(int a)
{
        if( a == N){
                count++;
                return;
        }
        else{
                for(int i=0; i<N; i++)
                {
                        if( isPossible(a,i)){
                                row[a] = i;
                                dfs(a+1);
                        }
                }
        }
}
int main(void)
{
        cin>>N;
        dfs(0);
        cout<<count<<endl;
}