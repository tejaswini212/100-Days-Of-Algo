#include<iostream>
#include<string>
using namespace std;
 
int main(){
  long long a;
  cin>>a;
  for(int i=1;;i++){
  	if(stoll(to_string(i)+to_string(i))>a){
      cout<<i-1;
      return 0;
    }
  }
}