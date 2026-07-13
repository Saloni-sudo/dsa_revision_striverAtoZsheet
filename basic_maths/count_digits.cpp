//count all digits of a number


#include<iostream>
#include<algorithm>
#include <string>
using namespace std;

int count_digits(int s){
    int count=0;
    while(s>0){
        s=s/10;
        count++;
     }
 return count;
}
int main(){
 cout<<"enter the number"<<endl;
 long long s;
 cin>>s;
 int k=count_digits(s);
  cout<<k<<endl;
   return 0;
}