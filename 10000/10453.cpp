//# Author : nuclear852 ========================#
//# Solution : 1800458 =========================#
//# Time Stamp : 2016-02-19 11:11:25 ===========#
//# Problem Title : 문자열 변환 =================#
//# Language : C++98 ===========================#

#include <iostream>
#include <cstring>
using namespace std;
int main(){
        int T;
        cin >> T;
        for(int test=0;test<T; test++)
        {
                char a[100001];
                cin>>a;
                int n = strlen(a);
                char b[100001];
                cin>>b;
                int m = strlen(b);

                if(n!=m){
                        cout<<"-1"<<endl;
                }

                else {
                        int a1=0;
                        int b1=0;
                        int a2=0;
                        int b2=0;

                        for(int i=0; i<n; i++){
                                if(a[i] == 'a')
                                        a1++;
                                else
                                        b1++;
                                if(b[i] == 'a')
                                        a2++;
                                else
                                        b2++;
                        }

                        if(a1 != a2 || b1 != b2)
                                cout<<"-1"<<endl;
                        else
                        {
                                int ans=0;
                                while( strcmp(a,b) != 0)
                                {
                                        for(int i=0; i<n-1; i++)
                                        {
                                                if( a[i] != b[i])
                                                {
                                                        for(int j=i; j<n; j++)
                                                        {
                                                                if(a[j] == b[i])
                                                                {
                                                                        char c= a[j];
                                                                        a[j]= a[i];
                                                                        a[i] = c;
                                                                        ans=ans+j-i;
                        
                                                                        break;
                                                                }
                                                        }
                                                }
                                        }
                                }
                                cout<<ans<<endl;
                        }

                }
        }
}