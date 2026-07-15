//->reverse a number
//->t.c=O(n) and s.c=O(1 )


#include<iostream>
#include<algorithm>
using namespace std;


int reverse(int n){
    int rev=0;
    while(n>0){
        int digit=0;
        digit=n%10;
        if(rev>INT_MAX/10 ||rev<INT_MIN/10){//->logic to checknif the answer did not overflow or underflow
            return 0;
           
        }
        rev=rev*10+digit;//->to add in the answer
        n=n/10;//->to short the number

     }
     return rev;

}

int main(){
  int n;
  cin>>n;
  cout<<reverse(n);
    return 0;

}