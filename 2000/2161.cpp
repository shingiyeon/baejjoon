//# Author : nuclear852 ========================#
//# Solution : 1765883 =========================#
//# Time Stamp : 2016-02-17 20:28:38 ===========#
//# Problem Title : 카드1 ====================#
//# Language : C++98 ===========================#

#include <iostream>
using namespace std;
int main()
{
        int N;
        int s=0;
        int arr[2000];
        cin >> N;
        int e= N-1;
        for(int i=0; i<N; i++)
                arr[i] = i+1;
        while( s != e)
        {
                cout<<arr[s]<<" ";
                s++;
                e++;
                arr[e] = arr[s];
                s++;
        }
        cout<<arr[s]<<endl;
        return 0;
}