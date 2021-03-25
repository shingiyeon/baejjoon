//# Author : nuclear852 ========================#
//# Solution : 2250242 =========================#
//# Time Stamp : 2016-03-12 20:37:38 ===========#
//# Problem Title : 배 ======================#
//# Language : C++98 ===========================#

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool cmp(int a, int b){
        return a>b;
}
int main(void){
        int N,M;
        int weight[50];
        vector<int> box;
        int ans = 0;
        int max = 0;
        cin>>N;
        for(int i=0; i<N; i++){
                cin>>weight[i];
                if(weight[i] > max)
                        max = weight[i];
        }
        cin>>M;
        for(int i=0; i<M; i++){
                int temp;
                cin>>temp;
                box.push_back(temp);
                if(temp > max)
                        ans = -1;
        }
        sort( box.begin(), box.end(), cmp);
        if( ans != -1){
        while( !box.empty())
        {
                for(int i=0; i<N; i++)
                {
                        for(int j=0; j< box.size(); j++)
                        {
                                if( box[j] <= weight[i]){
                                        box.erase( box.begin() + j);
                                        break;
                                }
                        }
                }
                ans++;
        }}
        cout<<ans<<endl;
}