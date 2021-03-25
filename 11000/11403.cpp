//# Author : nuclear852 ========================#
//# Solution : 2215129 =========================#
//# Time Stamp : 2016-03-10 22:32:39 ===========#
//# Problem Title : 경로 찾기 ==================#
//# Language : C++98 ===========================#

#include <iostream>
#include <vector>
#include <stack>
using namespace std;
int main(void){
        int N;
        cin>>N;
        bool visited[N];
        vector<int> gra[N];
        bool answer[N][N];
        for(int i=0;i<N;i++){
                for(int j=0;j<N;j++){
                        bool tmp;
                        cin>>tmp;
                        if(tmp)
                                gra[i].push_back(j);
                }
        }
        for(int i=0; i<N; i++){
                for(int j=0; j<N; j++){
                        for(int k=0; k<N; k++)
                                visited[k] = 0;
                        stack<int> s;
                        s.push(i);
                        visited[i] = 1;
                        bool okay=0;
                        while( !s.empty()){
                                int point = s.top();
                                s.pop();
                                for(int k=0; k<gra[point].size(); k++){
                                        if( gra[point].at(k) == j){
                                                okay = 1;
                                                break;
                                        }
                                        if( visited[gra[point].at(k)] == 0)
                                        {
                                                s.push( gra[point].at(k));
                                                visited[gra[point].at(k)] = 1;
                                        }
                                }
                        }
                        if(okay == 1)
                                answer[i][j] = 1;
                        else
                                answer[i][j] = 0;
                }
        }

        for(int i=0; i<N; i++)
        {
                for(int j=0; j<N; j++)
                        cout<<answer[i][j]<<" ";
                cout<<endl;
        }
}