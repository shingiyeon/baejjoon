//# Author : nuclear852 ========================#
//# Solution : 5160033 =========================#
//# Time Stamp : 2017-02-04 17:36:04 ===========#
//# Problem Title : 피보나치 수의 확장 =============#
//# Language : C++98 ===========================#

#include <iostream>
using namespace std;
int main(){
        long long a=0,b=1,c=0;
        int n; cin>>n;
        if(n>=0){
                if(n==0) cout<<"0\n0";
                else if(n==1) cout<<"1\n1";
                else{
                        while(n-1){
                                c = (a+b)%1000000000;
                                a = b;
                                b = c;
                                n--;
                        }
                        cout<<"1\n"<<c;
                }
        }
        else{
                int pos;
                while(n){
                        if(b-a>=0) pos = 1;
                        else pos = -1;
                        c = (b - a)%1000000000;
                        b = a;
                        a = c;
                        n++;
                }
                cout<<pos<<"\n";
                pos == 1 ? cout<<c : cout<<-c;
        }
}