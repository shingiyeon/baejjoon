//# Author : nuclear852 ========================#
//# Solution : 5000059 =========================#
//# Time Stamp : 2017-01-12 13:26:25 ===========#
//# Problem Title : 반도체 설계 =================#
//# Language : C++98 ===========================#

#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
        int arr[40001];
        vector<int> list;
        int N;
        cin>>N;
        for(int i=1; i<=N; i++)
                scanf("%d",&arr[i]);
        for(int i=1; i<=N; i++)
        {
                if(list.empty())
                        list.push_back(arr[i]);
                else if(arr[i] > list.back())
                        list.push_back(arr[i]);
                else{
                        int s = 0;
                        int e = list.size();
                        int mid = (s+e) / 2;
                        while(1)
                        {
                                if( list[mid] > arr[i])
                                {
                                        if( mid-1 < 0){
                                                list[0] = arr[i];
                                                break;
                                        }
                                        else if( list[mid-1] < arr[i]){
                                                list[mid] = arr[i];
                                                break;
                                        }
                                        else{
                                                e = mid;
                                                mid = (s+e) / 2;
                                        }
                                }
                                else
                                {
                                        s = mid+1;
                                        mid = (s+e) / 2;
                                }
                        }
                }
        }
        cout<<list.size()<<endl;
}