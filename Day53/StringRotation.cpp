#include<iostream>
#include<string>
using namespace std;

void ifSubstring(string s1,string s2)
{
    string s3="";
    s3+=s1+s1;
    int n=s2.size();
    int flag=0;
    for(int i=0;i<s3.size()-n+1;i++){
        string newStr=s3.substr(i,n);
        if(newStr==s2){
            cout<<"T\n";
            flag=1;
            break;
        }
    }
    if(flag==0)
        cout<<"F\n";
}

int main(){
    string s1;
    string s2;
    cout<<"S1: ";
    getline(cin, s1);
    cout<<"S2: ";
    getline(cin, s2);
    ifSubstring(s1,s2);
    return 0;
}
