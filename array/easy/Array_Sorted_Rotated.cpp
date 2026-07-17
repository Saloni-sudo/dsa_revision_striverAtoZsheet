//->Check if Array Is Sorted and Rotated
//Given an array nums, return true if the array was originally sorted in non-decreasing order, 
//then rotated some number of positions (including zero). Otherwise,
// return false.

//There may be duplicates in the original array.

//Note: An array A rotated by x positions results in
// an array B of the same length such that B[i] == A[(i+x) % A.length]
// for every valid index i.


#include<iostream>
#include<vector>
using namespace std;

bool check(vector<int> &arr){
 int cnt=0;
 for(int i=0;i<arr.size();i++){
    if(arr[i]>arr[(i+1)%arr.size()]) cnt++;
 }
 return cnt<=1;
}
   
int main(){
   int n;
     cin>>n;
     vector<int> arr(n);
     for(int &x:arr){
        cin>>x;
     } 
     cout<<boolalpha<<check(arr);
 return 0;
}