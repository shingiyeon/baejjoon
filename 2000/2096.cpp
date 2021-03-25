//# Author : nuclear852 ========================#
//# Solution : 1699205 =========================#
//# Time Stamp : 2016-02-14 23:21:32 ===========#
//# Problem Title : 내려가기 ===================#
//# Language : C++98 ===========================#

#include <iostream>
using namespace std;
int max(int a, int b)
{
        if(a>b)
                return a;
        else
                return b;
}
int min(int a, int b)
{
        if(a<b)
                return a;
        else
                return b;
}
int main(void)
{
        int N;
        cin>>N;
        int tempmax[3];
        int tempmin[3];
        int dymax[3];
        int dymin[3];
        int arr[3];
        for(int i=0; i<3; i++)
        {
                dymax[i]=0;
                dymin[i]=0;
        }
        for(int i=0; i<N; i++)
        {
                for(int j=0; j<3; j++)
                        cin>>arr[j];

                tempmax[0] = max( dymax[0], dymax[1]) + arr[0];
                tempmax[1] = max( dymax[0], max(dymax[1], dymax[2])) + arr[1];
                tempmax[2] = max( dymax[1], dymax[2]) + arr[2];
                dymax[0] = tempmax[0];
                dymax[1] = tempmax[1];
                dymax[2] = tempmax[2];
                tempmin[0] = min( dymin[0], dymin[1]) + arr[0];
                tempmin[1] = min( dymin[0], min(dymin[1], dymin[2])) + arr[1];
                tempmin[2] = min( dymin[1], dymin[2]) + arr[2];
                dymin[0] = tempmin[0];
                dymin[1] = tempmin[1];
                dymin[2] = tempmin[2];
        }

        cout<< max( dymax[0], max(dymax[1], dymax[2])) <<" "<< min( dymin[0], min(dymin[1], dymin[2]))<<endl;
        return 0;
}