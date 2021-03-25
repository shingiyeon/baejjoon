//# Author : nuclear852 ========================#
//# Solution : 2897230 =========================#
//# Time Stamp : 2016-05-05 23:41:33 ===========#
//# Problem Title : 괄호 =====================#
//# Language : C++98 ===========================#

#include <iostream>
#include <cstring>
using std::string;
using namespace std;
int main(void)
{
        int n;
        cin>>n;
        while(n--)
        {
                string a;
                cin>>a;
                int sum = 0;
                int i=0;
                bool ans = 1;
                while( a[i] != '\0' )
                {
                        if(a[i] == '(')
                                sum++;
                        else
                                sum--;
                        if(sum < 0)
                                ans = 0;
                        i++;
                }

                if(ans == 0 || sum > 0)
                        cout<<"NO"<<endl;
                else
                        cout<<"YES"<<endl;
        }
}