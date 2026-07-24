/*
Given an integer array nums,
find the subarray with the largest sum, 
and return its sum.
*/





#include<iostream>
#include<vector>
#include<cctype>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int &x:arr){
        cin>>x;
    }
   int currsum=0;
     int bestend;
     int beststart;
     int maxi=INT_MIN;
     int currstart;
    for(int right=0;right<n;right++){ 
        if(currsum==0) currstart=right;
         currsum+=arr[right];
         if(currsum>maxi){
            maxi=max(maxi,currsum);
            bestend=right;
            beststart=currstart;
        }
        if(currsum<0){
            currsum=0;
        }
  }
 cout<<maxi<<endl;
 for(int i=beststart;i<bestend+1;i++){
    cout<<arr[i]<<" ";
 }
return 0;
}