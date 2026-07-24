/*
Given an array nums with n objects colored red, white, 
or blue, sort them in-place so that objects of the same color are adjacent,
 with the colors in the order red, white, and blue.

We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

You must solve this problem without using the library's sort function.
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std; 

int main(){
 int n;
 cin>>n;
 vector<int> arr(n);
 for(int &x:arr){
    cin>>x;
 }
 int red=0;
 int white=0;
 int blue=0;
 for(int i=0;i<n;i++){
    if(arr[i]==0) red++;
    if(arr[i]==1) white++;
    if(arr[i]==2) blue++;
 }
 int index=0;
 for(int i=0;i<red;i++){
    arr[index++]=0;
 }
 for(int i=0;i<white;i++){
  arr[index++]=1;
 }
 for(int i=0;i<blue;i++){
    arr[index++]=2;
}
for(int &x:arr){
    cout<<x<<endl;
}

return 0;
}