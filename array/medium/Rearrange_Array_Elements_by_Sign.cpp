/*
You are given a 0-indexed integer array nums
of even length consisting of an equal number of positive and negative integers.

You should return the array of nums such that the 
array follows the given conditions:

Every consecutive pair of integers have opposite signs.
For all integers with the same sign, the order in which
 they were present in nums is preserved.
The rearranged array begins with a positive integer.
Return the modified array after rearranging the elements 
to satisfy the aforementioned conditions.


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
  int even_index=0;
  int odd_index=1;
  vector<int>ans(n);
  for(int i=0;i<arr.size();i++){
     if (arr[i]>0)
     {
       ans[even_index]=arr[i];
       even_index+=2;  
    }
    else{
        ans[odd_index]=arr[i];
       odd_index+=2;
    }
    }
    for(int &x:ans){
        cout<<x<<" ";
    }

    return 0;
}