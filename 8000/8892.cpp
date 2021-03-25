//# Author : nuclear852 ========================#
//# Solution : 2994645 =========================#
//# Time Stamp : 2016-05-26 15:10:12 ===========#
//# Problem Title : 팰린드롬 ===================#
//# Language : C++98 ===========================#

#include <iostream>
#include <string.h>

using namespace std;
using std::string;

int main(void){
        int test;
        cin>>test;

        while(test--)
        {
                int k;
                cin>>k;

                char word[100][10001];

                for(int i = 0; i<k; i++)
                        cin>>word[i];

                bool isokay = 0;
                char temp[20001];

                for(int i=0; i<k; i++)
                {
                        for(int j=0; j<k; j++)
                        {
                            if(i!=j){
                                char temp1[20001];
                                strcpy(temp1, word[i]);
                                strcat(temp1, word[j]);
                                bool iscan=1;
                                int length = strlen(temp1);
                                for(int i=0; i<length/2; i++)
                                {
                                        if(temp1[i] != temp1[ length-1-i])
                                                iscan=0;
                                }
                                if(iscan == 1)
                                {
                                        strcpy(temp, temp1);
                                        isokay = 1;
                                        break;
                                }
                            }
                        }
                }

                if(isokay==0)
                        cout<<"0"<<endl;
                else
                        cout<<temp<<endl;
        }
        return 0;
}