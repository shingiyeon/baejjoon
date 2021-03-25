//# Author : nuclear852 ========================#
//# Solution : 4900858 =========================#
//# Time Stamp : 2016-12-31 15:46:53 ===========#
//# Problem Title : 카드 역배치 =================#
//# Language : C++98 ===========================#

#include <iostream>
using namespace std;

int main(){
        int card[21];
        int tmp[21];
        for(int i=1; i<=20; i++)
                card[i]= i;

        for(int j=0; j<10; j++)
        {
                int s,e;
                cin>>s>>e;
                int temp = 0;
                for(int i=1; i<=20; i++)
                        tmp[i] = card[i];
                for(int i=s; i<=e; i++)
                {
                        card[i] = tmp[e-temp];
                        temp++;
                }
        }
        for(int i=1; i<=20; i++)
                cout<<card[i]<<" ";
}