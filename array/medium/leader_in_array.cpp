/*
Given an integer array nums,
return a list of all the leaders in the array.

A leader in an array is an element whose value 
is strictly greater than all elements to its right 
in the given array. 
The rightmost element is always a leader. 
The elements in the leader array must appear in 
the order they appear in the nums array.

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
  vector<int>ans;
  int maxi=arr[n-1];
  ans.push_back(maxi);
 for(int i=n-2;i>=0;i--){
    if(arr[i]>maxi){
        maxi=arr[i];
        ans.push_back(maxi);
    }
 }
 reverse(ans.begin(),ans.end());
 for(int & x:ans){
    cout<<x<<" ";
 }
return 0;
 }
