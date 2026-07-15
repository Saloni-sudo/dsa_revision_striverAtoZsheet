#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

class solution{
    public:
    string temp;
      bool palindrome(int x){
        string temp=to_string(x);
        reverse(temp.begin(),temp.end());
        if(temp==to_string(x)){
            return true;
        }
        else return false;

    }


};
 int main(){
    solution s;
    int x;
    cin>>x;
    cout << boolalpha<< s.palindrome(x) <<endl;
    return 0;
 }