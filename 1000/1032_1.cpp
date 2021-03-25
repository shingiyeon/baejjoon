//# Author : nuclear852 ========================#
//# Solution : 1399594 =========================#
//# Time Stamp : 2016-01-27 20:45:31 ===========#
//# Problem Title : 명령 프롬프트 ================#
//# Language : C++98 ===========================#

#include <iostream>
using namespace std;

int main(void){
        int n;
        cin >> n;
        char file[n][51];
        for(int i=0; i<n; i++)
        {
                cin>>file[i];
        }
        int tmp = 0;
        while( file[0][tmp] != '\0')
        {
                tmp++;
        }
        
        char ans[tmp];

        for(int i=0; i<tmp; i++)
                ans[i]= file[0][i];
        for(int i=0; i<tmp; i++)
        {
                for(int j=1; j<n; j++)
                {
                        if( ans[i] != file[j][i])
                                ans[i] = '?';
                }
        }
        for(int i=0; i<tmp; i++)
        {
                cout<<ans[i];
        }
        cout<<endl;
        return 0;
}