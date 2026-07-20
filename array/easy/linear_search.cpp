//Problem Statement: Given an array, and an element num the task is to find 
//if num is present in the given array or not.
//If present print the index of the element or print -1.


//time complexity=O(n)
//space complexity=O(1)



#include<iostream>
#include<vector>
#include<cctype>
using namespace std;

int main(){

    int n,target;
    cin>>n>>target;
   vector<int> arr(n);
    for(int &x:arr){
        cin>>x;
    }
    int found=-1;
   for(int i=0;i<arr.size();i++){
        if(arr[i]==target){
           found=1;
          
        } }
        if(found==1) cout<<boolalpha<<true; 
        else cout<<boolalpha<<false; 
    
     return 0;
}