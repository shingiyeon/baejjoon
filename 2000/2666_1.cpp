//# Author : nuclear852 ========================#
//# Solution : 4923338 =========================#
//# Time Stamp : 2017-01-03 14:22:20 ===========#
//# Problem Title : 벽장문의 이동 ================#
//# Language : C++98 ===========================#

#include <iostream>
#include <stdlib.h>
#include <math.h>
using namespace std;
int order[20];
int len;

int min(int a, int b)
{
        if(a<b)
                return a;
        else
                return b;
}

int dy(int find, int n1, int n2)
{
        if(find == len)
                return 0;
        else
        {
                int temp1 = abs(n1-order[find]);
                int temp2 = abs(n2-order[find]);

                return min( dy(find+1,order[find],n2)+temp1, dy(find+1,n1,order[find])+temp2);
        }
}

int main()
{
        int N;
        cin >>N;
        int num1, num2;
//      int len;
//      int arr[21][21][21];
//      int order[20];
        int sum = 0;

        cin>>num1>>num2>>len;

        for(int i=0; i<len; i++)
                cin>>order[i];


        cout<<dy(0,num1,num2)<<endl;
}