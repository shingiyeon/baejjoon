//# Author : nuclear852 ========================#
//# Solution : 2924681 =========================#
//# Time Stamp : 2016-05-11 23:37:07 ===========#
//# Problem Title : 순서 =====================#
//# Language : C++98 ===========================#

#include <iostream>
using namespace std;
int main(void){
        int n;
        cin>>n;
        while(n--)
        {
                bool array[101];
                for(int i=1; i<=100; i++)
                        array[i]=0;
                int n;
                cin>>n;
                int arr[100];
                for(int i=0; i<n; i++)
                        cin>>arr[i];

                int ans[100];
                bool imp = 0;
                for(int i=n-1; i>=0; i--)
                {
                        int movement = 0;
                        int k = 1;

                        while(movement != arr[i] || array[k] == 1)
                        {
                                if(array[k]==1)
                                        k++;
                                else{
                                        movement++;
                                        k++;
                                }

                                if(k>n)
                                {
                                        imp = 1;
                                        break;
                                }

                        }
                        if(imp==1)
                                break;

                        ans[i] = k;
                        array[k] = 1;
                }
                if(imp == 0){
                        for(int i=0; i<n; i++)
                                cout<<ans[i]<<" ";
                }

                else{
                        cout<<"IMPOSSIBLE";
                }
                cout<<endl;
        }
}