//# Author : nuclear852 ========================#
//# Solution : 2175359 =========================#
//# Time Stamp : 2016-03-08 21:50:11 ===========#
//# Problem Title : 스택 =====================#
//# Language : C++98 ===========================#

#include <iostream>
#include <stack>
#include <string>
using namespace std;
using std::string;
int main(void){
        int N;
        stack<int> s;
        cin>>N;
        char c[20];
        while(N--)
        {
                cin>>c;

                if( c[0] == 'p')
                {
                        if( c[1] == 'u')
                        {
                                int n;
                                cin>>n;
                                s.push(n);
                        }
                        if( c[1] == 'o')
                        {
                                if(s.size() == 0)
                                        cout<<"-1"<<endl;
                                else{
                                cout<<s.top()<<endl;
                                s.pop();
                                }
                        }
                }

                if( c[0] == 's')
                {
                        cout<<s.size()<<endl;
                }

                if( c[0] == 'e')
                {
                        cout<<s.empty()<<endl;
                }

                if( c[0] == 't')
                {
                        if(s.size() == 0)
                                cout<<"-1"<<endl;
                        else{
                                cout<<s.top()<<endl;
                        }
                }
        }
}