/*A phrase is a palindrome if, 
after converting all uppercase letters into 
lowercase letters and removing all non-alphanumeric characters, 
it reads the same forward and backward.
 Alphanumeric characters include letters and numbers.

Given a string s, return true if it is a palindrome, or false otherwise.*/


//time complexity=
//space complexity=


#include<iostream>
#include<algorithm>
#include<string>
#include<cctype>
using namespace std;
bool palindrome_or_not(string s,int start,int end){
 if(start>=end) return true;
 if(!isalnum(s[start])){
     return palindrome_or_not(s,start+1,end);
 }
 if(!isalnum(s[end])){
    return  palindrome_or_not(s,start,end-1);
 } 
 if(tolower(s[start])==tolower(s[end])){
    return  palindrome_or_not(s,start+1,end-1);
 }
 return false;

}

int main(){
 string s;
 getline(cin,s); 
 int start=0;
 int end=s.size()-1;
 cout<<boolalpha<<(palindrome_or_not(s,0,end));
 return 0;
}