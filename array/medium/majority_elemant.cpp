/*Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times. 


You may assume that the majority element always exists in the array.
*/


#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
 int n;
 cin>>n;
 vector<int>arr(n);
 for(int &x:arr){
    cin>>x;
 }
 int count=0;
 int candidate;
 for(int i=0;i<n;i++){
  if(count==0){
    candidate=arr[i];
  }
  if(candidate==arr[i]) count++;
  else{
    count--;
  }

 }
 cout<<candidate<<endl;
  return 0;
}
