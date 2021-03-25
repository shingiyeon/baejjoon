//# Author : nuclear852 ========================#
//# Solution : 5022126 =========================#
//# Time Stamp : 2017-01-15 11:51:04 ===========#
//# Problem Title : 뒤집힌 덧셈 =================#
//# Language : C++98 ===========================#

#include <iostream>
#include <string.h>
using namespace std;
using std::string;
int main(){
        int a, b, alen, blen, ansrev=0, ans=0;
        cin>>a>>b;
        for(alen=1; a/alen > 0; alen=alen*10);
        for(blen=1; b/blen > 0; blen=blen*10);
        alen=alen/10; blen=blen/10;
        for(int i=alen; i>=1; i=i/10)
        {       ansrev+= (int)(a/i)*(alen/i); a=a%i;}
        for(int i=blen; i>=1; i=i/10)
        {       ansrev+= (int)(b/i)*(blen/i); b=b%i;}
        for(alen=1; ansrev/alen > 0; alen=alen*10);
        alen=alen/10;
        for(int i=alen; i>=1; i=i/10)
        {       ans += (int)(ansrev/i)*(alen/i); ansrev=ansrev%i;}
        cout<<ans<<endl;
}