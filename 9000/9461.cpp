//# Author : nuclear852 ========================#
//# Solution : 1365673 =========================#
//# Time Stamp : 2016-01-23 20:31:31 ===========#
//# Problem Title : 파도반 수열 =================#
//# Language : C++98 ===========================#

#include <iostream>
using namespace std;
int main()
{

        long long array[101];

        int T;

        int N;


        cin>>T;

        array[1]=1;
        array[2]=1;
        array[3]=1;

        for(int i=4; i<101; i++)
        {
                array[i]=array[i-3]+array[i-2];
        }


        for(int i=0; i<T; i++)
        {
                cin>>N;

                cout<<array[N]<<endl;
        }


        return 0;
}