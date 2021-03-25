//# Author : nuclear852 ========================#
//# Solution : 1788439 =========================#
//# Time Stamp : 2016-02-18 20:29:15 ===========#
//# Problem Title : 유레카 이론 =================#
//# Language : C++98 ===========================#

#include <iostream>
using namespace std;
int main(){
        int T;
        cin >> T;
        int a[51];
        for(int i=0; i<51; i++)
                a[i]=i*(i+1)/2;

        for(int test=0; test<T; test++)
        {
                bool possible = 0;
                int n;
                cin>>n;

                for(int i=50; i>=1; i--)
                        if( n - a[i] >= 0)
                                for(int j=i; j>=1; j--)
                                        if( n - a[i] - a[j] >= 0)
                                                for(int k=j; k>=1; k--)
                                                        if( n- a[i] - a[j] - a[k] == 0)
                                                                possible=1;
                cout<<possible<<endl;
        }
        return 0;
}