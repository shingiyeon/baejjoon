//# Author : nuclear852 ========================#
//# Solution : 5149355 =========================#
//# Time Stamp : 2017-02-02 16:46:19 ===========#
//# Problem Title : 점수 계산 ==================#
//# Language : C++98 ===========================#

#include <algorithm>
#include <iostream>
#include <utility>
using namespace std;
bool cmp(pair<int, int> a, pair<int, int> b){
        return a.first>b.first;
}
bool cmp2(pair<int, int> a, pair<int, int> b){
        return a.second<b.second;
}
int main(){
        pair<int, int> arr[8];
        for(int i=0; i<8; i++){
                cin>>arr[i].first; arr[i].second = i+1;
        }
        sort(arr,arr+8,cmp);    int sum = 0;
        for(int i=0; i<5; i++)  sum += arr[i].first;
        cout<<sum<<endl;
        sort(arr,arr+5,cmp2);
        for(int i=0; i<5; i++) cout<<arr[i].second<<" ";
}