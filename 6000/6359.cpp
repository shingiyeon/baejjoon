//# Author : nuclear852 ========================#
//# Solution : 4943138 =========================#
//# Time Stamp : 2017-01-05 15:45:00 ===========#
//# Problem Title : 만취한 상범 =================#
//# Language : C++98 ===========================#

#include <iostream>
using namespace std;
int main(){
        int T;
        int dy[101];
        int k[101];
        for(int i=1; i<=100; i++)
        {
                int temp = 0;
                for(int j=i; j>=1; j--)
                {
                        if(i%j == 0)
                                temp++;
                }
                dy[i] = temp;
        }

        k[1] = 1;
        for(int i=2; i<=100; i++)
        {
                if(dy[i] % 2)
                        k[i] = k[i-1] + 1;
                else
                        k[i] = k[i-1];
        }

        cin>>T;
        while(T--)
        {
                int num;
                cin>>num;
                cout<<k[num]<<endl;
        }
}