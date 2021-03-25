//# Author : nuclear852 ========================#
//# Solution : 2212491 =========================#
//# Time Stamp : 2016-03-10 19:53:43 ===========#
//# Problem Title : 수열의 합 ==================#
//# Language : C++98 ===========================#

#include <iostream>
using namespace std;
int main(void){
        int N, L;
        cin>>N>>L;
        for(int i=L; i<=100; i++)
        {
                if( i%2){
                        if(N%i == 0)
                        {
                                int a = (N/i) - ((i-1)/2);
                                if( a>=0)
                                {
                                        int b = (N/i) + ((i-1)/2);
                                        for(int j=a; j<=b; j++)
                                                cout<<j<<" ";
                                                return 0;
                                }
                        }
                }
                else{
                        if(N%i == i/2)
                        {
                                int a = (N/i) - ((i/2) - 1);
                                if(a>=0)
                                {
                                        int b = (N/i) + (i/2);
                                        for(int j=a; j<=b; j++)
                                                cout<<j<<" ";
                                                return 0;
                                }
                        }
                }
        }
        cout<<"-1"<<endl;
}