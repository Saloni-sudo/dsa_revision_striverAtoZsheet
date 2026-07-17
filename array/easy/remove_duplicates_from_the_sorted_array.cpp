//Remove Duplicates from Sorted Array
//Given an integer array nums sorted in non-decreasing order,
// remove the duplicates in-place such that each unique element appears only once. 
// The relative order of the elements should be kept the same.

//Consider the number of unique elements in nums to be k​​​​​​​​​​​​​​. 
//After removing duplicates, return the number of unique elements k.

//The first k elements of nums should contain the unique numbers in sorted order.
// The remaining elements beyond index k - 1 can be ignored.

//time complexity=O(n)
//space complexity=O(1)

#include<iostream>
#include<vector>
using namespace std;

int main(){
 int n;
 cin>>n;
 vector<int> arr(n);
 for(int &x: arr){
    cin>>x;
 }
 int i=0;
 for(int j=1;j<n;j++){
    if(arr[j]!=arr[i]){
     i++;
     arr[i]=arr[j];
    }
 } cout << i+1;


    return 0;
}