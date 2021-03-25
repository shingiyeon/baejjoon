//# Author : nuclear852 ========================#
//# Solution : 1799458 =========================#
//# Time Stamp : 2016-02-19 10:15:58 ===========#
//# Problem Title : 순열 사이클 =================#
//# Language : C++98 ===========================#

#include <iostream>
using namespace std;
int main(){
        int T;
        cin >> T;
        for(int test =0; test<T; test++)
        {
                int N;
                int ans=0;
                cin>>N;
                bool visited[N+1];
                int arr[N+1];
                for(int i=1; i<=N; i++)
                {
                        cin>>arr[i];
                        visited[i] = 0;
                }

                for(int i=1; i<=N; i++)
                {
                        if(visited[i] == 0)
                        {
                                int temp=arr[i];
                                bool tempvisited[N+1];
                                int okay = 1;
                                for(int j=1; j<=N; j++)
                                        tempvisited[j]=0;
                                tempvisited[i]=1;

                                while( tempvisited[temp] != 1)
                                {
                                        tempvisited[temp] = 1;
                                        temp = arr[temp];
                                }

                                for(int j=1; j<=N; j++)
                                {
                                        if( tempvisited[j] ==1)
                                        {
                                                if(visited[j]==1)
                                                        okay=0;
                                                visited[j] =1;
                                        }
                                }
                                if(okay == 1)
                                        ans++;

                        }
                }
                cout<<ans<<endl;
        }
}